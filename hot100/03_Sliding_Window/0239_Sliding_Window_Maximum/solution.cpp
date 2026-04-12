#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int> > q; // {idx, val}

        // first k;
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.back().second <= nums[i])
                q.pop_back();
            q.emplace_back(i, nums[i]);

            while (!q.empty() && q.front().first <= i-k)
                q.pop_front();

            if (i >= k-1) ans.push_back(q.front().second);
        }

        return ans;
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

auto toString = [](vector<int> v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) { if (i) s += ","; s += to_string(v[i]); }
    return s + "]";
};
auto eq = [](vector<int> a, vector<int> b) { return a == b; };

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> nums, int k, vector<int> want, const string& label) {
        total++;
        vector<int> got = sol.maxSlidingWindow(nums, k);
        if (eq(got, want)) {
            printf(GRN "✓" RST "  %-36s →  %s\n", label.c_str(), toString(got).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(got).c_str());
        }
    };

    // All problem examples + ≥2 edge cases
    check({1,3,-1,-3,5,3,6,7}, 3, {3,3,5,5,6,7}, "example1: k=3");
    check({1},                  1, {1},            "example2: single element");
    check({1,-1},               1, {1,-1},         "edge: k=1 two elements");
    check({7,2,4},              2, {7,4},           "edge: k=2 decreasing");
    check({-7,-8,7,5,7,1,6,0}, 4, {7,7,7,7,7},    "edge: negative values");
    check({4,3,2,1},            2, {4,3,2},         "edge: descending");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
