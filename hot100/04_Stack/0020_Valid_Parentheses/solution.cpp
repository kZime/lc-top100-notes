#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        const string left = "([{", right = ")]}";
        for (auto &c : s) {
            auto iL = left.find(c);
            auto rL = right.find(c);

            if (iL != string::npos) {
                stk.push(c);
            }
            if (rL != string::npos) {
                if (!stk.empty() && left.find(stk.top()) == rL) {
                    // match
                    stk.pop();
                }
                else {
                    // not match
                    return false;
                }
            }

        }
        return stk.empty();
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

bool eq(bool a, bool b) { return a == b; }
string toString(bool b) { return b ? "true" : "false"; }

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](bool got, bool want, const string& label) {
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
    check(sol.isValid("()"),     true,  "\"()\"");
    check(sol.isValid("()[]{}"), true,  "\"()[]{}\"");
    check(sol.isValid("(]"),     false, "\"(]\"");
    check(sol.isValid("([])"),   true,  "\"([])\"");
    check(sol.isValid("([)]"),   false, "\"([)]\"");
    // Edge cases
    check(sol.isValid("{[]}"),   true,  "\"{[]}\" nested");
    check(sol.isValid("("),      false, "\"(\" unclosed");
    check(sol.isValid(")"),      false, "\")\" extra close");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
