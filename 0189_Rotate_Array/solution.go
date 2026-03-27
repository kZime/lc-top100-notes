package main

import (
	"fmt"
	"reflect"
)

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func rotate(nums []int, k int) {
	// TODO: implement
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(nums []int, k int, want []int, label string) {
		total++
		rotate(nums, k)
		if reflect.DeepEqual(nums, want) {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, nums)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, nums)
		}
	}

	// Examples from problem statement
	check([]int{1, 2, 3, 4, 5, 6, 7}, 3, []int{5, 6, 7, 1, 2, 3, 4}, "ex1: k=3")
	check([]int{-1, -100, 3, 99}, 2, []int{3, 99, -1, -100}, "ex2: k=2")

	// Edge cases
	check([]int{1}, 0, []int{1}, "single elem, k=0")
	check([]int{1, 2}, 1, []int{2, 1}, "two elems, k=1")
	check([]int{1, 2, 3}, 3, []int{1, 2, 3}, "k == n (full rotation)")
	check([]int{1, 2, 3, 4, 5}, 10, []int{1, 2, 3, 4, 5}, "k == 2*n")
	check([]int{1, 2, 3, 4, 5, 6}, 0, []int{1, 2, 3, 4, 5, 6}, "k == 0")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
