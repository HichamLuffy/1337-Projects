

# 📁 pipex – Recreate Shell Piping (42 Project)

## 📌 Project Overview

**pipex** is a foundational Unix project that lets you recreate the behavior of shell piping, like:

```bash
< infile cmd1 | cmd2 > outfile
```

It pushes you to work deeply with **processes**, **file descriptors**, **pipes**, and the low-level way Linux handles command execution.

---

## 🧠 Why This Project Matters

If you’re planning to tackle **Minishell**, do **pipex** first — it’s the perfect intro to:

- **Process creation** using `fork()`
- **Inter-process communication** via `pipe()`
- **I/O redirection** using `dup2()`
- **Program execution** with `execve()`

You'll build the habits and low-level understanding needed for building your own shell.

---

## 🧨 What You Should Deeply Understand

### 🔄 Forking & Processes
- Learn how `fork()` creates a child process.
- Understand **zombie processes** (child dies, parent ignores) and **orphan processes** (parent dies before child).
- Handle `wait()` or `waitpid()` properly to avoid zombies.

### 🔗 Pipes & Communication
- `pipe(fd)` gives you a way to connect output of one process to input of another.
- Learn how to redirect file descriptors: stdin/stdout/stderr.

### 🛠️ Edge Case Warnings
- Running commands like `./ls` or `ls` when `$PATH` is unset.
- Invalid permissions on `infile` or if it doesn’t exist.
- Watch for misuse of `access()` — check permissions wisely.
- If `env` is NULL or missing key variables like `PATH`, handle it gracefully.
---


## ✅ Bonus Tips

- Use `valgrind` and `lsof` to track memory leaks and file descriptor leaks.

---

