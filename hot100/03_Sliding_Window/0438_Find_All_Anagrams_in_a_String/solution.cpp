#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pCnt;
        for (auto &c : p)
            pCnt[c]++;

        int n = s.size(), k = p.size();

        int notFit = pCnt.size(); // char not fit
        for (int i = 0; i < k; i++) {
            pCnt[s[i]]--;
            if (pCnt[s[i]] == 0)
                notFit--;
        }

        vector<int> ans;
        if (notFit == 0) ans.push_back(0);
        for (int j = k; j < n; j++) {
            // pop j-k
            pCnt[s[j-k]]++;
            if (pCnt[s[j-k]] == 1) notFit++;

            // push j
            pCnt[s[j]]--;
            if (pCnt[s[j]] == 0) notFit--;

            if (notFit == 0)
                ans.push_back(j-k+1);

        }
        return ans;
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

auto toString = [](vector<int> v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) { if (i) s += ","; s += to_string(v[i]); }
    return s + "]";
};
auto eq = [](vector<int> a, vector<int> b) { return a == b; };

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> got, vector<int> want, const string& label) {
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
    check(sol.findAnagrams("cbaebabacd", "abc"), {0,6},     "example1: cbaebabacd/abc");
    check(sol.findAnagrams("abab",        "ab"),  {0,1,2},  "example2: abab/ab");
    check(sol.findAnagrams("a",           "ab"),  {},       "edge: s shorter than p");
    check(sol.findAnagrams("baa",          "aa"), {1},      "edge: baa/aa");
    check(sol.findAnagrams("aa",           "aa"), {0},      "edge: exact match");
    check(sol.findAnagrams("abcdef",      "xyz"), {},       "edge: no anagram");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
