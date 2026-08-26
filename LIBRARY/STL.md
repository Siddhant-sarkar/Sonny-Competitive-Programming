# Advanced STL Structures — Complete Reference

> Source: [Nourhan_Abo-Heba on Codeforces](https://codeforces.com/blog/entry/146139)

---

## Table of Contents
1. [Iterators & Vectors](#1-iterators--vectors)
2. [lower_bound & upper_bound](#2-lower_bound--upper_bound)
3. [Binary Search Tree (BST) — Theory](#3-binary-search-tree-bst--theory)
4. [set](#4-set)
5. [multiset](#5-multiset)
6. [map](#6-map)
7. [priority_queue](#7-priority_queue)
8. [Custom Comparators](#8-custom-comparators)
9. [Comparison Table](#9-comparison-table)
10.[Common Patterns](#10-common-patterns)

---

## 1. Iterators & Vectors

Iterators are like pointers that let you navigate through containers.

```cpp
vector<int> v = {1, 2, 3, 4, 5};

auto it  = v.begin();   // points to first element
auto end = v.end();     // points AFTER last element

sort(v.begin(), v.end());   // sort entire vector
v.end() - v.begin();        // size of vector
```

### Key Facts
| Expression | Meaning |
|---|---|
| `v.begin()` | iterator to first element |
| `v.end()` | iterator **after** last element (not the last element itself!) |
| `v.size()` | equals `v.end() - v.begin()` |
| `v.rbegin()` | reverse iterator to last element |
| `v.rend()` | reverse iterator before first element |

### Common Vector Operations
```cpp
vector<int> v;

v.push_back(x);         // append to end — O(1) amortized
v.pop_back();           // remove last — O(1)
v.front();              // first element
v.back();               // last element
v.size();               // number of elements
v.empty();              // true if size == 0
v.clear();              // remove all elements
v.resize(n);            // resize to n elements
v.assign(n, val);       // fill with n copies of val

// Insert / erase (expensive — O(n) shift)
v.insert(v.begin() + i, val);
v.erase(v.begin() + i);
v.erase(v.begin() + l, v.begin() + r);  // erase range [l, r)
```

### Range Formula
Count of integers in `[l, r]` = `r - l + 1`

This appears constantly in binary search, range queries, and coordinate compression.

```cpp
// How many integers from 5 to 10 inclusive?
int count = 10 - 5 + 1;  // = 6  →  {5, 6, 7, 8, 9, 10}
```

---

## 2. lower_bound & upper_bound

> **Must be used on a sorted container.**

```cpp
vector<int> v = {1, 3, 3, 5, 7, 9};

auto it1 = lower_bound(v.begin(), v.end(), 3);  // first element >= 3
auto it2 = upper_bound(v.begin(), v.end(), 3);  // first element >  3
```

### Visual
```
Array:  [ 1,  3,  3,  5,  7,  9 ]
                ↑           ↑
         lower_bound(3)   upper_bound(3)
```

### Query Table
| Query | Code |
|---|---|
| How many numbers `< x` | `lower_bound(v.begin(), v.end(), x) - v.begin()` |
| How many numbers `≤ x` | `upper_bound(v.begin(), v.end(), x) - v.begin()` |
| How many numbers `≥ x` | `v.end() - lower_bound(v.begin(), v.end(), x)` |
| How many numbers `> x` | `v.end() - upper_bound(v.begin(), v.end(), x)` |
| Count in range `[L, R]` | `upper_bound(..., R) - lower_bound(..., L)` |

### Complete Example
```cpp
vector<int> v = {1, 3, 3, 5, 7, 9};
sort(v.begin(), v.end());  // ensure sorted

// Count numbers in range [3, 7]
int count = upper_bound(v.begin(), v.end(), 7)
          - lower_bound(v.begin(), v.end(), 3);
// Result: 4  →  {3, 3, 5, 7}
```

---

## 3. Binary Search Tree (BST) — Theory

Understanding BSTs helps you understand `set` and `map` internals.

### Structure
- Each node has: parent, left child, right child
- **BST Property:** `left < parent < right`

```
        5
       / \
      3   8
     / \   \
    1   4   9
```

### Complexity
| Operation | Array | BST (balanced) | BST (worst case) |
|---|---|---|---|
| Search | O(n) | O(log n) | O(n) |
| Insert | O(1) | O(log n) | O(n) |
| Delete | O(n) | O(log n) | O(n) |

C++ uses **Red-Black Trees** (self-balancing BSTs) to guarantee O(log n) for all operations.

---

## 4. set

Stores **unique, sorted** elements using a balanced BST.

```cpp
set<int> st;
st.insert(6);
st.insert(3);
st.insert(5);
st.insert(1);
st.insert(3);  // duplicate — ignored

for (auto x : st)
    cout << x << " ";  // Output: 1 3 5 6
```

### Key Operations
```cpp
set<int> st = {1, 3, 5, 7, 9};

// Search — O(log n)
auto it = st.find(5);
if (it != st.end()) cout << "Found: " << *it;

// Insert — O(log n)
st.insert(4);

// Erase — O(log n)
st.erase(3);           // erase by value
st.erase(st.find(5));  // erase by iterator

// Min / Max
int mn = *st.begin();   // smallest
int mx = *st.rbegin();  // largest  (also: *(--st.end()))

// Bounds
auto lo = st.lower_bound(4);  // first element >= 4
auto hi = st.upper_bound(4);  // first element >  4
```

### Important Limitations
- **No indexing** — `st[2]` does **not** work
- **No random access** — cannot jump to middle element directly

### Make a Vector Distinct
```cpp
vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5};

// Method 1: via set
set<int> st(v.begin(), v.end());
v.assign(st.begin(), st.end());

// Method 2: sort + unique (faster)
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

---

## 5. multiset

Same as `set`, but **allows duplicates**.

```cpp
multiset<int> ms = {1, 2, 3, 4, 4, 4, 5, 5};

ms.insert(4);       // now 4 copies of 4
ms.erase(4);        // WARNING: erases ALL 4's!
ms.erase(ms.find(4)); // erases only ONE 4
```

### Critical Difference
```cpp
multiset<int> ms = {1, 2, 2, 2, 3};

ms.erase(2);              // removes ALL 2's  → {1, 3}
ms.erase(ms.find(2));     // removes ONE 2    → {1, 2, 2, 3}
```

### Count Occurrences
```cpp
multiset<int> ms = {1, 2, 2, 2, 3};
int cnt = ms.count(2);    // O(log n + k), k = count
```

### Advanced: Find Second Greater Element
```cpp
multiset<int> ms = {1, 3, 5, 7, 9};

int secondGreater(int x) {
    auto it = ms.upper_bound(x);    // first element > x
    if (it == ms.end()) return -1;

    it = ms.upper_bound(*it);       // second element > x
    if (it == ms.end()) return -1;

    return *it;
}
// secondGreater(3) → 7
```

---

## 6. map

Stores **key → value** pairs, sorted by key.

```cpp
map<string, int> mp;

mp["apple"]  = 5;
mp["banana"] = 10;
mp.insert({"cherry", 15});

for (auto [key, value] : mp)
    cout << key << " → " << value << "\n";
// Output (sorted by key):
// apple → 5
// banana → 10
// cherry → 15
```

### Key Operations
```cpp
map<string, int> mp;

mp["apple"] = 5;
cout << mp["banana"];   // 0 (default-constructs if missing)

// Check existence — prefer find() to avoid ghost insertions
if (mp.find("apple") != mp.end()) cout << "Found";
if (mp.count("apple"))            cout << "Found";

// Erase
mp.erase("apple");

// First / last
auto first = mp.begin();
cout << first->first << " → " << first->second;

auto last = mp.rbegin();
cout << last->first << " → " << last->second;
```

### lower_bound / upper_bound on Maps
```cpp
map<int, string> mp = {{1,"a"}, {5,"b"}, {9,"c"}};

auto it  = mp.lower_bound(4);  // iterator to {5,"b"}
auto it2 = mp.upper_bound(5);  // iterator to {9,"c"}
```
These work on **keys**, not values.

### Default Values
```cpp
map<int, int> freq;
freq[5]++;               // starts at 0, becomes 1

map<int, vector<int>> adj;
adj[3].push_back(7);     // creates empty vector first
```

---

## 7. priority_queue

A heap that always exposes the largest (or smallest) element in O(1).

### Max Heap (Default)
```cpp
priority_queue<int> pq;

pq.push(5);
pq.push(2);
pq.push(8);
pq.push(1);

cout << pq.top();  // 8
pq.pop();
cout << pq.top();  // 5
```

### Min Heap
```cpp
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(5);
pq.push(2);
pq.push(8);

cout << pq.top();  // 2
```

### When to Use
| Problem Type | Heap Type |
|---|---|
| Dijkstra's algorithm | min heap of `{dist, node}` |
| Greedy (process smallest first) | min heap |
| Greedy (process largest first) | max heap |
| Event simulation | min heap by time |

---

## 8. Custom Comparators

### For sort()
```cpp
// Sort pairs by second element descending
vector<pair<int,int>> v = {{1,3},{2,1},{3,2}};
sort(v.begin(), v.end(), [](auto& a, auto& b){
    return a.second > b.second;
});
```

### For set / multiset
```cpp
// set sorted by absolute value
auto cmp = [](int a, int b){ return abs(a) < abs(b); };
set<int, decltype(cmp)> st(cmp);

st.insert(-3);
st.insert(1);
st.insert(-5);
// stored as: 1, -3, -5  (by |value|)
```

### For priority_queue
```cpp
// Min heap of pairs sorted by second element
auto cmp = [](pair<int,int>& a, pair<int,int>& b){
    return a.second > b.second;   // greater → min heap
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

pq.push({1, 10});
pq.push({2, 5});
pq.push({3, 15});

auto top = pq.top();  // {2, 5}  (smallest second element)
```

### Using a Struct with operator<
```cpp
struct Node {
    int dist, id;
    bool operator>(const Node& o) const { return dist > o.dist; }
};

priority_queue<Node, vector<Node>, greater<Node>> pq;  // min heap by dist
```

---

## 9. Comparison Table

| Structure | Duplicates | Sorted | Top Access | Insert | Search | Best For |
|---|---|---|---|---|---|---|
| `vector` | Yes | No | O(1) | O(1) amortized | O(n) | General purpose |
| `set` | No | Yes | O(log n) | O(log n) | O(log n) | Unique sorted elements |
| `multiset` | Yes | Yes | O(log n) | O(log n) | O(log n) | Sorted with duplicates |
| `map` | No (keys) | Yes | O(log n) | O(log n) | O(log n) | Key-value pairs |
| `priority_queue` | Yes | Partial | O(1) top | O(log n) | O(n) | Max/min queries |

---

## 10. Common Patterns

### Pattern 1: Frequency Map
```cpp
map<int, int> freq;
for (int x : arr)
    freq[x]++;

int max_freq = 0;
for (auto [val, cnt] : freq)
    max_freq = max(max_freq, cnt);
```

### Pattern 2: Sliding Window with Set
```cpp
// Find if any subarray of size k has all distinct elements
set<int> window;
for (int i = 0; i < n; i++) {
    window.insert(arr[i]);
    if (i >= k) window.erase(arr[i - k]);

    if ((int)window.size() == k)
        cout << "Found at index " << i - k + 1 << "\n";
}
```

### Pattern 3: Closest Element with lower_bound
```cpp
set<int> st = {1, 5, 10, 15, 20};
int x = 12;

auto it = st.lower_bound(x);

int closest;
if (it == st.end()) {
    closest = *prev(it);          // all elements < x
} else if (it == st.begin()) {
    closest = *it;                // all elements >= x
} else {
    int right = *it;
    int left  = *prev(it);
    closest = (x - left < right - x) ? left : right;
}
```

### Pattern 4: Multiset as Sorted Bag (greedy)
```cpp
// Assign tasks greedily: each task needs capacity >= required
multiset<int> capacities = {3, 5, 7, 10};

for (int req : tasks) {
    auto it = capacities.lower_bound(req);  // smallest capacity >= req
    if (it == capacities.end()) {
        cout << "Impossible\n";
    } else {
        capacities.erase(it);               // use this capacity
    }
}
```

### Pattern 5: Dijkstra with Min Heap
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
vector<int> dist(n, INT_MAX);

dist[src] = 0;
pq.push({0, src});

while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;             // stale entry

    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
```

---

## Practice Problems

| Difficulty | Problem | Key Concept |
|---|---|---|
| Easy | CSES — Apartments | Two pointers + sorting |
| Easy | CSES — Concert Tickets | multiset |
| Easy | CSES — Sum of Two Values | map or two pointers |
| Medium | CSES — Movie Festival | Greedy + sorting |
| Medium | CSES — Towers | multiset + greedy |
| Medium | CSES — Traffic Lights | set + multiset combo |

---

## Quick Summary

| Tool | Superpower |
|---|---|
| `lower_bound` / `upper_bound` | Binary search on sorted containers |
| `set` | Unique + sorted elements in O(log n) |
| `multiset` | Sorted + allows duplicates; use `find()` to erase one |
| `map` | Key-value pairs sorted by key |
| `priority_queue` | Always access max/min in O(1) |
| Custom comparator | Control ordering for any container or algorithm |

> Next topics: `unordered_set`, `unordered_map`, STL algorithms (`next_permutation`, `accumulate`, `partial_sum`)
