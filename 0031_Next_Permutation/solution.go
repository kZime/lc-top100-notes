package main

import "fmt"

// ─── Solution ────────────────────────────────────────────────────────────────

func nextPermutation(nums []int) {
	// TODO: implement
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func sliceEq(a, b []int) bool {
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
		nextPermutation(nums)
		if sliceEq(nums, want) {
			fmt.Printf("%s: PASS\n", label)
			passed++
		} else {
			fmt.Printf("%s: FAIL  want=%v got=%v\n", label, want, nums)
		}
	}

	// Example cases
	check([]int{1, 2, 3}, []int{1, 3, 2}, "ex1: [1,2,3]")
	check([]int{3, 2, 1}, []int{1, 2, 3}, "ex2: [3,2,1] -> wrap")
	check([]int{1, 1, 5}, []int{1, 5, 1}, "ex3: [1,1,5]")

	// Edge cases
	check([]int{1}, []int{1}, "edge: single element")
	check([]int{1, 2}, []int{2, 1}, "edge: two elements ascending")
	check([]int{2, 1}, []int{1, 2}, "edge: two elements descending")
	check([]int{1, 3, 2}, []int{2, 1, 3}, "misc: [1,3,2]")
	check([]int{2, 3, 1}, []int{3, 1, 2}, "misc: [2,3,1]")

	fmt.Printf("\n%d/%d passed\n", passed, total)
}
