# Competitive Programming

## Setup (IDE + Contest Workflow)

### 1) Compiler and tools (macOS)

Install GCC (Homebrew):

```bash
brew install gcc
```

Check compiler:

```bash
g++ --version
```

### 2) IDE setup (Sublime Text)

- Open this folder in Sublime Text.
- Install _**FastOlympicCoding**_ Extension for Sublime text.
- Open the settins for **FastOlympicCoding** and this `run setting`

  ```
  	"run_settings": [
  	{
  		"name": "C++",
  		"extensions": ["cpp"],
  		"compile_cmd": "g++-15 -Wall -O2 -std=c++23 '{source_file}' -o {file_name}",
  		"run_cmd": "./\"{file_name}\" {args} -debug",

  		"lint_compile_cmd": "g++ -std=gnu++11 '{source_file}' -I '{source_file_dir}'"
  	},

  	{
  		"name": "Python",
  		"extensions": ["py"],
  		"compile_cmd": null,
  		"run_cmd": "python '{source_file}'"
  	},

  	{
  		"name": "Java",
  		"extensions": ["java"],
  		"compile_cmd": "javac -J-Dfile.encoding=utf8 -d \"{source_file_dir}\" \"{source_file}\"",
  		"run_cmd": "java -classpath \"{source_file_dir}\" \"{file_name}\""
  	}
  ],
  ```

- Keep terminal at repo root for quick compile/run commands.

### 3) Fast local run commands

Debug/local testing build:

```bash
g++ -std=c++20 -O2 -I. main.cpp -o main
./main < input.txt
```

Submission-style build:

```bash
g++ -std=c++20 -O2 -DONLINE_JUDGE -I. main.cpp -o main
./main < input.txt
```

### 4) Contest/problem-solving flow

1. Start from `main.cpp` template.
2. Put problem logic inside `solve(...)`.
3. Keep `debug(...)` while testing locally.
4. Compile with `-DONLINE_JUDGE` before final submit.
5. Reuse snippets from `LIBRARY/` as needed.

## LIBRARY Folder

Most files are snippet templates with small local `main()` demos. In contest use, copy the needed struct/functions into your solution file.

### DataStructures/FenwickTrees

- `LIBRARY/DataStructures/FenwickTrees/fenTree.cpp`: Basic Fenwick Tree (BIT), point update + range sum query (`qry(l, r)`).
- `LIBRARY/DataStructures/FenwickTrees/binJmp_fenwickTree.cpp`: Fenwick Tree + binary lifting style lower bound (`lw_bound(x)`) for prefix sums.

### DataStructures/SegmentTrees

- `LIBRARY/DataStructures/SegmentTrees/seg_tree.cpp`: Generic segment tree skeleton with `node`, `merge`, build/update/query (intended to customize).
- `LIBRARY/DataStructures/SegmentTrees/seg_lazy.cpp`: Lazy segment tree template for range updates + range sum style query.
- `LIBRARY/DataStructures/SegmentTrees/merge_sort_tree.cpp`: Merge-sort tree style structure using `multiset` at nodes; supports query for smallest value `>= x` in a range.
- `LIBRARY/DataStructures/SegmentTrees/sgt_min_max.cpp`: Segment tree for maximum subarray sum (`cs`, `psm`, `ssm`, `mss`) with point update.
- `LIBRARY/DataStructures/SegmentTrees/seg_lazy`: Compiled Mach-O executable artifact (not source template).

### DP

- `LIBRARY/DP/digitdp.cpp`: Digit DP to count numbers in range with exactly `k` occurrences of digit `d`.

### graph

