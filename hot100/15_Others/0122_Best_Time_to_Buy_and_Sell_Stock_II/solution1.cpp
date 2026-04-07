#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:

    int maxProfit(vector<int>& price) {
        int n = price.size();
        vector<array<int, 2> > dp(n, {0, 0});
        dp[0][1] = -price[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i]); // stay / sell today
            dp[i][1] = max(dp[i-1][0] - price[i], dp[i-1][1]); // stay / buy today
        }
        return max(dp[n-1][0], dp[n-1][1]);

    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

string toString(int v) { return to_string(v); }
bool eq(int a, int b) { return a == b; }

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

    // Example 1: multiple transactions
    { vector<int> p = {7,1,5,3,6,4}; check(sol.maxProfit(p), 7, "ex1 [7,1,5,3,6,4]"); }
    // Example 2: ascending — one big trade
    { vector<int> p = {1,2,3,4,5};   check(sol.maxProfit(p), 4, "ex2 [1,2,3,4,5]"); }
    // Example 3: descending — no profit
    { vector<int> p = {7,6,4,3,1};   check(sol.maxProfit(p), 0, "ex3 [7,6,4,3,1]"); }
    // Edge: single element
    { vector<int> p = {5};           check(sol.maxProfit(p), 0, "single element [5]"); }
    // Edge: all same price
    { vector<int> p = {3,3,3,3};     check(sol.maxProfit(p), 0, "all same [3,3,3,3]"); }
    // Edge: two-day gain
    { vector<int> p = {1,5};         check(sol.maxProfit(p), 4, "two days [1,5]"); }
    // Edge: valley-peak-valley-peak
    { vector<int> p = {2,4,1,7};     check(sol.maxProfit(p), 8, "two trades [2,4,1,7]"); }

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
