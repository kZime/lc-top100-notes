#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lt = 0, rt = n-1;

        for (int i = 0; i <= rt; ) {
            if (nums[i] == 0) {
                swap(nums[i++], nums[lt++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[rt--]);
            } else {
                i++;
            }
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

bool eq(const vector<int>& a, const vector<int>& b) { return a == b; }

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> nums, vector<int> want, const string& label) {
        total++;
        sol.sortColors(nums);
        if (eq(nums, want)) {
            printf(GRN "✓" RST "  %-40s →  %s\n", label.c_str(), toString(nums).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-40s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(nums).c_str());
        }
    };

    // Examples
    check({2,0,2,1,1,0}, {0,0,1,1,2,2}, "example1: [2,0,2,1,1,0]");
    check({2,0,1},        {0,1,2},       "example2: [2,0,1]");

    // Edge cases
    check({0},            {0},           "single 0");
    check({1},            {1},           "single 1");
    check({2},            {2},           "single 2");
    check({2,2,2},        {2,2,2},       "all 2s");
    check({0,0,0},        {0,0,0},       "all 0s");
    check({1,1,1},        {1,1,1},       "all 1s");
    check({2,1,0},        {0,1,2},       "reverse sorted");
    check({0,1,2,0,1,2},  {0,0,1,1,2,2}, "interleaved");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
