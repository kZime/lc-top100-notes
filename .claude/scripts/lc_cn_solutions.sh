#!/usr/bin/env bash
# Usage: lc_cn_solutions.sh <slug>
# Output: plain text of top 3 CN solutions, max 3000 chars

SLUG=${1-}
GRAPHQL_URL='https://leetcode.cn/graphql/'

log() {
  printf 'lc_cn_solutions: %s\n' "$*" >&2
}

fail() {
  log "$1"
  echo "FETCH_FAILED"
  exit 1
}

escape_json_string() {
  local value=$1
  value=${value//\\/\\\\}
  value=${value//\"/\\\"}
  printf '%s' "$value"
}

fetch_json() {
  local slug payload
  slug=$(escape_json_string "$1")
  payload=$(printf '{"query":"query{questionSolutionArticles(questionSlug:\\"%s\\",first:5,orderBy:HOT){edges{node{title upvoteCount content}}}}"}' "$slug")

  curl -sS -X POST "$GRAPHQL_URL" \
    -H 'Content-Type: application/json' \
    -H 'User-Agent: Mozilla/5.0' \
    --data "$payload"
}

parse_with_jq() {
  local json=$1
  local result

  if ! printf '%s' "$json" | jq -e '.errors | not' >/dev/null; then
    log 'graphql returned errors'
    return 1
  fi

  if ! printf '%s' "$json" | jq -e '.data.questionSolutionArticles.edges | type == "array" and length > 0' >/dev/null; then
    log 'graphql returned no solution articles'
    return 1
  fi

  if ! result=$(printf '%s' "$json" | jq -r '
      .data.questionSolutionArticles.edges[:3][].node |
      "### \(.title) (\(.upvoteCount)👍)\n" +
      (
        .content
        | gsub("<br\\s*/?>"; "\n")
        | gsub("</p>"; "\n\n")
        | gsub("<[^>]+>"; "")
        | gsub("&lt;"; "<")
        | gsub("&gt;"; ">")
        | gsub("&amp;"; "&")
        | gsub("&quot;"; "\"")
        | gsub("&#39;"; "'\''")
        | gsub("&nbsp;"; " ")
        | .[0:900]
      )
    '); then
    log 'jq failed to parse graphql response'
    return 1
  fi

  if [ -z "$result" ]; then
    log 'jq produced empty output'
    return 1
  fi

  printf '%s' "$result"
}

parse_with_perl() {
  local json=$1

  printf '%s' "$json" | perl -MJSON::PP -e '
    use strict;
    use warnings;
    use utf8;

    local $/;
    my $raw = <STDIN>;
    my $data;

    eval { $data = decode_json($raw); 1 } or do {
      print STDERR "lc_cn_solutions: perl failed to decode graphql response\n";
      exit 1;
    };

    if (exists $data->{errors} && ref($data->{errors}) eq "ARRAY" && @{$data->{errors}}) {
      print STDERR "lc_cn_solutions: graphql returned errors\n";
      exit 1;
    }

    my $edges = $data->{data}{questionSolutionArticles}{edges};
    if (ref($edges) ne "ARRAY" || !@$edges) {
      print STDERR "lc_cn_solutions: graphql returned no solution articles\n";
      exit 1;
    }

    my @chunks;
    for my $edge (@$edges[0 .. ($#$edges < 2 ? $#$edges : 2)]) {
      my $node = ref($edge) eq "HASH" ? $edge->{node} : undef;
      next unless ref($node) eq "HASH";

      my $title = defined $node->{title} ? $node->{title} : "";
      my $upvote = defined $node->{upvoteCount} ? $node->{upvoteCount} : 0;
      my $content = defined $node->{content} ? $node->{content} : "";

      $content =~ s/<br\s*\/?>/\n/gi;
      $content =~ s/<\/p>/\n\n/gi;
      $content =~ s/<[^>]+>//g;
      $content =~ s/&lt;/</g;
      $content =~ s/&gt;/>/g;
      $content =~ s/&amp;/&/g;
      $content =~ s/&quot;/"/g;
      $content =~ s/&#39;/'\''/g;
      $content =~ s/&nbsp;/ /g;

      push @chunks, sprintf("### %s (%s👍)\n%s", $title, $upvote, substr($content, 0, 900));
    }

    if (!@chunks) {
      print STDERR "lc_cn_solutions: perl produced empty output\n";
      exit 1;
    }

    binmode STDOUT, ":utf8";
    print join("\n", @chunks);
  '
}

main() {
  local json result

  if [ -z "$SLUG" ]; then
    fail 'missing slug argument'
  fi

  if ! command -v curl >/dev/null 2>&1; then
    fail 'curl is required'
  fi

  if ! json=$(fetch_json "$SLUG"); then
    fail 'network request failed'
  fi

  if command -v jq >/dev/null 2>&1; then
    if ! result=$(parse_with_jq "$json"); then
      fail 'jq parser failed'
    fi
  else
    log 'jq missing, falling back to perl'
    if ! command -v perl >/dev/null 2>&1; then
      fail 'perl is required for fallback parsing'
    fi
    if ! perl -MJSON::PP -e 1 >/dev/null 2>&1; then
      fail 'perl JSON::PP is required for fallback parsing'
    fi
    if ! result=$(parse_with_perl "$json"); then
      fail 'perl parser failed'
    fi
  fi

  if [ -z "$result" ]; then
    fail 'parser returned empty output'
  fi

  printf '%s' "$result" | head -c 3000
}

main "$@"
