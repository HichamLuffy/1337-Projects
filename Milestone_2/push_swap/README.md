# 🔃 push_swap – 1337 Sorting Project

This is my version of the **push_swap** project from the 42/1337 curriculum.  
The goal is simple: sort a stack using only specific operations with the fewest possible moves.

---

## 🧠 The Core Idea

You're given a stack of integers and your job is to sort it using a limited set of stack operations:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

Your program must output a sequence of these instructions that sort the stack **as efficiently as possible**.

---

## 🧩 Algorithm Logic & Strategy

There are multiple algorithms you can use for this project. 
### 💸 My Preferred Method: Cost-Based Algorithm

I personally used the **cost logic** strategy.

- For every number in `stack B`, calculate:
  - The cost to bring it to the top of `stack B`
  - The cost to bring its target position to the top of `stack A`
- Choose the number with the lowest total cost.
- Perform the necessary rotations efficiently, and push it.

📘 **Great resource for cost logic**:  
[Oceano the goat](https://www.youtube.com/watch?v=OaG81sDEpVk&t=3610s)

---
#### there is also other algos like 
- **Chunking Method**: Split stack A into chunks and push them to B based on value ranges.

---

## 📚 What You Should Learn From This Project

There’s not much theory involved beyond the sorting logic, but this is your **perfect chance** to:

- Understand and **implement real sorting algorithms** from scratch
- Study **time complexity** and **optimization**
- Practice writing **modular and efficient C code**
- Visualize sorting steps using tools (bonus: write your own visualizer)

---

## 🔧 Recommended Next Steps

- Try coding small sorting algorithms first: bubble sort, selection sort, insertion sort.
- Learn about **time complexity**: O(n), O(n²), O(log n), etc.
- Use push_swap to explore how to implement and optimize algorithms under constraints.

---

## 🗣️ Final Thoughts

This is one of those projects where you **can’t just hardcode** your way through.  
Build a solid base, keep your code clean, and enjoy the algorithmic grind.

—

