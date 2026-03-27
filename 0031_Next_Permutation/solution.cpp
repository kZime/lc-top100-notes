#include <bits/stdc++.h>
using namespace std;

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // 1. find increase list from back
        vector<int> bk(1, nums.back());
        int x = -1;
        nums.pop_back();

        while (!nums.empty()) {
            if (nums.back() >= bk.back()) {
                bk.push_back(nums.back());
                nums.pop_back();
            } else {
                x = nums.back();
                nums.pop_back();
                break;
            }
        }

        if (x == -1) {
            // all in bk, eg. [5,4,3,2,1]
            for (auto b : bk)
                nums.push_back(b);
            return;
        }

        int idx = upper_bound(bk.begin(), bk.end(), x) - bk.begin();

        if (idx != bk.size())
            swap(bk[idx], x);

        nums.push_back(x);
        for (auto b : bk)
            nums.push_back(b);
    }
};

// ─── Helpers ──────────────────────────────────────────────────────────────────

bool eq(const vector<int>& a, const vector<int>& b) {
    return a == b;
}

string vecStr(const vector<int>& v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) s += ",";
        s += to_string(v[i]);
    }
    return s + "]";
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> nums, vector<int> want, const string& label) {
        total++;
        sol.nextPermutation(nums);
        if (eq(nums, want)) {
            printf("%s: PASS\n", label.c_str());
            passed++;
        } else {
            printf("%s: FAIL  want=%s got=%s\n",
                   label.c_str(), vecStr(want).c_str(), vecStr(nums).c_str());
        }
    };

    // User cases
    check({5,3,4,7,6,2,1}, {5,3,6,1,2,4,7}, "user: [5,3,4,7,6,2,1]");
    check({1,5,1}, {5,1,1},   "user: [1,5,1]");
    check({1,1}, {1, 1}, "user: [1, 1]");


    // Example cases
    // check({1,2,3}, {1,3,2},   "ex1: [1,2,3]");
    check({3,2,1}, {1,2,3},   "ex2: [3,2,1] -> wrap");
    check({1,1,5}, {1,5,1},   "ex3: [1,1,5]");


    // Edge cases
    check({1},     {1},       "edge: single element");
    check({1,2},   {2,1},     "edge: two elements ascending");
    check({2,1},   {1,2},     "edge: two elements descending");
    check({1,3,2}, {2,1,3},   "misc: [1,3,2]");
    check({2,3,1}, {3,1,2},   "misc: [2,3,1]");

    printf("\n%d/%d passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}
