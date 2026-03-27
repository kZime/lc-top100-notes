#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // TODO: implement
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

string toString(const vector<int>& v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        s += to_string(v[i]);
        if (i + 1 < (int)v.size()) s += ",";
    }
    return s + "]";
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> nums, vector<int> want, const string& label) {
        total++;
        sol.moveZeroes(nums);
        if (nums == want) {
            printf(GRN "✓" RST "  %-36s →  %s\n", label.c_str(), toString(nums).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(nums).c_str());
        }
    };

    check({0,1,0,3,12},   {1,3,12,0,0},  "example1");
    check({0},             {0},           "example2: single zero");
    check({1},             {1},           "single non-zero");
    check({1,2,3},         {1,2,3},       "no zeros");
    check({0,0,0},         {0,0,0},       "all zeros");
    check({0,0,1},         {1,0,0},       "zeros at front");
    check({1,0,2,0,3,0},  {1,2,3,0,0,0}, "interleaved zeros");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
