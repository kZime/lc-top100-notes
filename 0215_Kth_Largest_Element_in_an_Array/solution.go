package main

import (
	"fmt"
)

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func findKthLargest(nums []int, k int) int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want int, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %d\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%d  got=%d\n", label, want, got)
		}
	}

	// Examples from problem
	check(findKthLargest([]int{3, 2, 1, 5, 6, 4}, 2), 5, "example1: [3,2,1,5,6,4] k=2")
	check(findKthLargest([]int{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4), 4, "example2: [3,2,3,1,2,4,5,5,6] k=4")

	// Edge cases
	check(findKthLargest([]int{1}, 1), 1, "single element")
	check(findKthLargest([]int{5, 5, 5, 5}, 2), 5, "all same elements")
	check(findKthLargest([]int{-1, -2, -3, -4, -5}, 1), -1, "all negative, k=1")
	check(findKthLargest([]int{2, 1}, 2), 1, "two elements, k=2 (smallest)")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
