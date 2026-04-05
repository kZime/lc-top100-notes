#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    int trap(vector<int>& height) {
        // TODO: implement
        return 0;
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> height, int want, const string& label) {
        total++;
        int got = sol.trap(height);
        if (got == want) {
            printf(GRN "✓" RST "  %-36s →  %d\n", label.c_str(), got);
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-36s" RST "    want=%d  got=%d\n",
                   label.c_str(), want, got);
        }
    };

    check({0,1,0,2,1,0,1,3,2,1,2,1}, 6,  "example1");
    check({4,2,0,3,2,5},              9,  "example2");
    check({},                          0,  "empty array");
    check({3},                         0,  "single bar");
    check({1,2},                       0,  "two bars, no trap");
    check({3,0,3},                     3,  "simple valley");
    check({0,0,0},                     0,  "all zeros");
    check({1,0,1,0,1},                 2,  "alternating");

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
