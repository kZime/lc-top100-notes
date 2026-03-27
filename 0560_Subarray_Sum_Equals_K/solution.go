package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func subarraySum(nums []int, k int) int {
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

	check(subarraySum([]int{1, 1, 1}, 1), 2, "[1,1,1] k=1")
	check(subarraySum([]int{1, 2, 3}, 3), 2, "[1,2,3] k=3")
	check(subarraySum([]int{1}, 1), 1, "single element, match")
	check(subarraySum([]int{1}, 2), 0, "single element, no match")
	check(subarraySum([]int{-1, -1, 1}, -1), 2, "negative nums, k=-1")
	check(subarraySum([]int{0, 0, 0, 0}, 0), 10, "all zeros, k=0")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
