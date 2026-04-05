# LeetCode Top 100 — Workflow

## Quick Start

Use `/lc` to set up any problem:

```
/lc 128
/lc longest-consecutive-sequence
```

After solving, run `/lc-review` in the problem folder to pull top solutions from LeetCode CN, generate `notes.md`, and mark the problem ☑ in README.

---

## Folder Structure

```
top100/
├── CLAUDE.md
├── README.md
├── USAGE.md
├── .claude/commands/lc.md
├── .claude/commands/lc-review.md
├── hot100/
│   └── NNNN_Problem_Title/
│       ├── problem.md
│       ├── solution.cpp
│       ├── solution.go
│       └── notes.md
└── others/
    ├── contests/
    └── tmp/
```

Folder naming: zero-padded 4-digit ID + title words joined by `_`.
Example: `0049_Group_Anagrams`
