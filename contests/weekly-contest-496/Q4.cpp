//
// Created by Yimu Liu on 2026/4/4.
//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minOperations(vector<int> nums, int k) {

    }
};

// 2, [2, 1, 1, 1, 1, 1, 2] 2
// k = 2

// n is odd
// max k = (n-1)/2

// 2, [2,1,2, 2, 2,2] 2

// n is even
// max k = n/2
// 最大只有两种可能


// 两端不能同时最大

int main () {
    Solution sol;
    assert(sol.minOperations({2, 1, 2}, 1) == 1);


}
