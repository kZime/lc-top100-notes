package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

func countDigitOne(n int) int {
	// TODO: implement
	return 0
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want int, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-36s →  %d\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-36s"+rst+"    want=%d  got=%d\n", label, want, got)
		}
	}

	check(countDigitOne(13), 6, "example1: n=13")
	check(countDigitOne(0), 0, "example2: n=0")
	check(countDigitOne(1), 1, "single one")
	check(countDigitOne(10), 2, "crossing ten")
	check(countDigitOne(99), 20, "double digits all range")
	check(countDigitOne(100), 21, "exact power of ten")

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
