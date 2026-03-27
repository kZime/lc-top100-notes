#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vis;

        for (auto a : nums)
            vis.insert(a);

        int ans = 0;
        for (auto a : nums) {
            if (!vis.count(a)) continue;
            if (vis.count(a-1)) continue; // find the starter

            int tmp = 1, b = a+1;
            vis.erase(a);

            while (vis.count(b)) {
                tmp++; // add b
                vis.erase(b);
                b++; // check next
            }
            ans = max(ans, tmp);
        }
        return ans;
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

    // Examples from problem statement
    {
        vector<int> nums = {100,4,200,1,3,2};
        check(sol.longestConsecutive(nums), 4, "[100,4,200,1,3,2]");
    }
    {
        vector<int> nums = {0,3,7,2,5,8,1,6,0,4};
        check(sol.longestConsecutive(nums), 9, "[0,3,7,2,5,8,1,6,0,4]");
    }
    {
        vector<int> nums = {1, 0, 1, 2};
        check(sol.longestConsecutive(nums), 3, "[1, 0, 1, 2]");
    }
    // Edge cases
    {
        vector<int> nums = {};
        check(sol.longestConsecutive(nums), 0, "empty array");
    }
    {
        vector<int> nums = {42};
        check(sol.longestConsecutive(nums), 1, "single element");
    }
    {
        vector<int> nums = {5,5,5,5};
        check(sol.longestConsecutive(nums), 1, "all duplicates");
    }
    {
        vector<int> nums = {-3,-2,-1,0,1,2,3};
        check(sol.longestConsecutive(nums), 7, "negative to positive");
    }
    {
        vector<int> nums = {1,3,5,7};
        check(sol.longestConsecutive(nums), 1, "no consecutive pairs");
    }
    {
        vector<int> nums(1000);
        iota(nums.begin(), nums.end(), 100000);
        check(sol.longestConsecutive(nums), 1000, "big numbers");
    }

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
