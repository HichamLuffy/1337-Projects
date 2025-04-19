# 📜 get_next_line – 1337 Project

This is my implementation of the **get_next_line** project from the 42/1337 curriculum. The goal is to write a function that reads a file line by line, returning one line at a time, no matter the file size or line length.

---

## 💡 What You Should Learn Before Starting

This project might look like a simple `read()` loop, but it’ll teach you a lot about file handling, buffers, and memory management. Here are the key things to understand if you want to pass and write clean, solid code.

### 🔍 1. File Descriptors (FDs)
- Deeply understand what **file descriptors** are.
- Learn how they're used by the operating system, how they behave with files, stdin/stdout, and pipes.
- Remember: each opened file or stream has its own file descriptor, and you’ll need to handle **multiple FDs** correctly.

### 📖 2. How `read()` Works
- Understand how the `read()` system call works under the hood.
- Know when and why it **returns 0 (EOF)** or **-1 (error)**.
- Always check the return value of `read()` and handle errors gracefully.

### 🧵 3. BUFFER_SIZE
- Understand how the `BUFFER_SIZE` macro (defined in the header) affects performance and correctness.
- Be sure your code works with any positive buffer size—even **1**.

### 🧠 4. Memory Management
- This project is a classic memory leak trap—get good at managing your allocations and frees.
- Watch out for edge cases like failed `read()`, `malloc()`, or when EOF is reached.

### 🧼 5. Understand Your Own Code
- You must understand **every line of your code**. Avoid copying blindly.
- Try to refactor your code into small, readable functions.
- If you don’t fully understand how your loop or string manipulation works, you’re more likely to leak memory or hit undefined behavior.

---

## 💡 Pro Tips

- 💥 If you set `BUFFER_SIZE` to `INT_MAX`, your code **should still work**.
- 🚫 But if it’s set to more than `INT_MAX`, your code **should fail** (as expected).
- ✅ Always test with different `BUFFER_SIZE` values: small, large, 0, or undefined.
- 🔄 Repeatedly test with multiple file descriptors (bonus part) to ensure your buffers don't conflict.

---

## 🧪 Recommended Testers

- test manually with:
  - Empty files
  - Very large files
  - Files without a trailing newline
  - `read()` returning -1 (you can fake this using `/dev/zero` + restricted permissions)

---

## 📘 Helpful Resources

- `man read`, `man open`, `man close`, `man malloc`, and `man free` — read them fully.
- Online articles or videos on how `read()` works in Linux.
- **Valgrind** — your best friend for spotting memory leaks.

---

## 🗣️ Final Thoughts

This project teaches you how to think like a systems programmer: handle errors, manage memory, and write predictable, reusable code. Don’t rush it. Read your code like someone else will be grading every detail—because they will.

—
**Good luck and keep coding.**