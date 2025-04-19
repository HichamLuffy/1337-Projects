# 🖨️ ft_printf – 1337 Project

This is my version of the **ft_printf** project from the 42/1337 curriculum. It's all about reimplementing the famous `printf` function from scratch, learning how variadic functions work in C.

---

## 🧠 What You Should Learn for ft_printf

This project is pretty straightforward, but you still need a solid understanding of how C handles memory, arguments, and output. Here’s what you should focus on:

### 📦 1. Variadic Functions
- Understand how **variadic functions** work (functions that take a variable number of arguments).
- Learn how to use the macros:
  - `va_list`
  - `va_start`
  - `va_arg`
  - `va_end`
- Know how values are passed in **registers** and **stack**, especially for the first arguments.
- Learn how arguments are read from memory in runtime — this will help avoid weird bugs.

### ⚠️ 2. Edge Cases
- The project itself is not that hard — **the difficulty is in the edge cases**.
- Pay close attention to how the real `printf` handles:
  - NULL strings
  - Zero values
  - Special characters
  - Negative numbers and precision

### 🧪 3. Testing
- Use **francinette** or any of the available ft_printf testers online to validate your output.
- Also, make your own tests with weird inputs — try to break your own code.

---

## 🧰 Project Organization & Makefile Tips

In my case, I **separated** the project into:
- `src/` folder for the mandatory part
- `source_bonus/` folder for the bonus part

I kept **one Makefile** with a custom `bonus` rule to compile only the bonus part.

> ✅ If you do the bonus part (even if it’s all in one folder), **you MUST still include a `bonus:` rule in your Makefile**.  
> Example:
> ```makefile
> bonus: all
> ```

This way, your Makefile passes the evaluation norms.

You’re also free to combine everything into one `ft_printf` that does both mandatory and bonus — just make sure your `Makefile` reflects that properly.

---

## 🏆 What You'll Gain from the Bonus Part

- Learn how to **handle bigger, more complex logic** with more cases.
- Work with multiple flags, width, precision, and combinations of all of them.
- Improve your ability to write modular, maintainable code.

---

## 📚 Useful Resources

- `man 3 printf` — Read it carefully!
- Articles and YouTube videos on how registers and the stack work in function calls.

---

## 🗣️ Final Thoughts

This project teaches you how to **rebuild** something huge by breaking it down into small parts. Don’t overcomplicate it, and make sure your code is clean, tested, and understandable.

—
**You got this 💪 Keep printing that W.**