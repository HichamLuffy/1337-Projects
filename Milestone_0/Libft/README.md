# 🧠 Libft – 1337 Project

This is my version of the **Libft** project from the 42/1337 curriculum. It's the first real step into C programming, where you rebuild some of the standard library functions from scratch. It may seem easy at first, but there's a lot to learn if you want to do it right.

---

## 🔥 What You *Really* Need to Know to Pass Libf

Here’s a list of things that really helped me understand Libft better. If you focus on these, the project will make a lot more sense.

### 🛠️ 1. Makefiles
- Know how to write a Makefile from scratch.
- Understand how `make` works: rules, targets, and dependencies.

### ⚙️ 2. How Compilation Works in C
- Learn the steps of the compilation process: **preprocessing**, **compiling**, **assembling**, and **linking**.
- Understand what the compiler actually does when you run `gcc` or `make`.
- Get familiar with `.c`, `.o`, and executable files—and how they all connect.
- Knowing this will help you debug linker errors and understand Makefiles better.

### 🔥 3. Overflow
- Understand how integer overflow happens.
- Try breaking your code with edge cases to see how it behaves.

### 🧠 4. Memory, Segfaults & Aborts
- Learn how memory works in C: allocation, freeing, and pointer access.
- Get comfortable debugging **segmentation faults** and **aborts**.
- Understand the difference between the **stack** and the **heap**, and how memory is structured in a C program.

### 📚 5. Libc Functions
- Don’t just copy what you see online—understand how functions like `strlcat`, `strlcpy`, `memcpy`, etc., actually behave.
- Read the man pages and test them out yourself.

### 🧷 6. File Descriptors
- Understand what **file descriptors (FDs)** are and how `write()` uses them.
- Know what 0, 1, and 2 mean (STDIN, STDOUT, STDERR).

### 📦 7. Structs & Memory
- Learn how structs work and how to calculate their size.
- Understand how padding and memory alignment can affect your program.

### 🧹 8. Memset & Memcpy
- Practice using `memset`, `memcpy`, and learn their purpose.
- Know the difference between **`memcpy`** and **`strlcpy`**.

### 🌀 9. Passing Functions as Parameters
- Learn how to **pass functions as arguments**.
- It’s especially useful for bonus part (like linked list operations).

### 🌿 10. Linked Lists
- Understand how linked lists work, how to **create**, **traverse**, **insert**, and **delete** nodes.
- Learn **when** they’re useful and how to manage their memory cleanly.
- Practice managing memory properly with `malloc` and `free`.

---

## 📘 Recommended Resources

These two books really helped me understand the language and the system better:

- **Head First C** – a friendly and visual way to learn C.
- **The Linux Programming Interface** – a deeper dive into how everything works under the hood.

---

## 🧪 Extra Tips

Always test your functions with:
- Edge cases
- Empty strings
- Large inputs
- Invalid or NULL inputs (when allowed)

---

## ✨ Final Thoughts

Libft is the base for everything that comes next at 1337. Don’t rush it. Take the time to understand what you’re writing, test everything, and write clean, readable code..

—
Thanks for stopping by 🫶