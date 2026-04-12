#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    string decodeString(string s) {
        // TODO: implement
        return {};
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

bool eq(const string& a, const string& b) { return a == b; }
string toString(const string& s) { return "\"" + s + "\""; }

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

    // Examples
    check(sol.decodeString("3[a]2[bc]"),    "aaabcbc",        "3[a]2[bc]");
    check(sol.decodeString("3[a2[c]]"),     "accaccacc",      "3[a2[c]]");
    check(sol.decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef", "2[abc]3[cd]ef");
    // Edge cases
    check(sol.decodeString("a"),            "a",              "no encoding");
    check(sol.decodeString("2[a]"),         "aa",             "2[a]");
    check(sol.decodeString("10[a]"),        "aaaaaaaaaa",     "10[a] multi-digit k");
    check(sol.decodeString("2[a3[b]]"),     "abbbabbb",       "2[a3[b]] nested");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
