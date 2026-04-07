# 121. Best Time to Buy and Sell Stock — 题解笔记

## 题意

给定股票每日价格数组，只能**一次**买入+卖出，求最大利润；买必须在卖之前，无法盈利则返回 0。

## 核心算法

### 算法一：暴力枚举
**思路**：双重循环枚举所有 (i, j) 对（i < j），计算 `prices[j] - prices[i]`，取最大值。
**时间**：O(n²)　**空间**：O(1)

### 算法二：一次遍历贪心（最优）
**思路**：遍历数组，维护"已见最低价格 `min_price`"；对每个价格，计算"当天卖出的利润"并更新答案，同时更新最低价格。核心贪心：若要在第 i 天卖出获得最大利润，买入点必然是 i 之前的最低价格。整个过程一次扫描即可完成。
**时间**：O(n)　**空间**：O(1)

---

## 我的解法

### [solution.cpp](solution.cpp) — 算法二：一次遍历贪心
**判断依据**：维护 `pre_min` 记录历史最低价，每次先尝试更新 `ans = max(ans, prices[i] - pre_min)`，再更新 `pre_min = min(pre_min, prices[i])`，与最优贪心方案完全一致。
**可改进点**：无，已是最优方案（O(n) 时间，O(1) 空间）。

---

## 参考链接

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/?envType=study-plan-v2&envId=top-100-liked
