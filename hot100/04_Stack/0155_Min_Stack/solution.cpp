#include <bits/stdc++.h>
using namespace std;

#define GRN "\033[32m"
#define RED "\033[31m"
#define BLD "\033[1m"
#define RST "\033[0m"

// ─── Solution ────────────────────────────────────────────────────────────────

class MinStack {
private:
    stack<int> s;  // main stack
    stack<int> m;  // min stack  NON-INC order

public:
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if (m.empty() or m.top() >= val) 
            m.push(val);
    }

    void pop() {
        if (m.top() == s.top()) 
            m.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }
};

// ─── Test Harness ─────────────────────────────────────────────────────────────

int main() {
    int passed = 0, total = 0;

    auto checkInt = [&](int got, int want, const string& label) {
        total++;
        if (got == want) {
            printf(GRN "✓" RST "  %-40s →  %d\n", label.c_str(), got);
            passed++;
        } else {
            printf(RED "✗" RST "  " BLD "%-40s" RST "    want=%d  got=%d\n",
                   label.c_str(), want, got);
        }
    };

    // Example 1: push(-2), push(0), push(-3), getMin, pop, top, getMin
    {
        MinStack ms;
        ms.push(-2);
        ms.push(0);
        ms.push(-3);
        checkInt(ms.getMin(), -3, "ex1: getMin after push(-2,0,-3)");
        ms.pop();
        checkInt(ms.top(),    0,  "ex1: top after pop");
        checkInt(ms.getMin(), -2, "ex1: getMin after pop");
    }

    // Edge case: single element
    {
        MinStack ms;
        ms.push(5);
        checkInt(ms.top(),    5, "edge: single top");
        checkInt(ms.getMin(), 5, "edge: single getMin");
    }

    // Edge case: duplicate minimums
    {
        MinStack ms;
        ms.push(1);
        ms.push(1);
        checkInt(ms.getMin(), 1, "edge: dup min before pop");
        ms.pop();
        checkInt(ms.getMin(), 1, "edge: dup min after pop");
    }

    // Edge case: ascending then pop reveals new min
    {
        MinStack ms;
        ms.push(3);
        ms.push(5);
        ms.push(7);
        checkInt(ms.getMin(), 3, "edge: asc getMin = 3");
        ms.pop();
        ms.pop();
        checkInt(ms.top(),    3, "edge: asc top after 2 pops = 3");
    }

    printf("\n%s\n", string(44, '-').c_str());
    if (passed == total)
        printf(GRN "%d / %d passed\n" RST, passed, total);
    else
        printf(RED "%d / %d passed\n" RST, passed, total);
    return (passed == total) ? 0 : 1;
}
