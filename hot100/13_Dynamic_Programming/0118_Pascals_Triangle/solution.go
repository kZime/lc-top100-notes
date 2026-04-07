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

func generate(numRows int) [][]int {
	// TODO: implement
	return nil
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(numRows int, want [][]int, label string) {
		total++
		got := generate(numRows)
		if reflect.DeepEqual(got, want) {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// Examples
	check(5, [][]int{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}, "numRows=5")
	check(1, [][]int{{1}}, "numRows=1")

	// Edge cases
	check(2, [][]int{{1}, {1, 1}},                   "numRows=2")
	check(3, [][]int{{1}, {1, 1}, {1, 2, 1}},        "numRows=3")
	check(4, [][]int{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}}, "numRows=4")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
