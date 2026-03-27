# 31. Next Permutation — 题解笔记

## 题意

给定一个整数数组，将其原地重排成字典序上的**下一个排列**；若当前已是最大排列（完全降序），则重排为最小排列（升序）。要求 O(1) 额外空间。

---

## 核心算法

### 算法一：两遍扫描（标准手写实现）

**思路**：从右向左找到第一个「下降点」i（满足 `nums[i] < nums[i+1]`）；再从右向左在后缀 `[i+1, n)` 中找到第一个比 `nums[i]` 大的元素 j，交换 `nums[i]` 与 `nums[j]`；最后将后缀 `[i+1, n)` 反转为升序。若找不到下降点，说明整体降序，直接反转全数组。

关键洞察：交换后后缀必然仍是降序（因为 j 是从右往左找到的第一个大于 `nums[i]` 的位置），所以反转比排序更高效。

**时间**：O(N)　**空间**：O(1)

### 算法二：调用标准库

**思路**：直接调用 C++ STL 的 `std::next_permutation`，底层实现与算法一完全一致，但屏蔽了实现细节。Go 标准库无此函数，需手写。

**时间**：O(N)　**空间**：O(1)

---

## 我的解法

**使用算法**：算法二 — 调用标准库 `std::next_permutation`

**判断依据**：C++ 解法函数体只有一行 `next_permutation(nums.begin(), nums.end())`，直接委托 STL。

**可改进点**：
1. **面试场景不可用**：面试官几乎必然要求手写实现。应掌握算法一的三步逻辑：找下降点 → 找右侧最小的比它大的数 → 交换 + 反转后缀。
2. **Go 版本未实现**：`solution.go` 仍是 TODO，缺少手写练习的机会。建议用算法一补全 Go 实现。

第二次， 使用算法 1，
```c++
   void nextPermutation(vector<int>& nums) {

        // 1. find increase list from back
        vector<int> bk(1, nums.back());
        int x = -1;
        nums.pop_back();

        while (!nums.empty()) {
            if (nums.back() >= bk.back()) {
                bk.push_back(nums.back());
                nums.pop_back();
            } else {
                x = nums.back();
                nums.pop_back();
                break;
            }
        }

        if (x == -1) {
            // all in bk, eg. [5,4,3,2,1]
            for (auto b : bk)
                nums.push_back(b);
            return;
        }

        int idx = upper_bound(bk.begin(), bk.end(), x) - bk.begin();

        if (idx != bk.size());
            swap(bk[idx], x);

        nums.push_back(x);
        for (auto b : bk)
            nums.push_back(b);
    }


```

方式和算法一一样，并且加上了二分查找 `upper_bound` 来找到第一个比 x 大的数，效率更高。
但是注意边界条件，而且没有注意到，有的测试点是有重复元素的，要。

问题：
1. 使用`bk` 来存储后缀，空间复杂度 O(N)，不满足题目要求的 O(1) 额外空间。应直接在原数组上操作。
2. 


---

## 参考链接

https://leetcode.cn/problems/next-permutation/solutions/?envType=study-plan-v2&envId=top-100-liked
