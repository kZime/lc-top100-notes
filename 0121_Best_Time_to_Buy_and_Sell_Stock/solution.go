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

	check(maxProfit([]int{7, 1, 5, 3, 6, 4}), 5, "example1 [7,1,5,3,6,4]")
	check(maxProfit([]int{7, 6, 4, 3, 1}), 0, "example2 [7,6,4,3,1]")
	check(maxProfit([]int{1}), 0, "single element")
	check(maxProfit([]int{2, 4, 1}), 2, "buy at 2 sell at 4")
	check(maxProfit([]int{3, 3, 3, 3}), 0, "all same prices")
	check(maxProfit([]int{1, 2, 3, 4, 5}), 4, "strictly increasing")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
