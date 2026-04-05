# 49. Group Anagrams

**Difficulty:** Medium
**Link:** https://leetcode.com/problems/group-anagrams/

---

## Description

Given an array of strings `strs`, group the anagrams together. You can return the answer in **any order**.

---

## Examples

**Example 1:**
```
Input:  strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
  - "bat" cannot be rearranged to form any other string in strs.
  - "nat" and "tan" are anagrams of each other.
  - "ate", "eat", and "tea" are anagrams of each other.
```

**Example 2:**
```
Input:  strs = [""]
Output: [[""]]
```

**Example 3:**
```
Input:  strs = ["a"]
Output: [["a"]]
```

---

## Constraints

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.
