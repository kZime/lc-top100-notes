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
        vector<int> maxVIdx;
        int maxV = -1, n = height.size();
        for (int i = 0; i < n; i++) {
            if (height[i] < maxV) continue;

            if (height[i] > maxV) {
                maxV = height[i];
                maxVIdx.clear();
            }

            if (height[i] == maxV)
                maxVIdx.push_back(i);
        }
        int ans = 0;

        int l = maxVIdx.front(), r = maxVIdx.back();
        int i = 0, j = 0, tmp = 0;

        for (i = 0; i < l; i = j) {
            j = i+1;
            tmp = 0;
            while (height[j] <= height[i]) { // find next bigger
                tmp += height[i] - height[j];
                j++;
            }
            // hj >= hi
            ans += tmp;
        }

        for (i = n-1; i > r; i = j) {
            j = i-1;
            tmp = 0;
            while (height[j] <= height[i]) { // find next bigger
                tmp += height[i] - height[j];
                j--;
            }
            // hj >= hi
            ans += tmp;
        }

        for (i = l; i <= r; i++) {
            ans += maxV - height[i];
        }
        return ans;
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
