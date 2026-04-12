package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func lengthOfLongestSubstring(s string) int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want int, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// All problem examples + ≥2 edge cases
	check(lengthOfLongestSubstring("abcabcbb"), 3, "example1: abcabcbb")
	check(lengthOfLongestSubstring("bbbbb"),    1, "example2: bbbbb")
	check(lengthOfLongestSubstring("pwwkew"),   3, "example3: pwwkew")
	check(lengthOfLongestSubstring(""),          0, "edge: empty string")
	check(lengthOfLongestSubstring("a"),         1, "edge: single char")
	check(lengthOfLongestSubstring("abcde"),     5, "edge: all unique")
	check(lengthOfLongestSubstring("dvdf"),      3, "edge: dvdf")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
