#include <bits/stdc++.h>
using namespace std;

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TODO: implement
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

struct TestCase {
    vector<int> nums;
    int target;
    vector<int> expected;
};

bool check(vector<int> result, vector<int> expected) {
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());
    return result == expected;
}

int main() {
    Solution sol;

    vector<TestCase> tests = {
        // Example 1
        {{2, 7, 11, 15}, 9, {0, 1}},
        // Example 2
        {{3, 2, 4}, 6, {1, 2}},
        // Example 3
        {{3, 3}, 6, {0, 1}},
        // Edge: two elements
        {{1, 2}, 3, {0, 1}},
        // Negative numbers
        {{-3, 4, 3, 90}, 0, {0, 2}},
    };

    int passed = 0;
    for (int i = 0; i < (int)tests.size(); i++) {
        auto& t = tests[i];
        vector<int> result = sol.twoSum(t.nums, t.target);
        bool ok = check(result, t.expected);
        cout << "Test " << i + 1 << ": " << (ok ? "PASS" : "FAIL");
        if (!ok) {
            cout << "  expected [";
            for (int j = 0; j < (int)t.expected.size(); j++)
                cout << t.expected[j] << (j + 1 < (int)t.expected.size() ? "," : "");
            cout << "] got [";
            for (int j = 0; j < (int)result.size(); j++)
                cout << result[j] << (j + 1 < (int)result.size() ? "," : "");
            cout << "]";
        }
        cout << "\n";
        if (ok) passed++;
    }

    cout << "\n" << passed << "/" << tests.size() << " passed\n";
    return passed == (int)tests.size() ? 0 : 1;
}
