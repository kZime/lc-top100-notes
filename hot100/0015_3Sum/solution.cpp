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
         * BF: O(N^3) TLE
         *
         *
         */
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        int a = min({nums[i], nums[k], nums[j]});
                        int c = max({nums[i], nums[k], nums[j]});
                        int b = -a - c;
                        ans.push_back({a, b, c});
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

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

    check({0,1,1},            {},                     "example2: no triplet");
    check({0,0,0},            {{0,0,0}},              "example3: all zeros");
    check({-1, 0, 1, 2, -1, -4},            {{-1, -1, 2}, {-1, 0, 1}},              "example3: all zeros");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
