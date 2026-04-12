package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func largestRectangleArea(heights []int) int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want int, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-40s →  %d\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-40s"+rst+"    want=%d  got=%d\n", label, want, got)
		}
	}

	// Examples
	check(largestRectangleArea([]int{2, 1, 5, 6, 2, 3}), 10, "[2,1,5,6,2,3]")
	check(largestRectangleArea([]int{2, 4}),              4,  "[2,4]")
	// Edge cases
	check(largestRectangleArea([]int{1}),                 1,  "[1] single bar")
	check(largestRectangleArea([]int{0}),                 0,  "[0] zero height")
	check(largestRectangleArea([]int{2, 2, 2, 2}),        8,  "[2,2,2,2] all equal")
	check(largestRectangleArea([]int{1, 2, 3, 4, 5}),     9,  "[1,2,3,4,5] ascending")
	check(largestRectangleArea([]int{5, 4, 3, 2, 1}),     9,  "[5,4,3,2,1] descending")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
