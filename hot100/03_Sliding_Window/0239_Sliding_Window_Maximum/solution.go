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

func maxSlidingWindow(nums []int, k int) []int {
	// TODO: implement
	return nil
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(nums []int, k int, want []int, label string) {
		total++
		got := maxSlidingWindow(nums, k)
		if reflect.DeepEqual(got, want) {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// All problem examples + ≥2 edge cases
	check([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3, []int{3, 3, 5, 5, 6, 7}, "example1: k=3")
	check([]int{1},                          1, []int{1},                "example2: single element")
	check([]int{1, -1},                      1, []int{1, -1},            "edge: k=1 two elements")
	check([]int{7, 2, 4},                    2, []int{7, 4},             "edge: k=2 decreasing")
	check([]int{-7, -8, 7, 5, 7, 1, 6, 0}, 4, []int{7, 7, 7, 7, 7},   "edge: negative values")
	check([]int{4, 3, 2, 1},                 2, []int{4, 3, 2},          "edge: descending")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
