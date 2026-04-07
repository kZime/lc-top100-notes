#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int climbStairs(int n) {
        array<int, 3> dp{};
        dp[0] = 1; // 1 way to climb 0 steps
        for (int i = 1; i <= n; i++)
            dp[i%3] = dp[(i-1 + 3)%3] + dp[(i-2 + 3)%3];
        return dp[n%3];
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

string toString(int v) { return to_string(v); }
bool eq(int a, int b) { return a == b; }

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](int n, int want, const string& label) {
        total++;
        int got = sol.climbStairs(n);
        if (eq(got, want)) {
            printf(GRN "✓" RST "  %-36s →  %s\n", label.c_str(), toString(got).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(got).c_str());
        }
    };

    // Examples
    check(2, 2,  "n=2");
    check(3, 3,  "n=3");

    // Edge cases
    check(1, 1,  "n=1 (base)");
    check(4, 5,  "n=4");
    check(5, 8,  "n=5");
    check(10, 89, "n=10");
    check(45, 1836311903, "n=45 (max)");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
