# 3. 无重复字符的最长子串 — 题解笔记

## 题意

给定字符串 s，找出其中不含重复字符的最长子串的长度。本质是在连续子串上维护"无重复"约束，找最大窗口。

## 核心算法

### 算法一：暴力枚举
**思路**：枚举所有起点 i 和终点 j，用 set 验证 s[i..j] 内无重复字符，记录最大长度。
**时间**：O(n²)　**空间**：O(min(m, n))（m 为字符集大小）

### 算法二：滑动窗口 + 集合
**思路**：双指针 l/r，集合记录窗口内字符。r 右移时若 s[r] 已在集合中，从 l 收缩直到集合中不含 s[r]，再插入 s[r]；每步更新最大长度。每个字符至多被加入/移除一次，均摊 O(n)。
**时间**：O(n)　**空间**：O(min(m, n))

### 算法三：滑动窗口 + 哈希表记录索引（最优）
**思路**：用 `unordered_map<char, int>` 记录每个字符上次出现的下标。r 右移时若 s[r] 已在窗口内，直接将 l 跳到 `lastSeen[s[r]] + 1`，无需内层 while 循环，单次扫描。实现更简洁且常数更小。
**时间**：O(n)　**空间**：O(min(m, n))

---

## 我的解法

### [solution.cpp](solution.cpp) — 算法二：滑动窗口 + 集合
**判断依据**：使用 `unordered_set<char>` 记录窗口字符，r 右移时若遇重复则用内层 while 从 l 逐个收缩，与算法二完全吻合。
**可改进点**：可用 `unordered_map<char, int>` 记录字符最后出现位置，遇重复时直接令 `l = lastSeen[s[r]] + 1`，省去内层 while，代码更简洁（渐近复杂度相同，但去掉了冗余操作）。

### [solution2.cpp](solution2.cpp) — 算法三：滑动窗口 + 哈希表记录索引
**判断依据**：使用 `unordered_map<char, int> vis` 记录每个字符上次出现的下标。r 右移时，若 `vis[s[r]] >= l`（说明重复字符仍在窗口内），直接令 `l = vis[s[r]] + 1` 一步跳过；无论是否重复均更新 `vis[s[r]] = r`，最后 `r - l + 1` 即为当前窗口长度。单次扫描，无内层循环，与算法三完全一致。  
复杂度 O(n) / O(min(m, n))，已达最优，无改进点。

---

## 参考链接

https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/?envType=study-plan-v2&envId=top-100-liked
