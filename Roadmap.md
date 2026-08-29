# Codeforces Candidate Master — Topic Checklist

## Data Structures

- Arrays, prefix sums, difference arrays, 2D prefix sums 🟡 (2D prefix sums done via `LIBRARY/misc/prefix_sum_2d.cpp`; plain 1D prefix sum / difference array not in library)
- Sorting, binary search (on answer too)
- Two pointers, sliding window
- Stacks, queues, deques (monotonic stack/queue)
- Sets, maps, hashing (custom hash for CF anti-hack)
- Segment tree (point/range update, range query), lazy propagation ✅ (`seg_tree.cpp`, `seg_lazy.cpp`)
- Fenwick tree (BIT), BIT for range update/range query, 2D BIT 🟡 (`fenTree.cpp`, `binJmp_fenwickTree.cpp` cover point update/range sum; range-update BIT and 2D BIT missing)
- Sparse table (RMQ) ✅ (`sparse_table.cpp`)
- Disjoint Set Union (path compression + union by rank), DSU on tree 🟡 (`dsu.cpp` done; DSU on tree missing)
- Trie (including bitwise trie for XOR problems) 🟡 (`trie.cpp` done for strings; bitwise trie missing)
- Persistent segment tree (light exposure)
- Ordered set / policy tree (GNU PBDS)

## Graphs

- BFS, DFS, connected components ✅ (`bfs.cpp`, `dfs.cpp`)
- Topological sort ✅ (`topoSort.cpp`)
- Dijkstra, Bellman-Ford, Floyd-Warshall
- MST: Kruskal, Prim
- Bipartite check ✅ (`bipartitie.cpp`)
- Bridges and articulation points
- SCC (Tarjan/Kosaraju)
- LCA (binary lifting), Euler tour on trees ✅ (`lca.cpp`, `bin_jmp.cpp`, `eularTour.cpp`)
- Tree DP, rerooting technique
- 0-1 BFS
- Basic flow concepts (Ford-Fulkerson/Edmonds-Karp) — awareness level

## Dynamic Programming

- Knapsack (0/1, unbounded)
- LIS, LCS and variants
- DP on subsets (bitmask DP)
- Digit DP ✅ (`digitdp.cpp`)
- DP on trees
- DP with bitmask + broken profile (light exposure)
- Convex hull trick / divide and conquer optimization (light exposure)
- Matrix exponentiation for linear recurrences 🟡 (`matrix.cpp` exists but is incomplete — missing return, needs a fix before use)

## Math

- Modular arithmetic, modular inverse (Fermat's little theorem, extended Euclid) 🟡 (`binomial.cpp` covers Fermat-based inverse; extended Euclid missing)
- GCD/LCM, extended Euclidean algorithm
- Sieve of Eratosthenes, prime factorization 🟡 (`seieve.cpp` covers the sieve/prime list; factorization via `get()` is broken — smallest-prime-factor storage is commented out)
- Combinatorics: nCr mod p, Pascal's triangle, permutations ✅ (`binomial.cpp`, `pascal.cpp`)
- Basic probability/expected value
- Fast exponentiation ✅ (`binpow.cpp`)
- Number theory: Euler's totient, divisor functions 🟡 (`harmonic.cpp` covers divisor counting; totient missing)
- Inclusion-exclusion principle

## Strings

- String hashing (polynomial rolling hash)
- KMP algorithm ✅ (`KMP.cpp`)
- Z-function
- Trie for strings ✅ (`trie.cpp`)
- Manacher's algorithm (light exposure)

## Greedy

- Interval scheduling, interval merging
- Exchange argument style greedy proofs

## Other Core Techniques

- Binary search on answer
- Two-pointer/sliding window optimization
- Coordinate compression ✅ (`coordinate_cmp.cpp`)
- Meet in the middle
- Divide and conquer (general paradigm)
- Amortized complexity intuition (for stacks/queues/DSU)
