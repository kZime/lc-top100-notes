//
// Created by Yimu Liu on 2026/4/4.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long minIncrease(vector<int> nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 1; i + 1 < n; i += 2) {
            int target = max(nums[i-1], nums[i+1]) + 1;
            if (nums[i] < target) ans += target - nums[i];
        }
        if (n % 2 == 1) return ans;


        long long tmp = ans;
        long long ans2 = ans;
        // ans
        for (int i = n-3; i >= 0; i -= 2) {
            // turn i to i+1
            if (nums[i] <= max(nums[i+1], nums[i-1])) {
                tmp -= max(nums[i+1], nums[i-1]) +1 - nums[i];
            }
            if (nums[i+1] <= max(nums[i], nums[i+2])) {
                tmp += max(nums[i], nums[i+2]) + 1 - nums[i+1];
            }
            ans2 = min(ans2, tmp);

        }

        return min(ans, ans2);
    }
};





int main () {
    Solution sol;
    assert(sol.minIncrease({17,22,35,33,27,10}) == 7);
    assert(sol.minIncrease({21, 12, 18, 19}) == 2);
    assert(sol.minIncrease({12, 23, 13, 17, 21, 3}) == 0);
    assert(sol.minIncrease({1, 2, 2}) == 1);
    assert(sol.minIncrease({2, 1, 1, 3}) == 2);
    assert(sol.minIncrease({5, 2, 1, 4, 3}) == 4);


}
