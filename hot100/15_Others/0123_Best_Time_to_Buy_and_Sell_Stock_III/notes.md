# 123. Best Time to Buy and Sell Stock III — 题解笔记

## 题意

给定每日股价数组，至多完成**两笔**交易（不能同时持有两股），求最大总利润。

## 核心算法

### 算法一：O(n) DP，5 状态

**思路**：将每天的状态拆为 5 类：无操作、第一次持股、第一次空仓（已完成1笔）、第二次持股、第二次空仓（已完成2笔）。对每个状态写出转移方程（今天不动 or 今天操作），逐日递推。最终答案取"第一次空仓"和"第二次空仓"中的最大值。

**时间**：O(n)　**空间**：O(n)（可压缩为 O(1)）

### 算法二：O(n) 前缀 + 后缀 DP

**思路**：`dp_pre[i]` 表示 `[0..i]` 范围内单笔交易的最大利润，`dp_suf[i]` 表示 `[i..n-1]` 范围内单笔交易的最大利润。枚举分割点，答案为 `max(dp_pre[i] + dp_suf[i])`。相当于把两笔交易分布在 `[0..i]` 和 `[i..n-1]` 两段各做一次。

**时间**：O(n)　**空间**：O(n)

### 算法三：O(1) 空间 4 变量状态机（最优）

**思路**：用 4 个变量 `buy1, sell1, buy2, sell2` 滚动模拟两次买卖的最优状态。一次遍历：`buy1 = max(buy1, -price[i])`，`sell1 = max(sell1, buy1+price[i])`，`buy2 = max(buy2, sell1-price[i])`，`sell2 = max(sell2, buy2+price[i])`。本质是把 5 状态 DP 的空间压缩到常数。

**时间**：O(n)　**空间**：O(1)

---

## 我的解法

### [solution.cpp](solution.cpp) — 算法二：前缀 + 后缀 DP

**判断依据**：代码维护 `dp_pre`（前向最小价格追踪）和 `dp_suf`（后向最大价格追踪），最后枚举分割点取最大，与算法二完全吻合。

**可改进点**：
1. **空间**：O(n) → 可改用 4 变量状态机降到 O(1)，同时去掉两趟扫描。
2. **冗余赋值**：`dp_pre[i] = dp_pre[i-1]` 和 `dp_suf[i] = dp_suf[i+1]` 两行立即被下一行覆盖，可直接删去。

---

## 我的解法（solution1.cpp）— 算法三：O(1) 空间 4 变量状态机

**判断依据**：代码用 `buy1 / sell1 / buy2 / sell2` 四个变量单次遍历，转移方程与算法三完全一致，空间压缩到常数。

**复杂度**：O(n) 时间，O(1) 空间——已为最优，无改进点。

> 注：`return max(sell1, sell2)` 等价于直接 `return sell2`（允许空操作时 sell2 ≥ sell1 恒成立），写法无误。

---

## 参考链接

https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solutions/?envType=study-plan-v2&envId=top-100-liked
