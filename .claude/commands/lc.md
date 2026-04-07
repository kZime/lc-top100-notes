Set up a LeetCode problem workspace. Argument: $ARGUMENTS (problem number, e.g. `128`, or URL slug).

## 步骤一：解析 slug

若 $ARGUMENTS 是数字，grep README.md 找到该题行，从链接路径提取文件夹名推断 slug（链接格式为 `hot100/NN_Category/NNNN_Folder/problem.md`，取最后一个路径段推断 slug，如 `0128_Longest_Consecutive_Sequence` → `longest-consecutive-sequence`）。若已是 slug，直接使用。

## 步骤二：拉取题目数据

```bash
bash .claude/scripts/lc_fetch.sh SLUG
```

输出 JSON：`{id, title, difficulty, content（纯文本）, metaData（含函数签名 JSON）}`。
若脚本返回 error，基于内置知识构建文件并告知用户。

## 步骤三：确定分类目录 & 创建文件夹

从 README.md 中找到该题所在章节（如 `## 2. Two Pointers`），映射到对应分类子目录：

| 章节 | 子目录 |
|------|--------|
| 1. Hashing | `01_Hashing` |
| 2. Two Pointers | `02_Two_Pointers` |
| 3. Sliding Window | `03_Sliding_Window` |
| 4. Stack | `04_Stack` |
| 5. Linked Lists | `05_Linked_Lists` |
| 6. Matrix | `06_Matrix` |
| 7. Binary Search | `07_Binary_Search` |
| 8. Heap | `08_Heap` |
| 9. Binary Tree | `09_Binary_Tree` |
| 10. Graph | `10_Graph` |
| 11. Greedy | `11_Greedy` |
| 12. Backtracking | `12_Backtracking` |
| 13. Dynamic Programming | `13_Dynamic_Programming` |
| 14. Trie + Misc | `14_Trie_Misc` |
| 15. 其他题 | `15_Others` |

创建文件夹：`hot100/<NN_Category>/<ID四位补零>_<Title_Words_By_Underscore>/`
若已存在则告知用户并停止。

## 步骤四：生成 problem.md

从 content 中拆出描述、示例、约束，填入：
```
# <ID>. <Title>
**Difficulty:** <difficulty>
**Link:** https://leetcode.com/problems/<slug>/
---
## Description
## Examples
## Constraints
```

## 步骤五：生成 solution.cpp 和 solution.go

参照 `.claude/templates/solution_template.cpp` 和 `.claude/templates/solution_template.go`。
从 metaData JSON 提取函数名和参数/返回类型，按 `.claude/lc_type_map.md` 做类型映射，替换占位符。
至少写 5 个测试用例（所有示例 + ≥2 边界用例）。
涉及 TreeNode/ListNode 时，在 Solution 上方插入 lc_type_map.md 中的标准结构体定义。

## 步骤六：更新 README

从 README.md 的章节标题推断 Category（如题目在"## 2. Two Pointers"节下 → `Two Pointers`）。

```bash
python3 .claude/scripts/lc_readme_update.py start README.md \
  <id> "<title>" "<difficulty>" "<category>" "hot100/<NN_Category>/<folder>/problem.md"
```