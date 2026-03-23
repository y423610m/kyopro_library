# Test Suite

This directory contains test cases for all the libraries in this competitive programming library.

## Running Tests

### Using pixi (recommended)

```bash
pixi run test
```

### Using the test runner script

```bash
./run_tests.sh
```

### Using pytest (requires pytest installed)

```bash
python3 -m pytest test_runner.py -v
```

### Manual compilation

To compile and run a specific test:

```bash
g++ -std=c++17 -O2 -I. test/structure/test_segtree.cpp -o test_segtree && ./test_segtree
```

## Test Categories

- **structure**: Data structure tests (segtree, union_find, trie, etc.)
- **dp**: Dynamic programming tests (LIS, LCS, edit_distance, LCP)
- **graph**: Graph algorithm tests (Dijkstra, Kruskal, Bellman-Ford)
- **math**: Math algorithm tests (Matrix, Combination)
- **string**: String algorithm tests (RollingHash)
- **sort**: Sorting algorithm tests (BubbleSort, MergeSort)
- **others**: Other utility tests (MyHash, Timer)
