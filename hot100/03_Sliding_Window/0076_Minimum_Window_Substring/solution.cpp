#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tCnt;
        for (auto &c : t) {
            tCnt[c]++;
        }
        auto check = [&] (const unordered_map<char, int> &cnt) {
            for (auto &[k, v] : cnt) {
                if (v > 0) return false;
            }
            return true;
        };

        int l = 0, r = 0;
        int n = s.size();

        // move r to legal
        while (r < n && !check(tCnt)) {
            tCnt[s[r]]--;
            r++; // add s[r] in it
        }

        if (r == n && !check(tCnt)) return ""; // Not Found

        // move l
        while (l < n && tCnt[s[l]] + 1 <= 0) {
            tCnt[s[l]]++;
            l++;
        }
        int ans = r-l;
        int ansl = l;
        int ansr = r;

        while (r < n) {
            // add r
            tCnt[s[r]]--;
            r++;

            // move l
            while (l < n && tCnt[s[l]] + 1 <= 0) {
                tCnt[s[l]]++;
                l++;
            }
            if (r - l < ans) {
                ans = r-l;
                ansl = l;
                ansr = r;
            }

        }
        return s.substr(ansl, ansr - ansl);

    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

auto toString = [](string v) { return "\"" + v + "\""; };
auto eq       = [](string a, string b) { return a == b; };

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](string got, string want, const string& label) {
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
    check(sol.minWindow("ADOBECODEBANC", "ABC"), "BANC", "example1: ADOBECODEBANC/ABC");
    check(sol.minWindow("a",              "a"),  "a",    "example2: a/a");
    check(sol.minWindow("a",              "aa"), "",     "example3: a/aa");
    check(sol.minWindow("b",              "b"),  "b",    "edge: single match");
    check(sol.minWindow("abc",            "cba"), "abc", "edge: full string");
    check(sol.minWindow("xyzabc",         "abc"), "abc", "edge: suffix match");
    check(sol.minWindow("AA",             "AA"), "AA",   "edge: duplicate required chars");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
