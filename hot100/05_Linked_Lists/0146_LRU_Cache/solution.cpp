#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class LRUCache {
public:
    LRUCache(int capacity) {
        // TODO: implement
    }

    int get(int key) {
        // TODO: implement
        return -1;
    }

    void put(int key, int value) {
        // TODO: implement
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    int passed = 0, total = 0;

    auto check = [&](int got, int want, const string& label) {
        total++;
        if (got == want) {
            printf(GRN "✓" RST "  %-40s →  %d\n", label.c_str(), got);
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-40s" RST "    want=%d  got=%d\n",
                   label.c_str(), want, got);
        }
    };

    // Example 1 (from problem statement)
    {
        LRUCache c(2);
        c.put(1, 1);
        c.put(2, 2);
        check(c.get(1),    1, "ex1: get(1)");
        c.put(3, 3);
        check(c.get(2),   -1, "ex1: get(2) after eviction");
        c.put(4, 4);
        check(c.get(1),   -1, "ex1: get(1) after eviction");
        check(c.get(3),    3, "ex1: get(3)");
        check(c.get(4),    4, "ex1: get(4)");
    }

    // Edge: capacity 1
    {
        LRUCache c(1);
        c.put(1, 10);
        check(c.get(1),   10, "cap1: get(1)=10");
        c.put(2, 20);
        check(c.get(1),   -1, "cap1: get(1) evicted");
        check(c.get(2),   20, "cap1: get(2)=20");
    }

    // Edge: update existing key
    {
        LRUCache c(2);
        c.put(1, 1);
        c.put(2, 2);
        c.put(1, 10);
        c.put(3, 3);
        check(c.get(2),   -1, "update: key 2 evicted");
        check(c.get(1),   10, "update: key 1 = 10");
        check(c.get(3),    3, "update: key 3 = 3");
    }

    // Edge: get promotes to MRU
    {
        LRUCache c(2);
        c.put(1, 1);
        c.put(2, 2);
        c.get(1);
        c.put(3, 3);
        check(c.get(1),    1, "promote: key 1 survives");
        check(c.get(2),   -1, "promote: key 2 evicted");
    }

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
