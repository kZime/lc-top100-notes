package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func isValid(s string) bool {
	// TODO: implement
	return false
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want bool, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// Examples
	check(isValid("()"),     true,  `"()"`)
	check(isValid("()[]{}"), true,  `"()[]{}"`)
	check(isValid("(]"),     false, `"(]"`)
	check(isValid("([])"),   true,  `"([])"`)
	check(isValid("([)]"),   false, `"([)]"`)
	// Edge cases
	check(isValid("{[]}"),   true,  `"{[]}" nested`)
	check(isValid("("),      false, `"(" unclosed`)
	check(isValid(")"),      false, `")" extra close`)

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
