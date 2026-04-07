#include <bits/stdc++.h>
using namespace std;

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r-l)/2; // l may == mid
            if (nums[mid] == target) return mid;

            if (nums[l] <= nums[mid]) { // [l, mid] increase
                if (nums[l] <= target && target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else { // [mid, r] increase
                if (nums[mid] <= target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        // 循环以 l < r 为条件，退出时 l==r，该位置从未被检查
        return nums[l] == target ? l : -1;
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
