package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func maxProfit(prices []int) int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want int, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-40s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-40s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// Example 1: two separate trades
	check(maxProfit([]int{3, 3, 5, 0, 0, 3, 1, 4}), 6, "ex1 [3,3,5,0,0,3,1,4]")
	// Example 2: one trade optimal
	check(maxProfit([]int{1, 2, 3, 4, 5}), 4, "ex2 [1,2,3,4,5]")
	// Example 3: descending — no profit
	check(maxProfit([]int{7, 6, 4, 3, 1}), 0, "ex3 [7,6,4,3,1]")
	// Edge: single element
	check(maxProfit([]int{5}), 0, "single [5]")
	// Edge: two elements gain
	check(maxProfit([]int{1, 4}), 3, "two days [1,4]")
	// Edge: best uses both transactions
	check(maxProfit([]int{1, 2, 3, 4, 5, 1, 2, 3, 4, 5}), 8, "double 1..5")
	// Edge: all same price
	check(maxProfit([]int{3, 3, 3, 3}), 0, "all same [3,3,3,3]")

	fmt.Printf("\n%s\n", "------------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
