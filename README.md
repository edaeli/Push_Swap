*This project has been created as part of the 42 curriculum by khoayvaz, taslanya.*

# push_swap

## Description

**push_swap** is a highly efficient C project that challenges you to sort a random list of integers using two stacks and a limited set of operations. 

The goal is to sort the data with the **minimum number of operations**. This project focuses on algorithm complexity, stack manipulation, and optimization. It requires a deep understanding of sorting logic and the ability to choose the most efficient path to reach a sorted state.

The project consists of two parts:
1. **push_swap**: A program that calculates and displays the shortest sequence of instructions to sort the integers.
2. **checker** (Bonus): A program that reads the instructions and verifies if they actually sort the stack correctly.

---

## Project Structure

The project is organized into several key components:

- `push_swap.c` – Main entry point for the sorter.
- `checker.c` – Main entry point for the instruction verifier.
- `parser.c` / `split.c` – Handling and validating input arguments.
- `operations.c` / `commands.c` – Implementation of the basic moves (`sa`, `pb`, `ra`, `rrr`, etc.).
- `greedy_sort.c` / `chunk_sort.c` – Core sorting algorithms.
- `push_swap.h` – Header file with structures and prototypes.

---

## Algorithm Explanation

To achieve the best performance (under 700 moves for 100 numbers and under 5500 for 500 numbers), I implemented a **Greedy Cost-Based Algorithm**.

### 1. Small Sorts (3 to 5 elements)
- **3 Elements:** Uses a simple pattern-matching logic to sort in maximum 2 moves.
- **5 Elements:** Pushes the two smallest numbers to Stack B, sorts the remaining three, and pushes them back.

### 2. Large Sort (Greedy/Cost-Based)
For larger sets of numbers, the algorithm follows these steps:

1. **Pre-sorting / Indexing:** All numbers are simplified into indexes (from 0 to N-1) to make comparisons easier.
2. **Pushing to B:** All numbers except three are pushed from Stack A to Stack B. A "chunk" or "mechanical" logic is used to keep Stack B somewhat organized during this process.
3. **Calculating Costs:** For every element in Stack B, the algorithm calculates how many moves are required to place it in its correct sorted position in Stack A.
   - **Cost A:** Moves needed to rotate Stack A to the correct spot.
   - **Cost B:** Moves needed to bring the element to the top of Stack B.
4. **Optimization (Double Rotations):** If both stacks need to rotate in the same direction, we use `rr` or `rrr` to reduce the total cost.
5. **Execution:** The element with the **lowest combined cost** is moved.
6. **Final Adjustment:** Once all elements are back in Stack A, a final rotation ensures the smallest number is at the top.

### Why this algorithm?
Unlike Radix Sort, which has a fixed number of operations, the **Greedy Algorithm** adapts to the data. It consistently yields significantly lower operation counts because it always chooses the most efficient "next step."

---

## Instructions

### Compilation

Compile the project using the provided `Makefile`:

```bash
# Compile push_swap
make

# Compile the checker (bonus)
make bonus
```

### Execution

To see the list of operations:
```bash
./push_swap 3 2 5 1 4
```

To verify if the sorting is correct:
```bash
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
```

To check for errors:
```bash
./checker 1 2 three
# Result: Error
```

---

## Resources

The following references were used during development:

- **Sorting Algorithms Complexity:** Study of $O(n^2)$ vs $O(n \log n)$ behaviors.
- **Unix Logic:** Understanding standard input/output for the checker program.
- **42 Intranet Subject:** Guidelines for stack operations and performance benchmarks.

### Use of Artificial Intelligence

Artificial Intelligence was used as a supplementary tool to optimize the development process:

- **Checker Integration:** Assisted in structuring the instruction loop and integrating `get_next_line` for the bonus part.
- **Memory Management:** Helped identify and fix memory leaks using `Valgrind` logs, particularly in the stack clearing functions.
- **Norminette Compliance:** Used to refactor long conditional blocks in `execute_cmd` into Norm-compliant functions.
- **Documentation:** Assisted in generating and formatting this `README.md` to meet the project requirements.

*All sorting logic and stack implementations were manually coded and tested to ensure deep understanding of the algorithms.*