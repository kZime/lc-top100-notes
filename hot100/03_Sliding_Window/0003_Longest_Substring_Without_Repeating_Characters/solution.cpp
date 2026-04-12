#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> vis;
        int l = 0, r = 0;
        int n = s.size();
        int ans = 0;
        for (r = 0; r < n; r++) {
            if (!vis.count(s[r])) { // no s[r]
                vis.insert(s[r]);
            } else { // visited s[r]
                while (vis.count(s[r])) {
                    vis.erase(s[l]);
                    l++;
                }
                vis.insert(s[r]);
            }
            ans = max(ans, (int)vis.size());
        }
        return ans;
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

auto toString = [](int v) { return to_string(v); };
auto eq       = [](int a, int b) { return a == b; };

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](int got, int want, const string& label) {
        total++;
        if (eq(got, want)) {
            printf(GRN "✓" RST "  %-36s →  %s\n", label.c_str(), toString(got).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(got).c_str());
        }
    };

    // All problem examples + ≥2 edge cases
    check(sol.lengthOfLongestSubstring("abcabcbb"), 3, "example1: abcabcbb");
    check(sol.lengthOfLongestSubstring("bbbbb"),    1, "example2: bbbbb");
    check(sol.lengthOfLongestSubstring("pwwkew"),   3, "example3: pwwkew");
    check(sol.lengthOfLongestSubstring(""),          0, "edge: empty string");
    check(sol.lengthOfLongestSubstring("a"),         1, "edge: single char");
    check(sol.lengthOfLongestSubstring("abcde"),     5, "edge: all unique");
    check(sol.lengthOfLongestSubstring("dvdf"),      3, "edge: dvdf");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
