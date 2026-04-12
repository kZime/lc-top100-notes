package main

import "fmt"

const (
	grn = "\033[32m"
	red = "\033[31m"
	bld = "\033[1m"
	rst = "\033[0m"
)

// ─── Solution ────────────────────────────────────────────────────────────────

type LRUCache struct {
	// TODO: add fields
}

func Constructor(capacity int) LRUCache {
	// TODO: implement
	return LRUCache{}
}

func (c *LRUCache) Get(key int) int {
	// TODO: implement
	return -1
}

func (c *LRUCache) Put(key, value int) {
	// TODO: implement
}

// ─── Test Harness ─────────────────────────────────────────────────────────────

func main() {
	passed, total := 0, 0

	check := func(got, want int, label string) {
		total++
		if got == want {
			fmt.Printf(grn+"✓"+rst+"  %-40s →  %d\n", label, got)
			passed++
		} else {
			fmt.Printf(red+"✗"+rst+"  "+bld+"%-40s"+rst+"    want=%d  got=%d\n", label, want, got)
		}
	}

	// Example 1 (from problem statement)
	{
		c := Constructor(2)
		c.Put(1, 1)
		c.Put(2, 2)
		check(c.Get(1), 1, "ex1: get(1)")
		c.Put(3, 3)
		check(c.Get(2), -1, "ex1: get(2) after eviction")
		c.Put(4, 4)
		check(c.Get(1), -1, "ex1: get(1) after eviction")
		check(c.Get(3), 3, "ex1: get(3)")
		check(c.Get(4), 4, "ex1: get(4)")
	}

	// Edge: capacity 1
	{
		c := Constructor(1)
		c.Put(1, 10)
		check(c.Get(1), 10, "cap1: get(1)=10")
		c.Put(2, 20)
		check(c.Get(1), -1, "cap1: get(1) evicted")
		check(c.Get(2), 20, "cap1: get(2)=20")
	}

	// Edge: update existing key
	{
		c := Constructor(2)
		c.Put(1, 1)
		c.Put(2, 2)
		c.Put(1, 10)
		c.Put(3, 3)
		check(c.Get(2), -1, "update: key 2 evicted")
		check(c.Get(1), 10, "update: key 1 = 10")
		check(c.Get(3), 3, "update: key 3 = 3")
	}

	// Edge: get promotes to MRU
	{
		c := Constructor(2)
		c.Put(1, 1)
		c.Put(2, 2)
		c.Get(1)
		c.Put(3, 3)
		check(c.Get(1), 1, "promote: key 1 survives")
		check(c.Get(2), -1, "promote: key 2 evicted")
	}

	fmt.Printf("\n%s\n", "--------------------------------------------")
	if passed == total {
		fmt.Printf(grn+"%d / %d passed\n"+rst, passed, total)
	} else {
		fmt.Printf(red+"%d / %d passed\n"+rst, passed, total)
	}
}
