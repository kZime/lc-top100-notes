package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

type MinStack struct {
	// TODO: implement
}

func Constructor() MinStack {
	// TODO: implement
	return MinStack{}
}

func (ms *MinStack) Push(val int) {
	// TODO: implement
}

func (ms *MinStack) Pop() {
	// TODO: implement
}

func (ms *MinStack) Top() int {
	// TODO: implement
	return 0
}

func (ms *MinStack) GetMin() int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	checkInt := func(got, want int, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-40s →  %d\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-40s"+rst+"    want=%d  got=%d\n", label, want, got)
		}
	}

	// Example 1: push(-2), push(0), push(-3), getMin, pop, top, getMin
	ms1 := Constructor()
	ms1.Push(-2)
	ms1.Push(0)
	ms1.Push(-3)
	checkInt(ms1.GetMin(), -3, "ex1: getMin after push(-2,0,-3)")
	ms1.Pop()
	checkInt(ms1.Top(),    0,  "ex1: top after pop")
	checkInt(ms1.GetMin(), -2, "ex1: getMin after pop")

	// Edge case: single element
	ms2 := Constructor()
	ms2.Push(5)
	checkInt(ms2.Top(),    5, "edge: single top")
	checkInt(ms2.GetMin(), 5, "edge: single getMin")

	// Edge case: duplicate minimums
	ms3 := Constructor()
	ms3.Push(1)
	ms3.Push(1)
	checkInt(ms3.GetMin(), 1, "edge: dup min before pop")
	ms3.Pop()
	checkInt(ms3.GetMin(), 1, "edge: dup min after pop")

	// Edge case: ascending then pop
	ms4 := Constructor()
	ms4.Push(3)
	ms4.Push(5)
	ms4.Push(7)
	checkInt(ms4.GetMin(), 3, "edge: asc getMin = 3")
	ms4.Pop()
	ms4.Pop()
	checkInt(ms4.Top(), 3, "edge: asc top after 2 pops = 3")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
