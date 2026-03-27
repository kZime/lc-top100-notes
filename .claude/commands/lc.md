Set up a LeetCode problem workspace. Argument: $ARGUMENTS (problem number, e.g. `128`, or URL slug, e.g. `longest-consecutive-sequence`).

## Step 1 — Resolve the slug

If $ARGUMENTS is a number, find the matching row in `README.md` by problem ID and extract the folder name to get the slug (e.g. `128` → `0128_Longest_Consecutive_Sequence` → slug `longest-consecutive-sequence`).
If $ARGUMENTS is already a slug, use it directly.

## Step 2 — Fetch problem data

Try the following sources in order, stopping at the first success:

> Note: `leetcode.cn/graphql/` does NOT support the `questionData` query (returns invalid JSON). Only `.com` is tried.

### 2a. LeetCode COM GraphQL

LeetCode requires a session cookie (CSRF protection). Use a two-step approach:

```bash
# Step 1: GET the problem page to establish a session cookie
curl -s -c /tmp/lc_cookies.txt \
  'https://leetcode.com/problems/SLUG/' \
  -H 'User-Agent: Mozilla/5.0' > /dev/null

# Step 2: POST GraphQL with the session cookie
curl -s -X POST 'https://leetcode.com/graphql' \
  -H 'Content-Type: application/json' \
  -H 'User-Agent: Mozilla/5.0' \
  -H 'Referer: https://leetcode.com/problems/SLUG/' \
  -b /tmp/lc_cookies.txt \
  --data '{"query":"query questionData($titleSlug: String!) { question(titleSlug: $titleSlug) { questionId title difficulty content exampleTestcases metaData } }","variables":{"titleSlug":"SLUG"}}'
```

### 2b. WebFetch（网络兜底）

Use the `WebFetch` tool on `https://leetcode.com/problems/SLUG/` and extract: description, examples, constraints, function signature.

### 2c. 内置知识（最终兜底）

If all network attempts fail, construct files from internal knowledge of the problem. **Tell the user clearly** that the API was unavailable and files were built from memory — they should verify the problem statement before starting.

---

From whichever source succeeds, extract: `questionId`, `title`, `difficulty`, `content` (HTML), `exampleTestcases`, `metaData` (JSON with function name and param/return types).

## Step 3 — Create the folder

Folder path: `<ID padded to 4 digits>_<Title_Words_Joined_By_Underscores>/`
Example: `0128_Longest_Consecutive_Sequence/`

If the folder already exists, inform the user and stop.

## Step 4 — Create `problem.md`

Strip HTML tags from `content`. Convert HTML entities (`&quot;` → `"`, `&lt;` → `<`, `&gt;` → `>`, `&amp;` → `&`, `&nbsp;` → ` `).

Template:
```
# <ID>. <Title>

**Difficulty:** <difficulty>
**Link:** https://leetcode.com/problems/<slug>/

---

## Description

<cleaned content — description paragraph only, before examples>

---

## Examples

<examples extracted from content>

---

## Constraints

<constraints extracted from content>
```

## Step 5 — Create `solution.cpp`

Use `metaData` to get the function name and parameter/return types. Map LeetCode types to C++:
- `integer` → `int`, `integer[]` → `vector<int>`, `string` → `string`, `string[]` → `vector<string>`
- `boolean` → `bool`, `list<list<integer>>` / `list<list<string>>` → nested vectors, `TreeNode*`, `ListNode*` as needed

Template structure:
```cpp
#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    <ReturnType> <functionName>(<params>) {
        // TODO: implement
        return {};
    }
};

// ─── Helpers ──────────────────────────────────────────────────────────────────

// Add toString() / eq() helpers as needed for the return type.
// For containers, sort a copy before comparing when order doesn't matter.

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    // check: call sol, compare got vs want, print result.
    // Output format:
    //   ✓  label                         →  <got>
    //   ✗  label                             want=<want>  got=<got>
    auto check = [&](<ReturnType> got, <ReturnType> want, const string& label) {
        total++;
        if (eq(got, want)) {
            printf(GRN "✓" RST "  %-36s →  %s\n", label.c_str(), toString(got).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(got).c_str());
        }
    };

    // Write at least 5 test cases:
    // - All examples from the problem statement
    // - At least 2 meaningful edge cases (empty input, single element, all same, boundary values, etc.)

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
```

Include `eq()` and `toString()` helpers when the return type is a container. Sort a copy before comparing when order doesn't matter.

## Step 6 — Create `solution.go`

Use `metaData` to get the function name and types. Map LeetCode types to Go:
- `integer` → `int`, `integer[]` → `[]int`, `string` → `string`, `string[]` → `[]string`
- `boolean` → `bool`, `list<list<integer>>` → `[][]int`, `list<list<string>>` → `[][]string`

Template structure:
```go
package main

import (
	"fmt"
	"sort"
)

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func <functionName>(<params>) <ReturnType> {
	// TODO: implement
	return <zeroValue>
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want <ReturnType>, label string) {
		total++
		// sort slices before comparing if order doesn't matter
		if <equal> {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// Same test cases as solution.cpp.
	_ = check
	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
```

Remove unused imports if `sort` is not needed.

## Step 7 — Update README.md

Find the row for this problem in `README.md`. The `Done` column should remain `☐` — the user marks it done after solving via `/lc-review`. No other changes needed.

---

## Notes

- For problems involving `TreeNode` or `ListNode`, add the standard struct definitions above the `Solution` class in `solution.cpp`, and equivalent struct definitions in `solution.go`.
- Use `g++ -std=c++17 solution.cpp -o sol && ./sol` to compile C++.
- Use `go run solution.go` to run Go.
