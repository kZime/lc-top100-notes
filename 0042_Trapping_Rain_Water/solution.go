package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func trap(height []int) int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(height []int, want int, label string) {
		total++
		got := trap(height)
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %d\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%d  got=%d\n", label, want, got)
		}
	}

	check([]int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6, "example1")
	check([]int{4, 2, 0, 3, 2, 5}, 9, "example2")
	check([]int{}, 0, "empty array")
	check([]int{3}, 0, "single bar")
	check([]int{1, 2}, 0, "two bars, no trap")
	check([]int{3, 0, 3}, 3, "simple valley")
	check([]int{0, 0, 0}, 0, "all zeros")
	check([]int{1, 0, 1, 0, 1}, 2, "alternating")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