- `LIBRARY/graph/bfs.cpp`: BFS traversal from node `1`, with parent tracking.
- `LIBRARY/graph/dfs.cpp`: DFS depth/distance fill from a root in a tree/graph.
- `LIBRARY/graph/dsu.cpp`: Disjoint Set Union (Union-Find) with path compression + union by size.
- `LIBRARY/graph/bipartitie.cpp`: Bipartite check using DFS and 2-coloring.
- `LIBRARY/graph/diameter.cpp`: Tree diameter using two DFS passes.
- `LIBRARY/graph/topoSort.cpp`: DFS postorder topological sort pattern.
- `LIBRARY/graph/eularTour.cpp`: Euler tour generation (`e1` and `e2` forms).
- `LIBRARY/graph/coordinate_cmp.cpp`: Coordinate compression via sorted copy + map.

### numberTheory

- `LIBRARY/numberTheory/binpow.cpp`: Binary exponentiation (`b^e mod MOD`).
- `LIBRARY/numberTheory/binomial.cpp`: Factorial/inverse precompute for `nCr`, `nPr` under modulo.
- `LIBRARY/numberTheory/harmonic.cpp`: Harmonic-style divisor counting (`count divisors for each number up to N`).
- `LIBRARY/numberTheory/seieve.cpp`: Prime sieve scaffold with prime list generation.

### string

- `LIBRARY/string/KMP.cpp`: KMP prefix/LPS array construction.
- `LIBRARY/string/trie.cpp`: Lowercase trie with insert/search/remove support.

### tree

- `LIBRARY/tree/bin_jmp.cpp`: Binary lifting / kth ancestor queries.
- `LIBRARY/tree/lca.cpp`: LCA + distance query using binary lifting.

### misc

- `LIBRARY/misc/matrix.cpp`: Matrix exponentiation skeleton (needs return/completion before direct use).
- `LIBRARY/misc/pascal.cpp`: Pascal triangle precompute for combinations table.
- `LIBRARY/misc/sparse_table.cpp`: Sparse table for static RMQ (minimum query).

## `main.cpp` Template Explanation

Your template in `main.cpp` is structured as:

1. **Header and namespace**
   - Includes local `bits/stdc++.h` and uses `std` namespace.

2. **Type aliases and macros**
   - Aliases like `ll`, `vi`, `vvi`, `pii`.
   - Utility macros like `FOR`, `ROF`, `all`, `F/S`, `nl`, and fast-I/O macro `_lalalalala_`.

3. **Debug integration**
   - If `ONLINE_JUDGE` is **not** defined, it includes `bits/bug.hpp` and enables `debug(...)`.
   - If `ONLINE_JUDGE` is defined, debug macros become empty (zero output overhead).

4. **I/O helpers**
   - Overloaded stream operators for pairs/vectors/generic iterable containers.
   - Variadic `print(...)` helper for quick output.

5. **Constants**
   - `INF`, `MOD`, `EPS` are globally available.

6. **Solve pattern**
   - `solve(ll tc)` currently reads `N`, then array `A`, and calls `debug(A)`.
   - `main()` reads test count `t` and runs the loop for each testcase.

## `bits/` and Precompiled Header (PCH)

### `bits/stdc++.h`

- Local copy of the standard competitive-programming umbrella header (many STL/C headers in one include).
- Used by your template as `#include "bits/stdc++.h"`.

### `bits/bug.hpp`

- Advanced debug printer utilities (containers, pairs/tuples, stacks/queues, etc.).
- Wrapped by `ONLINE_JUDGE` checks so debug output can be compiled out for submission.
- Uses C++20 features (`concept`/`requires`), so compile with C++20.

### Precompiling `bits/stdc++.h`

From repository root:

```bash
g++ -std=c++20 -x c++-header bits/stdc++.h -o bits/stdc++.h.gch
```

Then compile normally (compiler will pick `.gch` automatically when available):

```bash
g++ -std=c++20 -O2 -I. main.cpp -o main
```

For online-judge style build (debug disabled):

```bash
g++ -std=c++20 -O2 -DONLINE_JUDGE -I. main.cpp -o main
```

If you update `bits/stdc++.h`, regenerate `bits/stdc++.h.gch`.
