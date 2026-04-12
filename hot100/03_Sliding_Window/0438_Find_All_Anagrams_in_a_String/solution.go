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

func findAnagrams(s string, p string) []int {
	// TODO: implement
	return nil
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want []int, label string) {
		total++
		if reflect.DeepEqual(got, want) {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// All problem examples + ≥2 edge cases
	check(findAnagrams("cbaebabacd", "abc"), []int{0, 6},    "example1: cbaebabacd/abc")
	check(findAnagrams("abab",        "ab"),  []int{0, 1, 2}, "example2: abab/ab")
	check(findAnagrams("a",           "ab"),  []int{},        "edge: s shorter than p")
	check(findAnagrams("baa",          "aa"), []int{1},       "edge: baa/aa")
	check(findAnagrams("aa",           "aa"), []int{0},       "edge: exact match")
	check(findAnagrams("abcdef",       "xyz"), []int{},       "edge: no anagram")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
