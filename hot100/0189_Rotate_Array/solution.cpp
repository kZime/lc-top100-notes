#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
    // O(n), mem: O(n)
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tmp;
        k %= n;
        for (int i = k; i >= 1; i--) {
            tmp.push_back(nums[n-i]);
        }
        for (int i = 0; i < n-k; i++) {
            tmp.push_back(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            nums[i] = tmp[i];
        }
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

string toString(const vector<int>& v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) s += ",";
        s += to_string(v[i]);
    }
    return s + "]";
}

bool eq(const vector<int>& a, const vector<int>& b) {
    return a == b;
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    // Rotates nums in-place then compares against want.
    auto check = [&](vector<int> nums, int k, vector<int> want, const string& label) {
        sol.rotate(nums, k);
        total++;
        if (eq(nums, want)) {
            printf(GRN "✓" RST "  %-36s →  %s\n", label.c_str(), toString(nums).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(nums).c_str());
        }
    };

    // Examples from problem statement
    check({1,2,3,4,5,6,7}, 3, {5,6,7,1,2,3,4}, "ex1: k=3");
    check({-1,-100,3,99},  2, {3,99,-1,-100},   "ex2: k=2");

    // Edge cases
    check({1},           0, {1},           "single elem, k=0");
    check({1,2},         1, {2,1},         "two elems, k=1");
    check({1,2,3},       3, {1,2,3},       "k == n (full rotation)");
    check({1,2,3,4,5},  10, {1,2,3,4,5},  "k == 2*n");
    check({1,2,3,4,5,6}, 0, {1,2,3,4,5,6},"k == 0");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
