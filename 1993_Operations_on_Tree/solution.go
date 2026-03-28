package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

type LockingTree struct {
	parent   []int
	children [][]int
	locked   []int // locked[i] = user id (0 = unlocked)
}

func Constructor(parent []int) LockingTree {
	// TODO: implement
	return LockingTree{}
}

func (t *LockingTree) Lock(num int, user int) bool {
	// TODO: implement
	return false
}

func (t *LockingTree) Unlock(num int, user int) bool {
	// TODO: implement
	return false
}

func (t *LockingTree) Upgrade(num int, user int) bool {
	// TODO: implement
	return false
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want bool, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-40s →  %v\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-40s"+rst+"    want=%v  got=%v\n", label, want, got)
		}
	}

	// Example 1: [-1, 0, 0, 1, 1, 2, 2]
	{
		t := Constructor([]int{-1, 0, 0, 1, 1, 2, 2})
		check(t.Lock(2, 2),    true,  "ex1: lock(2,2)")
		check(t.Unlock(2, 3),  false, "ex1: unlock(2,3) wrong user")
		check(t.Unlock(2, 2),  true,  "ex1: unlock(2,2)")
		check(t.Lock(4, 5),    true,  "ex1: lock(4,5)")
		check(t.Upgrade(0, 1), true,  "ex1: upgrade(0,1)")
		check(t.Lock(0, 1),    false, "ex1: lock(0,1) already locked")
	}

	// Edge: lock already-locked node
	{
		t := Constructor([]int{-1, 0, 1})
		check(t.Lock(1, 1), true,  "edge: lock(1,1) first time")
		check(t.Lock(1, 2), false, "edge: lock(1,2) already locked")
	}

	// Edge: upgrade fails — node already locked
	{
		t := Constructor([]int{-1, 0, 1})
		t.Lock(0, 1)
		t.Lock(2, 2)
		check(t.Upgrade(0, 3), false, "edge: upgrade fails — root already locked")
	}

	// Edge: upgrade fails — no locked descendants
	{
		t := Constructor([]int{-1, 0, 1})
		check(t.Upgrade(0, 1), false, "edge: upgrade fails — no locked desc")
	}

	// Edge: upgrade fails — locked ancestor
	{
		t := Constructor([]int{-1, 0, 1})
		t.Lock(0, 1)
		t.Lock(2, 2)
		check(t.Upgrade(1, 3), false, "edge: upgrade fails — ancestor locked")
	}

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
