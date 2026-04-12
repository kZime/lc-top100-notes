#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int largestRectangleArea(vector<int> heights) {
        // not iterate the last bar, but the height on current bar
        stack<pair<int, int> > stk; // {idx, val}
        int n = (int)heights.size();
        vector<int> nsi(n+1), psi(n+1); // next smaller index, prev smaller index
        
        // init psi
        stk.emplace(-1, -1);
        for (int i = 0; i < n; i++) {
            while (stk.top().second >= heights[i])
                stk.pop();
            psi[i] = stk.top().first;
            stk.emplace(i, heights[i]);
        }
        // init nsi
        while (!stk.empty()) stk.pop();
        stk.emplace(n, -1);
        for (int i = n-1; i >= 0; i--) {
            while (stk.top().second >= heights[i])
                stk.pop();
            nsi[i] = stk.top().first;
            stk.emplace(i, heights[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) { 
            ans = max(ans, heights[i] * (nsi[i] - psi[i] - 1));
        }

        return ans;
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

bool eq(int a, int b) { return a == b; }
string toString(int n) { return to_string(n); }

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    cout << "DEBUG \n";
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

    // Examples
    check(sol.largestRectangleArea({2,1,5,6,2,3}), 10, "[2,1,5,6,2,3]");
    check(sol.largestRectangleArea({2,4}),          4,  "[2,4]");
    // Edge cases
    check(sol.largestRectangleArea({1}),            1,  "[1] single bar");
    check(sol.largestRectangleArea({0}),            0,  "[0] zero height");
    check(sol.largestRectangleArea({2,2,2,2}),      8,  "[2,2,2,2] all equal");
    check(sol.largestRectangleArea({1,2,3,4,5}),    9,  "[1,2,3,4,5] ascending");
    check(sol.largestRectangleArea({5,4,3,2,1}),    9,  "[5,4,3,2,1] descending");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
