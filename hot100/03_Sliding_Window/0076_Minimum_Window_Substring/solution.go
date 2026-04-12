package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func minWindow(s string, t string) string {
	// TODO: implement
	return ""
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want string, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %q\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%q  got=%q\n", label, want, got)
		}
	}

	// All problem examples + ≥2 edge cases
	check(minWindow("ADOBECODEBANC", "ABC"), "BANC", "example1: ADOBECODEBANC/ABC")
	check(minWindow("a",              "a"),  "a",    "example2: a/a")
	check(minWindow("a",              "aa"), "",     "example3: a/aa")
	check(minWindow("b",              "b"),  "b",    "edge: single match")
	check(minWindow("abc",            "cba"), "abc", "edge: full string")
	check(minWindow("xyzabc",         "abc"), "abc", "edge: suffix match")
	check(minWindow("AA",             "AA"), "AA",   "edge: duplicate required chars")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
