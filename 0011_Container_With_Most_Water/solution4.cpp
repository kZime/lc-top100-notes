#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n-1;
        while (l < r) {
            ans = max(ans, (r-l) * min(height[l], height[r]));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
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

    // Example 1
    { vector<int> h = {1,8,6,2,5,4,8,3,7}; check(sol.maxArea(h), 49, "example1: [1,8,6,2,5,4,8,3,7]"); }
    // Example 2
    { vector<int> h = {1,1}; check(sol.maxArea(h), 1, "example2: [1,1]"); }
    // Edge: two elements, one tall
    { vector<int> h = {4,3}; check(sol.maxArea(h), 3, "edge: [4,3]"); }
    // Edge: all equal
    { vector<int> h = {5,5,5,5,5}; check(sol.maxArea(h), 20, "edge: all 5s, n=5"); }
    // Edge: increasing then decreasing
    { vector<int> h = {1,2,4,3,1}; check(sol.maxArea(h), 4, "edge: [1,2,4,3,1]"); }
    // Edge: single tall on far ends
    { vector<int> h = {10,1,1,1,1,1,10}; check(sol.maxArea(h), 60, "edge: tall ends"); }

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
