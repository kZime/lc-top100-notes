package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func moveZeroes(nums []int) {
	// TODO: implement
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func eqSlice(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func main() {
	passed, total := 0, 0

	check := func(nums, want []int, label string) {
		total++
		moveZeroes(nums)
		if eqSlice(nums, want) {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, nums)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, nums)
		}
	}

	check([]int{0, 1, 0, 3, 12}, []int{1, 3, 12, 0, 0}, "example1")
	check([]int{0}, []int{0}, "example2: single zero")
	check([]int{1}, []int{1}, "single non-zero")
	check([]int{1, 2, 3}, []int{1, 2, 3}, "no zeros")
	check([]int{0, 0, 0}, []int{0, 0, 0}, "all zeros")
	check([]int{0, 0, 1}, []int{1, 0, 0}, "zeros at front")
	check([]int{1, 0, 2, 0, 3, 0}, []int{1, 2, 3, 0, 0, 0}, "interleaved zeros")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
