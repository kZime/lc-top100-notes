#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // TODO: implement
        return {};
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](int got, int want, const string& label) {
        total++;
        if (got == want) {
            printf(GRN "✓" RST "  %-36s →  %d\n", label.c_str(), got);
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%d  got=%d\n",
                   label.c_str(), want, got);
        }
    };

    // Examples from problem
    vector<int> v1 = {1,2,0};
    check(sol.firstMissingPositive(v1), 3, "example1: [1,2,0]");

    vector<int> v2 = {3,4,-1,1};
    check(sol.firstMissingPositive(v2), 2, "example2: [3,4,-1,1]");

    vector<int> v3 = {7,8,9,11,12};
    check(sol.firstMissingPositive(v3), 1, "example3: [7,8,9,11,12]");

    // Edge cases
    vector<int> v4 = {1};
    check(sol.firstMissingPositive(v4), 2, "single element [1]");

    vector<int> v5 = {2};
    check(sol.firstMissingPositive(v5), 1, "single element [2]");

    vector<int> v6 = {1,2,3,4,5};
    check(sol.firstMissingPositive(v6), 6, "consecutive from 1");

    vector<int> v7 = {-5,-1,0};
    check(sol.firstMissingPositive(v7), 1, "all non-positive");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
