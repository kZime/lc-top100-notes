package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func rob(nums []int) int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(nums []int, want int, label string) {
		total++
		got := rob(nums)
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-40s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-40s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// Examples
	check([]int{1, 2, 3, 1},   4,  "example1: [1,2,3,1]")
	check([]int{2, 7, 9, 3, 1}, 12, "example2: [2,7,9,3,1]")

	// Edge cases
	check([]int{0},          0, "single house, 0")
	check([]int{5},          5, "single house, 5")
	check([]int{1, 2},       2, "two houses, take max")
	check([]int{2, 1, 1, 2}, 4, "two ends optimal")
	check([]int{0, 0, 0, 0}, 0, "all zeros")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
