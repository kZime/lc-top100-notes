#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    // O(N^2)

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 10);
        for (int i = 1; i <= n; i++) {
            int a = nums[i-1];
            s[i] = s[i-1] + a;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int sum = s[j] - s[i-1];
                if (sum == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](int got, int want, const string& label) {
        total++;
        if (got == want) {
            printf(GRN "✓" RST "  %-36s →  %d\n", label.c_str(), got);
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%d  got=%d\n",
                   label.c_str(), want, got);
        }
    };

    // Examples from problem statement
    vector<int> v1 = {1, 1, 1};
    check(sol.subarraySum(v1, 2), 2, "[1,1,1] k=1");

    vector<int> v2 = {1, 2, 3};
    check(sol.subarraySum(v2, 3), 2, "[1,2,3] k=3");

    // Edge cases
    vector<int> v3 = {1};
    check(sol.subarraySum(v3, 1), 1, "single element, match");

    vector<int> v4 = {1};
    check(sol.subarraySum(v4, 2), 0, "single element, no match");

    vector<int> v5 = {-1, -1, 1};
    check(sol.subarraySum(v5, -1), 3, "negative nums, k=-1");

    vector<int> v6 = {0, 0, 0, 0};
    check(sol.subarraySum(v6, 0), 10, "all zeros, k=0");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
