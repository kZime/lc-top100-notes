package main

import "fmt"

// ─── Solution ────────────────────────────────────────────────────────────────

func search(nums []int, target int) int {
	// TODO: implement
	return -1
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(nums []int, target int, want int, label string) {
		total++
		got := search(nums, target)
		if got == want {
			fmt.Printf("%s: PASS\n", label)
			passed++
		} else {
			fmt.Printf("%s: FAIL  want=%d got=%d\n", label, want, got)
		}
	}

	// Examples from problem statement
	check([]int{4, 5, 6, 7, 0, 1, 2}, 0, 4, "ex1: target in rotated array")
	check([]int{4, 5, 6, 7, 0, 1, 2}, 3, -1, "ex2: target not in rotated array")
	check([]int{1}, 0, -1, "ex3: single element, target absent")

	// Edge cases
	check([]int{1}, 1, 0, "edge1: single element, target present")
	check([]int{3, 1}, 1, 1, "edge2: two elements, target is second")
	check([]int{3, 1}, 3, 0, "edge3: two elements, target is first")
	check([]int{1, 2, 3, 4, 5, 6, 7}, 5, 4, "edge4: not rotated, target present")
	check([]int{5, 6, 7, 1, 2, 3, 4}, 7, 2, "edge5: rotated, target in left half")

	fmt.Printf("\n%d/%d passed\n", passed, total)
}
