# 118. Pascal's Triangle — 题解笔记

## 题意

给定 numRows，输出杨辉三角的前 numRows 行。每行两端为 1，中间位置等于上一行对应左右两个数之和。

## 核心算法

### 算法一：逐行构造（最优）

**思路**：从第 0 行 `[1]` 开始，每次根据上一行推出当前行：两端置 1，中间第 j 个元素 = `prev[j-1] + prev[j]`。结果直接收集到输出数组中。由于必须输出所有值，时间和空间均为 O(numRows²)，已是下界。

**时间**：O(numRows²)　**空间**：O(numRows²)（输出本身）

---

## 我的解法

### [solution.cpp](solution.cpp) — 算法一：逐行构造

**判断依据**：从 `res = {{1}}` 出发，每轮取 `pre = res.back()`，新行 `vec` 左右端隐式初始化为 0，通过 `if (j-1 >= 0) vec[j] += pre[j-1]; if (j < i) vec[j] += pre[j]` 叠加上一行的左右值——等价于 `c[i][j] = c[i-1][j-1] + c[i-1][j]`，逻辑正确，使用了 `emplace_back(move(vec))` 避免拷贝，实现清晰高效，已是最优解。

---

## 参考链接

https://leetcode.cn/problems/pascals-triangle/solutions/?envType=study-plan-v2&envId=top-100-liked
