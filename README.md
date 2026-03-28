# LeetCode Top 100 Liked — Progress

个人刷题记录，覆盖 [LeetCode Top 100 Liked](https://leetcode.com/studyplan/top-100-liked/) 题单。每道题包含题面、C++ / Go 双语解法和复盘笔记。

---

## 使用说明

### 环境要求

- C++17：`g++ -std=c++17`
- Go 1.18+：`go run`
- [Claude Code](https://claude.ai/code) CLI（使用 `/lc` 和 `/lc-review` skill）

### 如何复用本项目

1. Clone 仓库后，用 Claude Code 打开 `top100/` 目录。
2. `.claude/commands/` 下已内置两个 skill，Claude Code 会自动加载。
3. 按下方 skill 说明开始刷题即可。

若不使用 Claude Code，可参考 `CLAUDE.md` 手动创建题目文件夹，按模板编写 `problem.md` 和 `solution.cpp` / `solution.go`。

---

## Skill 说明

### `/lc <题号 或 slug>`

在 `top100/` 目录下运行，自动完成：

1. 从 LeetCode 拉取题目数据（描述、示例、约束、函数签名）
2. 创建 `NNNN_Problem_Title/` 文件夹
3. 生成 `problem.md`（题面）
4. 生成 `solution.cpp` 和 `solution.go`（含测试 harness，至少 5 个用例）

```
/lc 128
/lc longest-consecutive-sequence
```

### `/lc-review`

在**题目文件夹内**运行，完成做题复盘：

1. 读取 `problem.md` 和所有 `solution*.cpp` / `solution*.go`
2. 从 LeetCode CN 拉取高赞题解，提炼 2～3 种核心算法
3. 分析你的解法属于哪种算法、是否有改进空间
4. 生成 `notes.md` 复盘笔记
5. 将 README 中该题的 Status 列更新为 ☑

```bash
cd 0128_Longest_Consecutive_Sequence
/lc-review
```

---

状态：☑ 完成　⊙ 尝试中　☐ 未开始

**8 / 100**

---

## 1. Hashing

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 1 | [Two Sum](0001_Two_Sum/problem.md) | Easy | ☑ | [笔记](0001_Two_Sum/notes.md) |
| 49 | [Group Anagrams](0049_Group_Anagrams/problem.md) | Medium | ☑ | [笔记](0049_Group_Anagrams/notes.md) |
| 128 | [Longest Consecutive Sequence](0128_Longest_Consecutive_Sequence/problem.md) | Medium | ☑ | [笔记](0128_Longest_Consecutive_Sequence/notes.md) |
| 560 | [Subarray Sum Equals K](0560_Subarray_Sum_Equals_K/problem.md) | Medium | ☑ | [笔记](0560_Subarray_Sum_Equals_K/notes.md) |

## 2. Two Pointers

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 283 | [Move Zeroes](0283_Move_Zeroes/problem.md) | Easy | ☐ | |
| 11 | [Container With Most Water](0011_Container_With_Most_Water/problem.md) | Medium | ☑ | [笔记](0011_Container_With_Most_Water/notes.md) |
| 15 | [3Sum](0015_3Sum/problem.md) | Medium | ☑ | [笔记](0015_3Sum/notes.md) |
| 75 | [Sort Colors](0075_Sort_Colors/problem.md) | Medium | ☐ | |
| 42 | [Trapping Rain Water](0042_Trapping_Rain_Water/problem.md) | Hard | ☐ | |

## 3. Sliding Window

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 3 | [Longest Substring Without Repeating Characters](0003_Longest_Substring_Without_Repeating_Characters/problem.md) | Medium | ☐ | |
| 438 | [Find All Anagrams in a String](0438_Find_All_Anagrams_in_a_String/problem.md) | Medium | ☐ | |
| 76 | [Minimum Window Substring](0076_Minimum_Window_Substring/problem.md) | Hard | ☐ | |
| 239 | [Sliding Window Maximum](0239_Sliding_Window_Maximum/problem.md) | Hard | ☐ | |

## 4. Stack

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 20 | [Valid Parentheses](0020_Valid_Parentheses/problem.md) | Easy | ☐ | |
| 155 | [Min Stack](0155_Min_Stack/problem.md) | Medium | ☐ | |
| 394 | [Decode String](0394_Decode_String/problem.md) | Medium | ☐ | |
| 84 | [Largest Rectangle in Histogram](0084_Largest_Rectangle_in_Histogram/problem.md) | Hard | ☐ | |

## 5. Linked Lists

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 21 | [Merge Two Sorted Lists](0021_Merge_Two_Sorted_Lists/problem.md) | Easy | ☐ | |
| 141 | [Linked List Cycle](0141_Linked_List_Cycle/problem.md) | Easy | ☐ | |
| 160 | [Intersection of Two Linked Lists](0160_Intersection_of_Two_Linked_Lists/problem.md) | Easy | ☐ | |
| 206 | [Reverse Linked List](0206_Reverse_Linked_List/problem.md) | Easy | ☐ | |
| 234 | [Palindrome Linked List](0234_Palindrome_Linked_List/problem.md) | Easy | ☐ | |
| 2 | [Add Two Numbers](0002_Add_Two_Numbers/problem.md) | Medium | ☐ | |
| 19 | [Remove Nth Node From End of List](0019_Remove_Nth_Node_From_End_of_List/problem.md) | Medium | ☐ | |
| 24 | [Swap Nodes in Pairs](0024_Swap_Nodes_in_Pairs/problem.md) | Medium | ☐ | |
| 138 | [Copy List with Random Pointer](0138_Copy_List_with_Random_Pointer/problem.md) | Medium | ☐ | |
| 142 | [Linked List Cycle II](0142_Linked_List_Cycle_II/problem.md) | Medium | ☐ | |
| 146 | [LRU Cache](0146_LRU_Cache/problem.md) | Medium | ☐ | |
| 148 | [Sort List](0148_Sort_List/problem.md) | Medium | ☐ | |
| 23 | [Merge k Sorted Lists](0023_Merge_k_Sorted_Lists/problem.md) | Hard | ☐ | |
| 25 | [Reverse Nodes in k-Group](0025_Reverse_Nodes_in_k-Group/problem.md) | Hard | ☐ | |

## 6. Matrix

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 48 | [Rotate Image](0048_Rotate_Image/problem.md) | Medium | ☐ | |
| 54 | [Spiral Matrix](0054_Spiral_Matrix/problem.md) | Medium | ☐ | |
| 73 | [Set Matrix Zeroes](0073_Set_Matrix_Zeroes/problem.md) | Medium | ☐ | |
| 240 | [Search a 2D Matrix II](0240_Search_a_2D_Matrix_II/problem.md) | Medium | ☐ | |

## 7. Binary Search

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 35 | [Search Insert Position](0035_Search_Insert_Position/problem.md) | Easy | ☐ | |
| 33 | [Search in Rotated Sorted Array](0033_Search_in_Rotated_Sorted_Array/problem.md) | Medium | ☐ | |
| 34 | [Find First and Last Position of Element in Sorted Array](0034_Find_First_and_Last_Position_of_Element_in_Sorted_Array/problem.md) | Medium | ☐ | |
| 74 | [Search a 2D Matrix](0074_Search_a_2D_Matrix/problem.md) | Medium | ☐ | |
| 153 | [Find Minimum in Rotated Sorted Array](0153_Find_Minimum_in_Rotated_Sorted_Array/problem.md) | Medium | ☐ | |
| 4 | [Median of Two Sorted Arrays](0004_Median_of_Two_Sorted_Arrays/problem.md) | Hard | ☐ | |

## 8. Heap

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 215 | [Kth Largest Element in an Array](0215_Kth_Largest_Element_in_an_Array/problem.md) | Medium | ☐ | |
| 347 | [Top K Frequent Elements](0347_Top_K_Frequent_Elements/problem.md) | Medium | ☐ | |
| 295 | [Find Median from Data Stream](0295_Find_Median_from_Data_Stream/problem.md) | Hard | ☐ | |

## 9. Binary Tree

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 94 | [Binary Tree Inorder Traversal](0094_Binary_Tree_Inorder_Traversal/problem.md) | Easy | ☐ | |
| 101 | [Symmetric Tree](0101_Symmetric_Tree/problem.md) | Easy | ☐ | |
| 104 | [Maximum Depth of Binary Tree](0104_Maximum_Depth_of_Binary_Tree/problem.md) | Easy | ☐ | |
| 108 | [Convert Sorted Array to Binary Search Tree](0108_Convert_Sorted_Array_to_Binary_Search_Tree/problem.md) | Easy | ☐ | |
| 226 | [Invert Binary Tree](0226_Invert_Binary_Tree/problem.md) | Easy | ☐ | |
| 543 | [Diameter of Binary Tree](0543_Diameter_of_Binary_Tree/problem.md) | Easy | ☐ | |
| 98 | [Validate Binary Search Tree](0098_Validate_Binary_Search_Tree/problem.md) | Medium | ☐ | |
| 102 | [Binary Tree Level Order Traversal](0102_Binary_Tree_Level_Order_Traversal/problem.md) | Medium | ☐ | |
| 105 | [Construct Binary Tree from Preorder and Inorder Traversal](0105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal/problem.md) | Medium | ☐ | |
| 114 | [Flatten Binary Tree to Linked List](0114_Flatten_Binary_Tree_to_Linked_List/problem.md) | Medium | ☐ | |
| 199 | [Binary Tree Right Side View](0199_Binary_Tree_Right_Side_View/problem.md) | Medium | ☐ | |
| 230 | [Kth Smallest Element in a BST](0230_Kth_Smallest_Element_in_a_BST/problem.md) | Medium | ☐ | |
| 236 | [Lowest Common Ancestor of a Binary Tree](0236_Lowest_Common_Ancestor_of_a_Binary_Tree/problem.md) | Medium | ☐ | |
| 437 | [Path Sum III](0437_Path_Sum_III/problem.md) | Medium | ☐ | |
| 124 | [Binary Tree Maximum Path Sum](0124_Binary_Tree_Maximum_Path_Sum/problem.md) | Hard | ☐ | |

## 10. Graph

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 200 | [Number of Islands](0200_Number_of_Islands/problem.md) | Medium | ☐ | |
| 207 | [Course Schedule](0207_Course_Schedule/problem.md) | Medium | ☐ | |
| 994 | [Rotting Oranges](0994_Rotting_Oranges/problem.md) | Medium | ☐ | |

## 11. Greedy

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 121 | [Best Time to Buy and Sell Stock](0121_Best_Time_to_Buy_and_Sell_Stock/problem.md) | Easy | ☐ | |
| 45 | [Jump Game II](0045_Jump_Game_II/problem.md) | Medium | ☐ | |
| 55 | [Jump Game](0055_Jump_Game/problem.md) | Medium | ☐ | |
| 56 | [Merge Intervals](0056_Merge_Intervals/problem.md) | Medium | ☐ | |
| 763 | [Partition Labels](0763_Partition_Labels/problem.md) | Medium | ☐ | |

## 12. Backtracking

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 17 | [Letter Combinations of a Phone Number](0017_Letter_Combinations_of_a_Phone_Number/problem.md) | Medium | ☐ | |
| 22 | [Generate Parentheses](0022_Generate_Parentheses/problem.md) | Medium | ☐ | |
| 39 | [Combination Sum](0039_Combination_Sum/problem.md) | Medium | ☐ | |
| 46 | [Permutations](0046_Permutations/problem.md) | Medium | ☐ | |
| 78 | [Subsets](0078_Subsets/problem.md) | Medium | ☐ | |
| 79 | [Word Search](0079_Word_Search/problem.md) | Medium | ☐ | |
| 131 | [Palindrome Partitioning](0131_Palindrome_Partitioning/problem.md) | Medium | ☐ | |
| 51 | [N-Queens](0051_N-Queens/problem.md) | Hard | ☐ | |

## 13. Dynamic Programming

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 70 | [Climbing Stairs](0070_Climbing_Stairs/problem.md) | Easy | ☐ | |
| 118 | [Pascal's Triangle](0118_Pascals_Triangle/problem.md) | Easy | ☐ | |
| 5 | [Longest Palindromic Substring](0005_Longest_Palindromic_Substring/problem.md) | Medium | ☐ | |
| 62 | [Unique Paths](0062_Unique_Paths/problem.md) | Medium | ☐ | |
| 64 | [Minimum Path Sum](0064_Minimum_Path_Sum/problem.md) | Medium | ☐ | |
| 72 | [Edit Distance](0072_Edit_Distance/problem.md) | Medium | ☐ | |
| 139 | [Word Break](0139_Word_Break/problem.md) | Medium | ☐ | |
| 152 | [Maximum Product Subarray](0152_Maximum_Product_Subarray/problem.md) | Medium | ☐ | |
| 198 | [House Robber](0198_House_Robber/problem.md) | Medium | ☐ | |
| 279 | [Perfect Squares](0279_Perfect_Squares/problem.md) | Medium | ☐ | |
| 300 | [Longest Increasing Subsequence](0300_Longest_Increasing_Subsequence/problem.md) | Medium | ☐ | |
| 322 | [Coin Change](0322_Coin_Change/problem.md) | Medium | ☐ | |
| 416 | [Partition Equal Subset Sum](0416_Partition_Equal_Subset_Sum/problem.md) | Medium | ☐ | |
| 1143 | [Longest Common Subsequence](1143_Longest_Common_Subsequence/problem.md) | Medium | ☐ | |
| 32 | [Longest Valid Parentheses](0032_Longest_Valid_Parentheses/problem.md) | Hard | ☐ | |

## 14. Trie + Misc

| # | Title | Difficulty | Status | Notes |
|---|-------|-----------|:------:|-------|
| 136 | [Single Number](0136_Single_Number/problem.md) | Easy | ☐ | |
| 169 | [Majority Element](0169_Majority_Element/problem.md) | Easy | ☐ | |
| 31 | [Next Permutation](0031_Next_Permutation/problem.md) | Medium | ☑ | [笔记](0031_Next_Permutation/notes.md) |
| 53 | [Maximum Subarray](0053_Maximum_Subarray/problem.md) | Medium | ☐ | |
| 189 | [Rotate Array](0189_Rotate_Array/problem.md) | Medium | ☑ | [笔记](0189_Rotate_Array/notes.md) |
| 208 | [Implement Trie (Prefix Tree)](0208_Implement_Trie/problem.md) | Medium | ☐ | |
| 238 | [Product of Array Except Self](0238_Product_of_Array_Except_Self/problem.md) | Medium | ☐ | |
| 287 | [Find the Duplicate Number](0287_Find_the_Duplicate_Number/problem.md) | Medium | ☐ | |
| 41 | [First Missing Positive](0041_First_Missing_Positive/problem.md) | Hard | ☐ | |
