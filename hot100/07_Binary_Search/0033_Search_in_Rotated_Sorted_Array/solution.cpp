#include <bits/stdc++.h>
using namespace std;

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int fst = nums.front(), lst = nums.back();
        if (fst < lst) { // no rotated;
            if (target < fst or target > lst) return -1;
            int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            return nums[idx] == target ? idx : -1;
        }


        // small case;
        if (nums.size() <= 3) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) return i;
            }
            return -1;
        }

        // find k;
        int l = 0, r = nums.size()-1;

        // 找到比 fst 大的最大的数
        while (l+1 < r) { // avoid mid == l or r
            int mid = (l+r) / 2;
            if (nums[mid] > nums[l]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        // l is k;
        int k = l;
        if (target > nums[l] or target < nums[r])
            return -1;
        if (target > lst and target < fst)
            return -1;

        if (target >= fst) {
            int idx = lower_bound(nums.begin(), nums.begin()+r, target) - nums.begin();
            return nums[idx] == target ? idx : -1;
        } else { // target at right
            int idx = lower_bound(nums.begin()+r, nums.end(), target) - nums.begin();
            return nums[idx] == target ? idx : -1;
        }

    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> nums, int target, int want, const string& label) {
        total++;
        int got = sol.search(nums, target);
        if (got == want) {
            printf("%s: PASS\n", label.c_str());
            passed++;
        } else {
            printf("%s: FAIL  want=%d got=%d\n", label.c_str(), want, got);
        }
    };

    check({4,5,6,7,0,1,2}, 0, 4, "ex1: target in rotated array");
    check({4,5,6,7,8,1,2,3}, 8, 4, "edge2: two elements, target is second");
    check({3, 5, 1}, 5, 1, "edge2: two elements, target is second");
    check({1,3}, 0, -1, "edge2: two elements, target is second");
    check({3,1}, 1, 1, "edge2: two elements, target is second");
    // Examples from problem statement
    check({4,5,6,7,0,1,2}, 3, -1, "ex2: target not in rotated array");
    check({1}, 0, -1, "ex3: single element, target absent");

    // Edge cases
    check({1}, 1, 0, "edge1: single element, target present");
    check({3,1}, 3, 0, "edge3: two elements, target is first");
    check({1,2,3,4,5,6,7}, 5, 4, "edge4: not rotated, target present");
    check({5,6,7,1,2,3,4}, 7, 2, "edge5: rotated, target in left half");

    printf("\n%d/%d passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}
