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

func sortColors(nums []int) {
	// TODO: implement
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(nums, want []int, label string) {
		total++
		sortColors(nums)
		if reflect.DeepEqual(nums, want) {
			fmt.Printf(grn+"✓"+rst+"  %-40s →  %v\n", label, nums)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-40s"+rst+"    want=%v  got=%v\n", label, want, nums)
		}
	}

	// Examples
	check([]int{2, 0, 2, 1, 1, 0}, []int{0, 0, 1, 1, 2, 2}, "example1: [2,0,2,1,1,0]")
	check([]int{2, 0, 1},          []int{0, 1, 2},           "example2: [2,0,1]")

	// Edge cases
	check([]int{0},               []int{0},               "single 0")
	check([]int{1},               []int{1},               "single 1")
	check([]int{2},               []int{2},               "single 2")
	check([]int{2, 2, 2},         []int{2, 2, 2},         "all 2s")
	check([]int{0, 0, 0},         []int{0, 0, 0},         "all 0s")
	check([]int{1, 1, 1},         []int{1, 1, 1},         "all 1s")
	check([]int{2, 1, 0},         []int{0, 1, 2},         "reverse sorted")
	check([]int{0, 1, 2, 0, 1, 2}, []int{0, 0, 1, 1, 2, 2}, "interleaved")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
