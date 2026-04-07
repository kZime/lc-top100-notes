#!/usr/bin/env python3
"""
lc_readme_update.py  —  README.md status updater

Commands:
  start  <readme> <id> <title> <difficulty> <category> <problem_link>
         Set status to ⊙, add row to 尝试中 table.

  finish <readme> <id> <notes_link>
         Set status to ☑, add notes link, remove from 尝试中, recount progress.
"""
import sys, re

CHECK = "☑"
CIRCLE = "⊙"
EMPTY = "☐"


def read(path):
    with open(path, encoding="utf-8") as f:
        return f.readlines()


def write(path, lines):
    with open(path, "w", encoding="utf-8") as f:
        f.writelines(lines)


def recount_progress(lines):
    """Recount ☑ in main tables and update **N / 100** line."""
    count = sum(1 for l in lines if re.search(r'\|\s*☑\s*\|', l))
    for i, l in enumerate(lines):
        if re.match(r'\*\*\d+ / 100\*\*', l.strip()):
            lines[i] = f"**{count} / 100**\n"
            break
    return lines


def set_status_in_main_table(lines, pid, new_status, notes_link=""):
    """Find the row for pid in the main category tables and update status."""
    pattern = re.compile(rf'^\|\s*{pid}\s*\|')
    for i, l in enumerate(lines):
        if pattern.match(l):
            # Replace status cell (4th pipe-delimited field)
            parts = l.split("|")
            # parts: ['', '#', 'Title', 'Difficulty', 'Status', 'Notes', '']
            if len(parts) >= 6:
                parts[4] = f" {new_status} "
                parts[5] = f" {notes_link} " if notes_link else " "
            lines[i] = "|".join(parts)
    return lines


def add_to_trying(lines, pid, title, difficulty, category, problem_link):
    """Add a row to the 尝试中 table if not already present."""
    new_row = f"| {pid} | [{title}]({problem_link}) | {difficulty} | {category} |\n"
    pid_str = f"| {pid} |"

    # Find header of 尝试中 section
    header_idx = None
    for i, l in enumerate(lines):
        if "尝试中" in l and l.startswith("## "):
            header_idx = i
            break
    if header_idx is None:
        return lines

    # Check if already in table
    for l in lines[header_idx:]:
        if l.startswith("---") and header_idx is not None:
            break
        if pid_str in l:
            return lines  # already present

    # Find end of table (first blank line after the table header row)
    in_table = False
    insert_idx = None
    for i in range(header_idx, len(lines)):
        l = lines[i]
        if l.startswith("|"):
            in_table = True
        elif in_table and not l.startswith("|"):
            insert_idx = i
            break

    if insert_idx is not None:
        lines.insert(insert_idx, new_row)

    # Update count in header: 尝试中（N 题）
    for i in range(header_idx, header_idx + 1):
        lines[i] = re.sub(
            r'（(\d+) 题）',
            lambda m: f'（{int(m.group(1)) + 1} 题）',
            lines[i]
        )
    return lines


def remove_from_trying(lines, pid):
    """Remove the row for pid from 尝试中 table and decrement count."""
    pid_str = f"| {pid} |"
    header_idx = None
    for i, l in enumerate(lines):
        if "尝试中" in l and l.startswith("## "):
            header_idx = i
            break
    if header_idx is None:
        return lines

    removed = False
    for i in range(header_idx + 1, len(lines)):
        if lines[i].startswith("---"):
            break
        if pid_str in lines[i]:
            lines.pop(i)
            removed = True
            break

    if removed:
        lines[header_idx] = re.sub(
            r'（(\d+) 题）',
            lambda m: f'（{max(0, int(m.group(1)) - 1)} 题）',
            lines[header_idx]
        )
    return lines


def cmd_start(readme, pid, title, difficulty, category, problem_link):
    lines = read(readme)
    lines = set_status_in_main_table(lines, pid, CIRCLE)
    lines = add_to_trying(lines, pid, title, difficulty, category, problem_link)
    write(readme, lines)
    print(f"[lc_readme] {pid} → ⊙, added to 尝试中")


def cmd_finish(readme, pid, notes_link):
    lines = read(readme)
    lines = set_status_in_main_table(lines, pid, CHECK, notes_link)
    lines = remove_from_trying(lines, pid)
    lines = recount_progress(lines)
    write(readme, lines)
    print(f"[lc_readme] {pid} → ☑, removed from 尝试中, progress recounted")


if __name__ == "__main__":
    args = sys.argv[1:]
    if not args:
        print(__doc__)
        sys.exit(1)

    cmd = args[0]
    if cmd == "start" and len(args) >= 7:
        cmd_start(args[1], args[2], args[3], args[4], args[5], args[6])
    elif cmd == "finish" and len(args) >= 4:
        cmd_finish(args[1], args[2], args[3])
    else:
        print(__doc__)
        sys.exit(1)