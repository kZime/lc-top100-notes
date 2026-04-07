# 1993. Operations on Tree

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/operations-on-tree/

> ⚠️ 题面来自内置知识，非实时抓取，请核对题目后再开始。

---

## Description

You are given a tree with `n` nodes numbered from `0` to `n - 1` in the form of a parent array `parent` where `parent[i]` is the parent of the `i`th node. The root of the tree is node `0`, so `parent[0] = -1` since it has no parent.

Each node has a lock status, initially all unlocked. Implement the `LockingTree` class:

- **`LockingTree(int[] parent)`** — Initializes the data structure with the parent array.
- **`bool lock(int num, int user)`** — Locks node `num` for user `user` if the node is **currently not locked**. Returns `true` if successful, `false` otherwise.
- **`bool unlock(int num, int user)`** — Unlocks node `num` if it is **currently locked by `user`**. Returns `true` if successful, `false` otherwise.
- **`bool upgrade(int num, int user)`** — Upgrades node `num` for user `user`. Returns `true` and performs the operation if **all three** conditions hold:
  1. Node `num` is currently **not locked**.
  2. There is **at least one locked descendant** of node `num`.
  3. Node `num` does **not have any locked ancestors**.

  When upgrading: lock node `num` for `user`, and **unlock all locked descendants** of node `num`.

---

## Examples

**Example 1:**

```
Input:
["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"]
[[-1, 0, 0, 1, 1, 2, 2], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]

Output: [null, true, false, true, true, true, false]

Explanation:
LockingTree lockingTree = new LockingTree([-1, 0, 0, 1, 1, 2, 2]);
lockingTree.lock(2, 2);    // true.  Node 2 locked by user 2.
lockingTree.unlock(2, 3);  // false. Node 2 is locked by user 2, not user 3.
lockingTree.unlock(2, 2);  // true.  Node 2 unlocked.
lockingTree.lock(4, 5);    // true.  Node 4 locked by user 5.
lockingTree.upgrade(0, 1); // true.  Node 0 locked by user 1; node 4 unlocked.
lockingTree.lock(0, 1);    // false. Node 0 is already locked by user 1.
```

---

## Constraints

- `n == parent.length`
- `2 <= n <= 2000`
- `0 <= parent[i] <= n - 1` for `i != 0`
- `parent[0] == -1`
- `0 <= num <= n - 1`
- `1 <= user <= 10^4`
- `parent` represents a valid tree.
- At most `2000` calls will be made to `lock`, `unlock`, and `upgrade`.
