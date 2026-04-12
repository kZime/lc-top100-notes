//
// Created by Yimu Liu on 2026/4/11.
//

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int longestBalanced(string s) {
        int n = (int) s.size();
        int cnt[2] = {0, 0};
        for (auto &c : s) cnt[c-'0']++;

        vector<int> pre(n+1); // set '0' as -1, '1' as +1
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + (s[i] == '0' ? -1 : 1); // pre[i] = cnt1 - cnt0 in s[0..i-1]
        }
        // pre[i] == 0: 0s and 1s are balanced in s[0..i]

        unordered_map<int, vector<int>> pos; // preSum: idx
        for (int i = 0; i <= n; i++) {
            pos[pre[i]].push_back(i);
        }

        int ans = 0;
        // cnt1 == cnt0:
        for (auto &[_, idxs] : pos) {
            ans = max(ans, idxs.back() - idxs.front());
        };
        // cout << ans << '\n';



        auto check = [&](int d, int lim) {
            if (lim <= 0) return; // no valid swap possible

            for (int i = 0; i <= n; i++) { // seg started i
                auto itVec = pos.find(pre[i] + d);
                if (itVec == pos.end()) continue;

                auto &idxs = itVec->second;

                // the largest j hold j <= i + lim
                auto it = upper_bound(idxs.begin(), idxs.end(), i + lim);
                if (it == idxs.begin()) continue;

                --it;
                int j = *it;
                if (j > i) {
                    ans = max(ans, j - i);
                }
            }
        };

        // cnt1 - cnt0 == 2, and len <= 2 * count(0)
        check(2, 2 * cnt[0]);
        // cout << ans << '\n';

        // cnt1 - cnt0 == -2, len <= 2 * count(1)
        check(-2, 2 * cnt[1]);
        // cout << ans << '\n';

        return ans;

    }
};


int main() {
    Solution sol;

    auto test = [&](string s, int expected) {
        int got = sol.longestBalanced(s);
        cout << (got == expected ? "✓" : "✗")
             << "  s=\"" << s << "\"  expected=" << expected << "  got=" << got << "\n";
    };

    test("100001",     4);   // swap s[1]↔s[5] → "110000", pick "1100" (len 4)
    test("111",        0);   // all ones, no balanced substring possible
    test("10",         2);   // already balanced
    test("1100",       4);   // already balanced
    test("0",          0);   // single char
    test("1111100000", 10);  // 5+5, already balanced → whole string
    test("000001",     2);   // 1 one, 5 zeros → best is "10" or "01" (len 2)
    test("01",         2);   // already balanced
    test("110100",     6);   // 3+3, already balanced → whole string
    test("11100",      4);   // 3 ones 2 zeros; swap gives best balanced len 4

    return 0;
}
