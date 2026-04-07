#!/usr/bin/env bash
# Usage: lc_cn_solutions.sh <slug>
# Output: plain text of top 3 CN solutions, max 3000 chars
SLUG=$1

result=$(curl -s -X POST 'https://leetcode.cn/graphql/' \
  -H 'Content-Type: application/json' \
  -H 'User-Agent: Mozilla/5.0' \
  --data '{"query":"query{questionSolutionArticles(questionSlug:\"'"$SLUG"'\",first:5,orderBy:HOT){edges{node{title upvoteCount content}}}}"}' \
  | jq -r '.data.questionSolutionArticles.edges[:3][].node |
      "### \(.title) (\(.upvoteCount)👍)\n" +
      (.content
        | gsub("<[^>]+>"; "")
        | gsub("&lt;"; "<") | gsub("&gt;"; ">")
        | gsub("&amp;"; "&") | gsub("&quot;"; "\"")
        | gsub("&#39;"; "'\''") | gsub("&nbsp;"; " ")
        | .[0:900])
    ' 2>/dev/null)

if [ -z "$result" ]; then
  echo "FETCH_FAILED"
  exit 1
fi
printf '%s' "$result" | head -c 3000