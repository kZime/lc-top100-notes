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
        // TODO: implement
        return {};
    }
};

// ─── Helpers ──────────────────────────────────────────────────────────────────

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

    vector<int> p1 = {7,1,5,3,6,4};
    check(sol.maxProfit(p1), 5, "example1 [7,1,5,3,6,4]");

    vector<int> p2 = {7,6,4,3,1};
    check(sol.maxProfit(p2), 0, "example2 [7,6,4,3,1]");

    vector<int> p3 = {1};
    check(sol.maxProfit(p3), 0, "single element");

    vector<int> p4 = {2,4,1};
    check(sol.maxProfit(p4), 2, "buy at 2 sell at 4");

    vector<int> p5 = {3,3,3,3};
    check(sol.maxProfit(p5), 0, "all same prices");

    vector<int> p6 = {1,2,3,4,5};
    check(sol.maxProfit(p6), 4, "strictly increasing");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
