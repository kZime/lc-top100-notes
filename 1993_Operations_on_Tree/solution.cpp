#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class LockingTree {
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> locked;  // locked[i] = user id (0 = unlocked)
    int n;

public:
    LockingTree(vector<int>& parent) : parent(parent), n(parent.size()),
        children(parent.size()), locked(parent.size(), 0) {
        // TODO: implement
    }

    bool lock(int num, int user) {
        // TODO: implement
        return false;
    }

    bool unlock(int num, int user) {
        // TODO: implement
        return false;
    }

    bool upgrade(int num, int user) {
        // TODO: implement
        return false;
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    int passed = 0, total = 0;

    auto check = [&](bool got, bool want, const string& label) {
        total++;
        if (got == want) {
            printf(GRN "✓" RST "  %-40s →  %s\n", label.c_str(), got ? "true" : "false");
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-40s" RST "    want=%s  got=%s\n",
                   label.c_str(), want ? "true" : "false", got ? "true" : "false");
        }
    };

    // Example 1: [-1, 0, 0, 1, 1, 2, 2]
    // Tree:  0 -> {1,2}, 1 -> {3,4}, 2 -> {5,6}
    {
        vector<int> p = {-1, 0, 0, 1, 1, 2, 2};
        LockingTree t(p);
        check(t.lock(2, 2),    true,  "ex1: lock(2,2)");
        check(t.unlock(2, 3),  false, "ex1: unlock(2,3) wrong user");
        check(t.unlock(2, 2),  true,  "ex1: unlock(2,2)");
        check(t.lock(4, 5),    true,  "ex1: lock(4,5)");
        check(t.upgrade(0, 1), true,  "ex1: upgrade(0,1)");
        check(t.lock(0, 1),    false, "ex1: lock(0,1) already locked");
    }

    // Edge: lock already-locked node
    {
        vector<int> p = {-1, 0, 1};
        LockingTree t(p);
        check(t.lock(1, 1),   true,  "edge: lock(1,1) first time");
        check(t.lock(1, 2),   false, "edge: lock(1,2) already locked");
    }

    // Edge: upgrade fails — node already locked
    {
        vector<int> p = {-1, 0, 1};
        LockingTree t(p);
        t.lock(0, 1);
        t.lock(2, 2);
        check(t.upgrade(0, 3), false, "edge: upgrade fails — root already locked");
    }

    // Edge: upgrade fails — no locked descendants
    {
        vector<int> p = {-1, 0, 1};
        LockingTree t(p);
        check(t.upgrade(0, 1), false, "edge: upgrade fails — no locked desc");
    }

    // Edge: upgrade fails — locked ancestor
    {
        vector<int> p = {-1, 0, 1};
        LockingTree t(p);
        t.lock(0, 1);
        t.lock(2, 2);
        check(t.upgrade(1, 3), false, "edge: upgrade fails — ancestor locked");
    }

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
