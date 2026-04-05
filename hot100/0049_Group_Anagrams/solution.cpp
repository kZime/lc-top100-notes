#include <bits/stdc++.h>
using namespace std;

// ─── Solution ────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
         *
         *
         *
         */

        unordered_map<string, vector<string> > mp;
        for (auto c : strs) {
            string ori_c = c;
            sort(c.begin(), c.end());
            mp[c].push_back(ori_c);
        }
        vector<vector<string>> res;
        for (auto cc : mp) {
            res.push_back(cc.second);
        }

        return res;
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

// Compare two group-anagram results regardless of inner/outer order
bool equal(vector<vector<string>> a, vector<vector<string>> b) {
    if (a.size() != b.size()) return false;
    auto norm = [](vector<vector<string>>& v) {
        for (auto& g : v) sort(g.begin(), g.end());
        sort(v.begin(), v.end());
    };
    norm(a); norm(b);
    return a == b;
}

int main() {
    Solution sol;

    struct TestCase {
        vector<string> strs;
        vector<vector<string>> expected;
    };

    vector<TestCase> tests = {
        // Example 1
        {{"eat","tea","tan","ate","nat","bat"},
         {{"bat"},{"nat","tan"},{"ate","eat","tea"}}},
        // Example 2: single empty string
        {{""},
         {{""}}},
        // Example 3: single char
        {{"a"},
         {{"a"}}},
        // All same anagram
        {{"abc","bca","cab"},
         {{"abc","bca","cab"}}},
        // No anagrams among them
        {{"a","b","c"},
         {{"a"},{"b"},{"c"}}},
    };

    int passed = 0;
    for (int i = 0; i < (int)tests.size(); i++) {
        auto& t = tests[i];
        auto result = sol.groupAnagrams(t.strs);
        bool ok = equal(result, t.expected);
        cout << "Test " << i + 1 << ": " << (ok ? "PASS" : "FAIL") << "\n";
        if (!ok) {
            auto print = [](const vector<vector<string>>& v, const string& label) {
                cout << "  " << label << ": [";
                for (auto& g : v) {
                    cout << "[";
                    for (int j = 0; j < (int)g.size(); j++)
                        cout << "\"" << g[j] << "\"" << (j+1<(int)g.size()?",":"");
                    cout << "]";
                }
                cout << "]\n";
            };
            print(t.expected, "expected");
            print(result,     "got    ");
        }
        if (ok) passed++;
    }

    cout << "\n" << passed << "/" << tests.size() << " passed\n";
    return passed == (int)tests.size() ? 0 : 1;
}
