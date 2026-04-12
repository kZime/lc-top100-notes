//
// Created by Yimu Liu on 2026/4/11.
//

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    const double PI = 3.1415926;
    vector<double> internalAngles(vector<int>& s) {
        vector<double> ans;
        sort(s.begin(), s.end());
        if (s[0] + s[1] <= s[2])
            return ans;

        int a = s[0], b = s[1], c = s[2];
        double cosA = 1.0* (b*b + c*c - a*a) / (2.0*b*c);
        double cosB = 1.0* (a*a + c*c - b*b) / (2.0*a*c);
        double cosC = 1.0* (a*a + b*b - c*c) / (2.0*a*b);

        ans = {cosA, cosB, cosC};

        for (auto &d: ans) {
            d = acos(d) * 180.0 / PI;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};


int main() {


}
