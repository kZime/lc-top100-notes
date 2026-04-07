#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for (int i = 1; i < numRows; i++) {
            auto pre = res.back();
            vector<int> vec(i+1);
            for (int j = 0; j < i+1; j++) {
                if (j-1 >= 0) vec[j] += pre[j-1];
                if (j < i) vec[j] += pre[j];
            }
            res.emplace_back(move(vec));
        }
        return res;
    }
};

// ─── Helpers ─────────────────────────────────────────────────────────────────

string toString(const vector<vector<int>>& v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) s += ",";
        s += "[";
        for (int j = 0; j < (int)v[i].size(); j++) {
            if (j) s += ",";
            s += to_string(v[i][j]);
        }
        s += "]";
    }
    return s + "]";
}
bool eq(const vector<vector<int>>& a, const vector<vector<int>>& b) { return a == b; }

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](int numRows, vector<vector<int>> want, const string& label) {
        total++;
        auto got = sol.generate(numRows);
        if (eq(got, want)) {
            printf(GRN "✓" RST "  %-36s →  %s\n", label.c_str(), toString(got).c_str());
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%s  got=%s\n",
                   label.c_str(), toString(want).c_str(), toString(got).c_str());
        }
    };

    // Examples
    check(5, {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}}, "numRows=5");
    check(1, {{1}},                                       "numRows=1");

    // Edge cases
    check(2, {{1},{1,1}},          "numRows=2");
    check(3, {{1},{1,1},{1,2,1}},  "numRows=3");
    check(4, {{1},{1,1},{1,2,1},{1,3,3,1}}, "numRows=4");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
