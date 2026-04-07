#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;

        for (int price : prices) {
            buy1 = max(buy1, -price);           //  best first buy
            sell1 = max(sell1, buy1 + price);   //  best first sell
            buy2 = max(buy2, sell1 - price);    //  best second buy
            sell2 = max(sell2, buy2 + price);   // best second sell
        }
        return max(sell1, sell2);  // from two sells
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
            printf(GRN "✓" RST "  %-40s →  %s\n", label.c_str(), toString(got).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-40s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(got).c_str());
        }
    };

    // Example 1: two separate trades
    { vector<int> p = {3,3,5,0,0,3,1,4}; check(sol.maxProfit(p), 6, "ex1 [3,3,5,0,0,3,1,4]"); }
    // Example 2: one trade optimal
    { vector<int> p = {1,2,3,4,5};        check(sol.maxProfit(p), 4, "ex2 [1,2,3,4,5]"); }
    // Example 3: descending — no profit
    { vector<int> p = {7,6,4,3,1};        check(sol.maxProfit(p), 0, "ex3 [7,6,4,3,1]"); }
    // Edge: single element
    { vector<int> p = {5};                check(sol.maxProfit(p), 0, "single [5]"); }
    // Edge: two elements gain
    { vector<int> p = {1,4};              check(sol.maxProfit(p), 3, "two days [1,4]"); }
    // Edge: best uses both transactions
    { vector<int> p = {1,2,3,4,5,1,2,3,4,5}; check(sol.maxProfit(p), 8, "double 1..5"); }
    // Edge: all same price
    { vector<int> p = {3,3,3,3};          check(sol.maxProfit(p), 0, "all same [3,3,3,3]"); }

    printf("\n%s\n", string(48, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
