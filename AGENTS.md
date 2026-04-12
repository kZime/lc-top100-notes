# AGENTS.md

For general-purpose agents working in this repository:

- If the user asks for `lc`, read `.claude/commands/lc.md`.
- If the user asks for `lc-review`, read `.claude/commands/lc-review.md`.
- If the user asks for `contest`, read `.claude/commands/contest.md`.

Reusable scripts live here:

- `.claude/scripts/lc_fetch.sh`
- `.claude/scripts/lc_cn_solutions.sh`
- `.claude/scripts/lc_readme_update.py`

Project-level workflow context lives in `CLAUDE.md`.

Important:

- Do not auto-solve newly bootstrapped problems.
- Keep generated solution bodies as `// TODO: implement`.
- Prefer reusing the existing scripts and templates instead of reimplementing the workflow.
