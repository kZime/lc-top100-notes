# 使用说明

## 环境要求

- C++17：`g++ -std=c++17`
- Go 1.18+：`go run`
- [Claude Code](https://claude.ai/code) CLI（使用 `/lc` 和 `/lc-review` skill）

## 如何复用本项目

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
5. 将 README 中该题的 Status 列更新为 `⊙`，并加入"尝试中"表格

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
5. 若解法已是最优解，将 README 中该题的 Status 列更新为 `☑`，从"尝试中"表格移除，更新完成计数

```bash
cd 0128_Longest_Consecutive_Sequence
/lc-review
```
