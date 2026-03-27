#include <bits/stdc++.h>
using namespace std;

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // TODO: implement
        return -1;
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

    // Examples from problem statement
    check({4,5,6,7,0,1,2}, 0, 4, "ex1: target in rotated array");
    check({4,5,6,7,0,1,2}, 3, -1, "ex2: target not in rotated array");
    check({1}, 0, -1, "ex3: single element, target absent");

    // Edge cases
    check({1}, 1, 0, "edge1: single element, target present");
    check({3,1}, 1, 1, "edge2: two elements, target is second");
    check({3,1}, 3, 0, "edge3: two elements, target is first");
    check({1,2,3,4,5,6,7}, 5, 4, "edge4: not rotated, target present");
    check({5,6,7,1,2,3,4}, 7, 2, "edge5: rotated, target in left half");

    printf("\n%d/%d passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}
