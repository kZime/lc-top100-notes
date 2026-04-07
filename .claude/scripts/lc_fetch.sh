#!/usr/bin/env bash
# Usage: lc_fetch.sh <slug>
# Output: JSON {id, title, difficulty, content (plain text), metaData}
set -e
SLUG=$1
QUERY='{"query":"query questionData($titleSlug: String!) { question(titleSlug: $titleSlug) { questionId title difficulty content exampleTestcases metaData } }","variables":{"titleSlug":"'"$SLUG"'"}}'
HEADERS=(-H 'Content-Type: application/json' -H 'User-Agent: Mozilla/5.0' -H 'x-csrftoken: lc' -H 'Cookie: csrftoken=lc')

strip() {
  jq '{
    id: .data.question.questionId,
    title: .data.question.title,
    difficulty: .data.question.difficulty,
    metaData: .data.question.metaData,
    content: (.data.question.content
      | gsub("<[^>]+>"; "")
      | gsub("&lt;"; "<") | gsub("&gt;"; ">")
      | gsub("&amp;"; "&") | gsub("&quot;"; "\"")
      | gsub("&#39;"; "'") | gsub("&nbsp;"; " "))
  }'
}

for url in 'https://leetcode.com/graphql' 'https://leetcode.cn/graphql/'; do
  resp=$(curl -s -X POST "$url" "${HEADERS[@]}" --data "$QUERY")
  if echo "$resp" | jq -e '.data.question.questionId' > /dev/null 2>&1; then
    echo "$resp" | strip
    exit 0
  fi
done

echo '{"error":"API unavailable"}' >&2
exit 1