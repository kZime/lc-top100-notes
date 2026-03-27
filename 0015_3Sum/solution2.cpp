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

         * iteration val, N^2
         *
         */
        int n = nums.size();
        vector<vector<int>> ans;
        set<int> num_set;
        unordered_set<int> vis;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            num_set.insert(nums[i]);
            vis.insert(nums[i]);
            cnt[nums[i]]++;
        }
        for (auto a : num_set) { // increase
            // 3 * a
            if (a == 0 and cnt[a] >= 3) {
                ans.push_back({0, 0, 0});
            }
            // 2*a
            if (a != 0 and cnt[a] >= 2 and num_set.count(-2*a)) {
                if (a < -2*a) ans.push_back({a, a, -2*a});
                else ans.push_back({-2*a, a, a});
            }
            // only a!=b!=c
            {
                for (auto b : num_set) {
                    if (b <= a) continue; // b > a
                    int c = -a + -b;
                    if (c <= a or c <= b) continue;
                    if (not vis.count(c)) continue;
                    ans.push_back({a, b, c});
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
