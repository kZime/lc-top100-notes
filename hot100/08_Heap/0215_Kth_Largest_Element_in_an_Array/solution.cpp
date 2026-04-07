#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> meds;

        // DEBUG
        cout << "nums: [ ";
        for (int i = 0; i < len; i++)
            cout << nums[i] << ", ";
        cout << "]\t";
        cout << "k=" << k << '\n';


        if (len == 1 and k == 1) return nums[0];
        // step 1, split to group with size 5
        for (int l = 0, r = 0; r != len; l = r) {
            r = min(len, l + 5);

            // cout << l << ", " << r << ": ";
            // for (int i = l; i < r; i++) {
            //     cout << nums[i] << ' ';
            // }
            // cout << '\n';
            // step 2: insert sort to each group (from big to small)
            for (int i = l+1; i < r; i++) {
                for (int j = i - 1; j >= l; j--) {
                    if (nums[j + 1] > nums[j]) swap(nums[j + 1], nums[j]);
                    else break;
                }
            }

            // cout << l << ", " << r << ": ";
            // for (int i = l; i < r; i++) {
            //     cout << nums[i] << ' ';
            // }
            // cout << '\n';

            meds.push_back(nums[(l+r)/2]);
        }

        // step 3: find medien of medien
        int mom = findKthLargest(meds, (meds.size() + 1) / 2);
        cout << "mom: " << mom << '\n';

        // step 4: partition nums with mom
        vector<int> lft, rgt;
        for (int i = 0; i < len; i++) {
            if (nums[i] > mom) lft.push_back(nums[i]);
            if (nums[i] < mom) rgt.push_back(nums[i]);
        }
        int equ = len - lft.size() - rgt.size(); // the number of items equal to mom;
        nums.clear();

        // 1
        if (k <= lft.size()) return findKthLargest(lft, k);
        // 2
        if (k > lft.size() + equ) return findKthLargest(rgt, k - lft.size() - equ);
        // 3
        return mom;
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
