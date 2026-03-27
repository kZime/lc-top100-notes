package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func maxArea(height []int) int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want int, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// Example 1
	check(maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7}), 49, "example1: [1,8,6,2,5,4,8,3,7]")
	// Example 2
	check(maxArea([]int{1, 1}), 1, "example2: [1,1]")
	// Edge: two elements, one tall
	check(maxArea([]int{4, 3}), 3, "edge: [4,3]")
	// Edge: all equal
	check(maxArea([]int{5, 5, 5, 5, 5}), 20, "edge: all 5s, n=5")
	// Edge: increasing then decreasing
	check(maxArea([]int{1, 2, 4, 3, 1}), 6, "edge: [1,2,4,3,1]")
	// Edge: single tall on far ends
	check(maxArea([]int{10, 1, 1, 1, 1, 1, 10}), 60, "edge: tall ends")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
