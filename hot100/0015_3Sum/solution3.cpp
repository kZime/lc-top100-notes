#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
         * two point N^2, mem: O(1)
         */
        int n = nums.size();
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 and nums[i] == nums[i-1]) continue; // skip to next i

            int l = i+1, r = n-1;
            while (l<r) {
                int s = nums[i] + nums[l] + nums[r];
                if (s > 0) {
                    r--;
                } else if (s < 0) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    do {
                        l++;
                    } while (nums[l] == nums[l-1] and l < r);
                    do {
                        r--;
                    } while (nums[r] == nums[r+1] and l < r);
                }
            }
        }
        return ans;
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

string toString(const vector<vector<int>>& v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        s += "[";
        for (int j = 0; j < (int)v[i].size(); j++) {
            s += to_string(v[i][j]);
            if (j + 1 < (int)v[i].size()) s += ",";
        }
        s += "]";
        if (i + 1 < (int)v.size()) s += ",";
    }
    return s + "]";
}

bool eq(vector<vector<int>> a, vector<vector<int>> b) {
    for (auto& row : a) sort(row.begin(), row.end());
    for (auto& row : b) sort(row.begin(), row.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> nums, vector<vector<int>> want, const string& label) {
        total++;
        auto got = sol.threeSum(nums);
        if (eq(got, want)) {
            printf(GRN "✓" RST "  %-36s →  %s\n", label.c_str(), toString(got).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(got).c_str());
        }
    };

    check({-2,0,1,1,2},            {{-2,0,2}, {-2,1,1}},              "example3: all zeros");
    check({-1, 0, 1, 2, -1, -4},            {{-1, -1, 2}, {-1, 0, 1}},              "example3: all zeros");
    check({0,1,1},            {},                     "example2: no triplet");
    check({0,0,0},            {{0,0,0}},              "example3: all zeros");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
