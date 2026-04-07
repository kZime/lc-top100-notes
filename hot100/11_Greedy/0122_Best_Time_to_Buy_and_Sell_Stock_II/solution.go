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
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// Example 1: multiple transactions
	check(maxProfit([]int{7, 1, 5, 3, 6, 4}), 7, "ex1 [7,1,5,3,6,4]")
	// Example 2: ascending — one big trade
	check(maxProfit([]int{1, 2, 3, 4, 5}), 4, "ex2 [1,2,3,4,5]")
	// Example 3: descending — no profit
	check(maxProfit([]int{7, 6, 4, 3, 1}), 0, "ex3 [7,6,4,3,1]")
	// Edge: single element
	check(maxProfit([]int{5}), 0, "single element [5]")
	// Edge: all same price
	check(maxProfit([]int{3, 3, 3, 3}), 0, "all same [3,3,3,3]")
	// Edge: two-day gain
	check(maxProfit([]int{1, 5}), 4, "two days [1,5]")
	// Edge: valley-peak-valley-peak
	check(maxProfit([]int{2, 4, 1, 7}), 8, "two trades [2,4,1,7]")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
