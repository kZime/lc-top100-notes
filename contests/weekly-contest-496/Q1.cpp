//
// Created by Yimu Liu on 2026/4/4.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char mirror(char c) {
        if (isalpha(c)) return (25 - (c - 'a') + 'a');
        else if (isdigit(c)) return (9 - (c - '0') + '0');
    }

    int mirrorFrequency(string s) {
        unordered_map<char, int> cnt;
        unordered_set<char> sset;
        for (char c : s) {
            cnt[c]++;
            if (sset.count(mirror(c))) continue;
            else sset.insert(c);
        }
        int ans = 0;
        for (char c : sset) {
            ans += abs(cnt[c] - cnt[mirror(c)]);
        }
        return ans;
    }
};






int main () {
    Solution sol;
    assert(sol.mirrorFrequency( "4m7n") == 2);
    assert(sol.mirrorFrequency( "ab1z9") == 3);
}
