*This activity has been created as part of the 42 curriculum by kkrriku, ajrexha.*

# push_swap

## Description

push_swap is a sorting program written in C. It takes a list of integers and sorts them in ascending order using two stacks (`a` and `b`) and a limited set of 11 operations. The program outputs the smallest sequence of operations to stdout.

The project explores algorithmic complexity by implementing four distinct sorting strategies, each belonging to a different complexity class. A disorder metric measures how far the input is from being sorted, and an adaptive strategy selects the best internal method based on that measurement.

## Instructions

### Compilation

```bash
make        # Compiles libft and push_swap
make clean  # Removes object files
make fclean # Removes object files and binaries
make re     # Full recompile
```

The project compiles with `cc -Wall -Wextra -Werror` and uses a custom `libft` library.

### Execution

```bash
./push_swap <numbers...>                        # Default (adaptive)
./push_swap --simple <numbers...>               # Force O(n^2)
./push_swap --medium <numbers...>               # Force O(n*sqrt(n))
./push_swap --complex <numbers...>              # Force O(n*log(n))
./push_swap --adaptive <numbers...>             # Force adaptive (default)
./push_swap --bench <numbers...>                # Enable benchmark output on stderr
```

### Verification with checker

```bash
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_os $ARG
# Should print: OK
```

### Error handling

- Non-integer arguments, duplicates, or values outside INT range print `Error` to stderr.
- No arguments: silent exit.
- Already sorted: no output.

## Algorithms: Rationale and Complexity

### Strategy 1: Simple — Selection Sort — O(n^2)

**Flag:** `--simple`

Repeatedly finds the minimum element in stack `a`, rotates it to the top using the shortest path (ra or rra), and pushes it to `b`. After all elements are in `b`, pushes everything back to `a`.

**Complexity:** For each of the n elements, we scan the stack to find the minimum (O(n)) and rotate it to the top (up to n/2 operations). Total: O(n^2) push_swap operations.

**Space:** O(n) — uses stack `b` to hold all elements.

### Strategy 2: Medium — Chunk Sort — O(n*sqrt(n))

**Flag:** `--medium`

After normalizing values to indices 0..n-1, divides the range into chunks (5 chunks for n<=100, 11 for n<=500). Iterates through stack `a` and pushes elements belonging to the current chunk to `b`, using bidirectional scanning to find the nearest matching element. Within each chunk, smaller values are rotated to the bottom of `b` to maintain partial order. Finally, repeatedly finds the maximum in `b` and pushes it back to `a`.

**Complexity:** Each element is found via bidirectional scan within its chunk pass. With k chunks of size n/k, pushing costs O(n) per chunk (each element rotates at most n positions). Push-back phase: finding max in b costs O(n) per element. Total: O(n * k + n^2/k). With k = sqrt(n), this gives O(n * sqrt(n)).

**Space:** O(n) — uses stack `b`.

### Strategy 3: Complex — Binary Radix Sort — O(n*log(n))

**Flag:** `--complex`

Works on normalized indices (0 to n-1). For each bit position from LSB to MSB: iterates through all elements in `a`. If the current bit is 0, pushes to `b` (pb). If 1, rotates `a` (ra). After processing all elements for that bit, pushes everything from `b` back to `a`.

**Complexity:** There are log2(n) bit positions. For each bit, we process n elements (one operation each) and push back at most n elements. Total: O(n * log(n)) push_swap operations.

**Space:** O(n) — uses stack `b`.

### Strategy 4: Adaptive — Turkish Sort — O(n) / O(n*sqrt(n)) / O(n*log(n))

**Flag:** `--adaptive` (default when no flag is given)

The adaptive strategy measures the disorder of the input before sorting and selects an internal method accordingly.

**Disorder metric:** Computed as the ratio of inversions to total pairs. An inversion is a pair (i, j) where i < j but a[i] > a[j]. Disorder = inversions / (n*(n-1)/2). A value of 0 means sorted, 1 means reverse sorted.

**Method selection based on disorder:**

- **Low disorder (< 0.2):** The stack is nearly sorted. Uses the chunk sort with fewer chunks, exploiting the existing order. The limited number of out-of-place elements means few operations are needed. Target: O(n) operations.

- **Medium disorder (0.2 <= d < 0.5):** Uses the Turkish sort (cost-based insertion). For each element in `a`, calculates the cost to insert it into the correct position in `b` (keeping `b` sorted in descending order). Always executes the cheapest insertion. Combined rotations (rr/rrr) are used when both stacks need to rotate in the same direction, reducing the total cost. Target: O(n*sqrt(n)) operations.

- **High disorder (>= 0.5):** Also uses the Turkish sort, which performs well on highly disordered input due to its cost optimization. The combined rotation optimization (rr/rrr) keeps operations efficient even with random data. Target: O(n*log(n)) operations.

**Turkish sort details:** Pushes 2 elements to `b`, then for each remaining element (except the last 3), finds the cheapest element to move by computing: cost = rotations for `a` + rotations for `b`, with a discount when both rotate in the same direction (using rr or rrr). The last 3 elements in `a` are sorted in-place with hardcoded optimal moves. Then elements are pushed back from `b` to `a`, each inserted at the correct position to maintain sorted order. Finally, the minimum is rotated to the top.

**Threshold justification:** The 0.2 threshold separates nearly-sorted inputs (where most elements are already in place) from moderately disordered ones. The 0.5 threshold marks the transition to highly random data where the cost-based approach benefits most from combined rotations. These values were chosen empirically to minimize average operation count across varied inputs.

## Performance

| Input size | Average ops | Target (excellent) |
|------------|-------------|-------------------|
| 100 numbers | ~634 | < 700 |
| 500 numbers | ~5481 | < 5500 |

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements at the top of stack `a` |
| `sb` | Swap the first two elements at the top of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Take the first element at the top of `b` and put it at the top of `a` |
| `pb` | Take the first element at the top of `a` and put it at the top of `b` |
| `ra` | Rotate `a` — shift up all elements by one, first becomes last |
| `rb` | Rotate `b` — shift up all elements by one, first becomes last |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate `a` — shift down all elements by one, last becomes first |
| `rrb` | Reverse rotate `b` — shift down all elements by one, last becomes first |
| `rrr` | `rra` and `rrb` at the same time |

## Resources

- [The Art of Computer Programming, Vol. 3: Sorting and Searching — Donald Knuth](https://en.wikipedia.org/wiki/The_Art_of_Computer_Programming)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Visualgo — Sorting Visualizations](https://visualgo.net/en/sorting)
- [Push_swap Tutorial — Algorithmic approaches](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### AI usage

AI was used as a development assistant for:
- Implementing the sorting algorithms based on our design decisions
- Writing boilerplate code (libft functions, stack operations, Makefile)
- Debugging and optimizing operation counts
- Generating test commands for performance validation

All generated code was reviewed, understood, and tested by the team. The algorithmic choices (Turkish sort for adaptive, chunk sort for medium, radix for complex, selection sort for simple) were made by the learners based on performance analysis.
