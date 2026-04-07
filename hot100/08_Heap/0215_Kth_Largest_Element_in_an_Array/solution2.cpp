#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────
class Solution {
public:
    // TLE at many same elements

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;


        return quickSelect(nums, 0, n-1, target);
    }

private:
    int quickSelect(std::vector<int>& nums, int left, int right, int target) {
        if (left == right) return nums[left];

        int pivot_idx = left + rand()%(right - left + 1);
        int pivot = nums[pivot_idx];

        swap(nums[pivot_idx], nums[right]);
        int i = left;

        for (int j = left; j < right; j++) { // <= pivot, left
            if (nums[j] <= pivot) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
        // i: first > pivot
        swap(nums[i], nums[right]);

        if (target == i) {
            return nums[i];
        } else if (target < i) {
            return quickSelect(nums, left, i-1, target);
        } else {
            return quickSelect(nums, i+1, right, target);
        }

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

    // Examples from problem
    vector<int> v1 = {3,2,1,5,6,4};
    check(sol.findKthLargest(v1, 2), 5, "example1: [3,2,1,5,6,4] k=2");

    vector<int> v2 = {3,2,3,1,2,4,5,5,6};
    check(sol.findKthLargest(v2, 4), 4, "example2: [3,2,3,1,2,4,5,5,6] k=4");

    // Edge cases
    vector<int> v3 = {1};
    check(sol.findKthLargest(v3, 1), 1, "single element");

    vector<int> v4 = {5,5,5,5};
    check(sol.findKthLargest(v4, 2), 5, "all same elements");

    vector<int> v5 = {-1,-2,-3,-4,-5};
    check(sol.findKthLargest(v5, 1), -1, "all negative, k=1");

    vector<int> v6 = {2,1};
    check(sol.findKthLargest(v6, 2), 1, "two elements, k=2 (smallest)");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
