package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func decodeString(s string) string {
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

	// Examples
	check(decodeString("3[a]2[bc]"),     "aaabcbc",        "3[a]2[bc]")
	check(decodeString("3[a2[c]]"),      "accaccacc",      "3[a2[c]]")
	check(decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef", "2[abc]3[cd]ef")
	// Edge cases
	check(decodeString("a"),             "a",              "no encoding")
	check(decodeString("2[a]"),          "aa",             "2[a]")
	check(decodeString("10[a]"),         "aaaaaaaaaa",     "10[a] multi-digit k")
	check(decodeString("2[a3[b]]"),      "abbbabbb",       "2[a3[b]] nested")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
