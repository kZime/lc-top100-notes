Set up all problems from a LeetCode contest. Argument: $ARGUMENTS (contest URL or slug, e.g. `biweekly-contest-180` or `https://leetcode.com/contest/biweekly-contest-180`).

## 步骤一：解析 contest slug

从 $ARGUMENTS 中提取 slug：
- 完整 URL（含 `/contest/`）→ 取最后一段路径（去除末尾 `/`），例如 `https://leetcode.com/contest/biweekly-contest-180` → `biweekly-contest-180`
- 已是 slug → 直接使用

## 步骤二：获取比赛题目列表

**方案一（优先）：LeetCode REST API**

```bash
curl -s "https://leetcode.com/contest/api/info/<SLUG>/" \
  -H 'User-Agent: Mozilla/5.0'
```

返回 JSON，顶层字段 `questions` 数组，每项含 `question_id`、`title_slug`、`title`、`difficulty`、`credit`（分值）。按 `credit` 升序排列即为 Q1→Q4。同时从 `contest.title` 获取比赛全名。

**方案二（备用）：GraphQL**

```bash
curl -s -X POST 'https://leetcode.com/graphql' \
  -H 'Content-Type: application/json' \
  -H 'User-Agent: Mozilla/5.0' \
  -H 'x-csrftoken: lc' \
  -H 'Cookie: csrftoken=lc' \
  --data "{\"query\":\"query contest(\$titleSlug: String!) { contest(titleSlug: \$titleSlug) { title questions { questionId titleSlug title difficulty } } }\",\"variables\":{\"titleSlug\":\"<SLUG>\"}}"
```

**方案三（最后备用）**：WebFetch 抓 `https://leetcode.com/contest/<SLUG>/`，从页面 HTML 解析 4 道题的链接和标题。

提取出 4 道题各自的 `question_id`（题号）、`title_slug`、`title`、`difficulty`，按难度从易到难标记为 Q1~Q4。

## 步骤三：为每道题创建工作空间

对每道题依次执行（Q1 → Q4）：

### 3a. 拉取题目数据

```bash
bash .claude/scripts/lc_fetch.sh <title_slug>
```

输出 JSON：`{id, title, difficulty, content（纯文本）, metaData（含函数签名 JSON）}`。
若脚本返回 error，基于内置知识构建文件并告知用户。

### 3b. 创建文件夹

路径：`others/contests/<SLUG>/Q<N>_<ID四位补零>_<Title_Words_By_Underscore>/`

示例：`others/contests/biweekly-contest-180/Q1_3543_Some_Title/`

若文件夹已存在，跳过该题并告知用户。

### 3c. 生成 problem.md

从 content 中拆出描述、示例、约束，填入：

```
# <ID>. <Title>
**Difficulty:** <difficulty>
**Link:** https://leetcode.com/problems/<slug>/
---
## Description
...
## Examples
...
## Constraints
...
```

### 3d. 生成 solution.cpp 和 solution.go

参照 `.claude/templates/solution_template.cpp` 和 `.claude/templates/solution_template.go`。
从 metaData JSON 提取函数名和参数/返回类型，按 `.claude/lc_type_map.md` 做类型映射，替换占位符。
涉及 TreeNode/ListNode 时，在 Solution 上方插入 lc_type_map.md 中的标准结构体定义。

**重要：Solution 类/函数体只保留 `// TODO: implement`，绝对不写任何解题逻辑。** 这是用户的做题空间。

测试用例至少 5 个（所有示例 + ≥2 边界用例），写完整调用和期望值，当前运行会全部失败——这是正常的。

## 步骤四：生成 contest README

在 `others/contests/<SLUG>/README.md` 创建题目索引表：

```markdown
# <Contest Title>

| Q  | ID   | Title | Difficulty | Status |
|----|------|-------|------------|--------|
| Q1 | <id> | [<title>](Q1_<folder>/problem.md) | <difficulty> | ☐ |
| Q2 | <id> | [<title>](Q2_<folder>/problem.md) | <difficulty> | ☐ |
| Q3 | <id> | [<title>](Q3_<folder>/problem.md) | <difficulty> | ☐ |
| Q4 | <id> | [<title>](Q4_<folder>/problem.md) | <difficulty> | ☐ |
```

完成后输出已创建的所有文件路径清单。