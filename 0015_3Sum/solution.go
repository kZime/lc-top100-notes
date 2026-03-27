package main

import (
	"fmt"
	"sort"
)

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func threeSum(nums []int) [][]int {
	// TODO: implement
	return nil
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func eqTriples(a, b [][]int) bool {
	norm := func(s [][]int) [][]int {
		cp := make([][]int, len(s))
		for i, row := range s {
			r := append([]int(nil), row...)
			sort.Ints(r)
			cp[i] = r
		}
		sort.Slice(cp, func(i, j int) bool {
			for k := 0; k < len(cp[i]) && k < len(cp[j]); k++ {
				if cp[i][k] != cp[j][k] {
					return cp[i][k] < cp[j][k]
				}
			}
			return len(cp[i]) < len(cp[j])
		})
		return cp
	}
	na, nb := norm(a), norm(b)
	if len(na) != len(nb) {
		return false
	}
	for i := range na {
		if len(na[i]) != len(nb[i]) {
			return false
		}
		for j := range na[i] {
			if na[i][j] != nb[i][j] {
				return false
			}
		}
	}
	return true
}

func main() {
	passed, total := 0, 0

	check := func(nums []int, want [][]int, label string) {
		total++
		got := threeSum(nums)
		if eqTriples(got, want) {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	check([]int{-1, 0, 1, 2, -1, -4}, [][]int{{-1, -1, 2}, {-1, 0, 1}}, "example1")
	check([]int{0, 1, 1}, [][]int{}, "example2: no triplet")
	check([]int{0, 0, 0}, [][]int{{0, 0, 0}}, "example3: all zeros")
	check([]int{-2, 0, 1, 1, 2}, [][]int{{-2, 0, 2}, {-2, 1, 1}}, "two triplets")
	check([]int{-4, -1, -1, 0, 1, 2}, [][]int{{-1, -1, 2}, {-1, 0, 1}}, "duplicates in input")
	check([]int{1, 2, -2, -1}, [][]int{}, "no valid triplet")
	check([]int{0, 0, 0, 0}, [][]int{{0, 0, 0}}, "multiple zeros")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
