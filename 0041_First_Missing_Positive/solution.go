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

func firstMissingPositive(nums []int) int {
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
	check(firstMissingPositive([]int{1, 2, 0}), 3, "example1: [1,2,0]")
	check(firstMissingPositive([]int{3, 4, -1, 1}), 2, "example2: [3,4,-1,1]")
	check(firstMissingPositive([]int{7, 8, 9, 11, 12}), 1, "example3: [7,8,9,11,12]")

	// Edge cases
	check(firstMissingPositive([]int{1}), 2, "single element [1]")
	check(firstMissingPositive([]int{2}), 1, "single element [2]")
	check(firstMissingPositive([]int{1, 2, 3, 4, 5}), 6, "consecutive from 1")
	check(firstMissingPositive([]int{-5, -1, 0}), 1, "all non-positive")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
