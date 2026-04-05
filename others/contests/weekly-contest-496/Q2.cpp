//
// Created by Yimu Liu on 2026/4/4.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<ll, int> cnt;
        for (ll i = 1; i <= 1000; i++) {
            for (ll j = i + 1; j <= 1000; j++) {
                if (i*i*i + j*j*j > 1e9) break;
                cnt[i*i*i + j*j*j]++;
            }
        }
        vector<int> res;
        for (auto it : cnt) {
            if (it.second >= 2) {
                res.push_back(it.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};






int main () {
    Solution sol;
    auto res = sol.findGoodIntegers(302);
    for (int x : res) {
        cout << x << ", ";
    }

}
