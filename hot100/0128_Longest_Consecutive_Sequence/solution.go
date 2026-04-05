package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func longestConsecutive(nums []int) int {
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

	// Examples from problem statement
	check(longestConsecutive([]int{100, 4, 200, 1, 3, 2}), 4, "[100,4,200,1,3,2]")
	check(longestConsecutive([]int{0, 3, 7, 2, 5, 8, 1, 6, 0, 4}), 9, "[0,3,7,2,5,8,1,6,0,4]")
	// Edge cases
	check(longestConsecutive([]int{}), 0, "empty array")
	check(longestConsecutive([]int{42}), 1, "single element")
	check(longestConsecutive([]int{5, 5, 5, 5}), 1, "all duplicates")
	check(longestConsecutive([]int{-3, -2, -1, 0, 1, 2, 3}), 7, "negative to positive")
	check(longestConsecutive([]int{1, 3, 5, 7}), 1, "no consecutive pairs")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
