# 198. House Robber — 题解笔记

## 题意

一排房子各有金额，不能连续偷相邻两间，求能偷到的最大金额。经典"不相邻选最大和"DP 入门题。

## 核心算法

### 算法一：动态规划（O(n) 空间）

**思路**：定义 `dp[i]` 为偷前 i 间房子能得到的最大金额，状态转移 `dp[i] = max(dp[i-1], dp[i-2] + nums[i])`，边界 `dp[0]=nums[0]`，`dp[1]=max(nums[0],nums[1])`。用整个数组存储所有子问题答案。

**时间**：O(n)　**空间**：O(n)

### 算法二：双变量滚动 DP（最优）

**思路**：注意到 `dp[i]` 只依赖 `dp[i-1]` 和 `dp[i-2]`，因此可用两个变量 `prev2, prev1` 滚动替代整个数组。每步 `cur = max(prev1, prev2 + nums[i])`，然后 `prev2=prev1, prev1=cur`，最终返回 `prev1`。

**时间**：O(n)　**空间**：O(1)

---

## 我的解法

### [solution.cpp](solution.cpp) — 算法一：O(n) 空间 DP

**判断依据**：使用了 `vector<int> dp(n)` 完整数组，转移式 `dp[i] = max(dp[i-1], dp[i-2] + nums[i])` 与算法一完全一致。

**代码中的疑问解答**：注释 `// why can I use only one dimension of dp ??` 说明你注意到了这里只用了一维而非二维——这是因为子问题定义本身就是一维的（"前 i 间房子的最大收益"），不涉及第二个维度，所以天然就是一维 DP。

**可改进点**：`dp[i]` 只依赖前两项，可将 `vector<int> dp(n)` 替换为两个变量滚动，空间从 O(n) 降至 O(1)——这就是你注释中隐含的那个问题的答案：正因为只依赖前两项，才能进一步压缩为 O(1) 空间。

### [solution1.cpp](solution1.cpp) — 算法二：滚动数组 O(1) 空间 DP

**判断依据**：用 `array<int,3>` 以 `i%3` 为索引滚动，`dp[i%3] = max(dp[(i-1+3)%3], dp[(i-2+3)%3] + nums[i])`，与算法二复杂度一致，O(n) 时间 O(1) 空间。边界处理巧妙：数组零初始化后，i=0 时 `dp[(i-2+3)%3]` 和 `dp[(i-1+3)%3]` 均为 0，恰好对应"前 -2 间"和"前 -1 间"收益为 0 的边界条件，无需单独处理。已达最优解。

---

## 参考链接

https://leetcode.cn/problems/house-robber/solutions/?envType=study-plan-v2&envId=top-100-liked
