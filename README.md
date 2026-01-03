# push_swap - Efficient Stack Sorting

An algorithmic challenge to sort integers using only two stacks (`a`, `b`) and a constrained set of operations, emphasizing time complexity, move minimization, and safe memory handling.

## Overview

push_swap receives an unsorted list of integers and outputs the minimal (or near-minimal) sequence of stack operations to sort them. The project balances algorithmic efficiency with strict operational constraints, making every move count.

## Core Concepts

- **Constrained Operations**: Only stack rotations, swaps, and pushes are available. Solutions must respect this limited instruction set.
- **Complexity Awareness**: Strategies aim for $O(n \log n)$ behavior on larger inputs while staying minimal on small inputs.
- **Memory Safety**: Parsing, indexing, and operation sequencing avoid leaks and double frees; all allocations are released on success or failure paths.
- **Deterministic Output**: Given the same input, the program emits a consistent, reproducible sequence of moves.

## Algorithms Employed

- **Small-Input Strategies**: Tailored sequences for $n \le 5$ to minimize moves.
- **Radix/Binary Sorting**: Index-based radix approach for larger $n$ to achieve scalable performance within the allowed operations.
- **Validation & Indexing**: Input is validated (duplicates, non-numeric, overflow), then normalized to indexed values to simplify comparisons.

## Build & Run

```bash
make
./push_swap <list_of_ints>
```

Example:
```bash
./push_swap 2 1 3 6 5 8
```

## Failure Containment & Memory Management

- Validate inputs before allocation; reject on duplicates, invalid numbers, or overflow.
- Free all allocated structures on any error path; no partial-state leaks.
- Keep operation logs in contiguous structures to simplify cleanup and output.

## Learning Outcomes

- Designing algorithms under strict operation constraints.
- Balancing minimal moves with scalable complexity.
- Implementing input validation and memory-safe data structures (arrays/lists for stacks, operation logs).

---

*A 42 School project focused on algorithmic efficiency and safe resource management.*
