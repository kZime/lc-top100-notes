#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return *max_element(nums.begin(), nums.end());
        vector<int> dp(n);
        // why can I use only one dimension of dp ??
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(
                        dp[i-1],
                        dp[i-2] + nums[i]
                    );
        }
        return dp[n-1];
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

string toString(int v) { return to_string(v); }
bool eq(int a, int b) { return a == b; }

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> nums, int want, const string& label) {
        total++;
        int got = sol.rob(nums);
        if (eq(got, want)) {
            printf(GRN "✓" RST "  %-40s →  %s\n", label.c_str(), toString(got).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-40s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(got).c_str());
        }
    };

    // Examples
    check({1,2,3,1},   4,  "example1: [1,2,3,1]");
    check({2,7,9,3,1}, 12, "example2: [2,7,9,3,1]");

    // Edge cases
    check({0},         0,   "single house, 0");
    check({5},         5,   "single house, 5");
    check({1,2},       2,   "two houses, take max");
    check({2,1,1,2},   4,   "two ends optimal");
    check({0,0,0,0},   0,   "all zeros");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
