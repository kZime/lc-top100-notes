对当前题目完成做题复盘。全程使用**中文**。

## 步骤一：读题 & 读代码

1. 若有 ARGUMENTS，用 Glob 模式 `**/0<NNNN>*/problem.md`（零填充到4位）定位题目文件夹，例如参数为 `41` 则搜索 `**/0041*/problem.md`。找到后读取该路径的 `problem.md`
2. 列出解法文件：
   ```bash
   ls solution*.cpp solution*.go note.md 2>/dev/null | sort
   ```
3. 对每个代码文件：用 Grep 定位 Solution 类/函数的起止行，再 Read offset+limit 只取该段（跳过 test harness）。若文件含 `TODO: implement` 则跳过。
4. 若所有文件均为 TODO，停止并提示用户先实现代码。
**notes.md 已存在时**：若有未分析过的新解法文件，追加 `## 我的解法（solutionN.cpp）`, 然后跳到步骤5

## 步骤二：拉取高赞题解

```bash
bash .claude/scripts/lc_cn_solutions.sh SLUG
```

输出前 3 篇题解的纯文本（含标题和点赞数），最多 3000 字符。
若输出 `FETCH_FAILED`，改用 WebFetch 抓 `https://leetcode.cn/problems/SLUG/solutions/?envType=study-plan-v2&envId=top-100-liked`。
若仍失败，用内置知识并在 notes.md 中注明。

## 步骤三：提炼算法 & 分析用户代码

**提炼**：从题解中选 2～3 种最具代表性的算法，**按复杂度从高到低排列**（算法一最朴素，末尾最优）。每种写：核心思路（2～4 句）、时间/空间复杂度。不贴代码。

**分析**：将用户代码与各算法对比，判断最接近哪种并写出依据。若有改进空间（复杂度或实现）指出 1～2 点；若已最优明确说明。

## 步骤四：生成 notes.md

参照 `.claude/templates/notes_template.md` 的结构生成文件。

**notes.md 已存在时**：若有未分析过的新解法文件，追加 `## 我的解法（solutionN.cpp）` 小节；若无新文件，询问用户是否覆盖。

## 步骤五：更新 README

> README 路径：`../../../README.md`（相对题目文件夹，结构为 `hot100/<NN_Category>/<folder>/`）

**☑ 条件**：复杂度与最优方案一致且无明显改进点：
```bash
CATEGORY=$(basename $(dirname $(pwd)))
python3 ../../../.claude/scripts/lc_readme_update.py finish ../../../README.md \
  <id> "hot100/$CATEGORY/<folder>/notes.md"
```

**⊙ 条件**：存在更优方案或有明显 bug，不改状态，不执行脚本。
