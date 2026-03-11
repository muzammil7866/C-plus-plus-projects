# Recursive And Utility Exercises

## Overview
This folder contains 15 C++ programs focusing on recursive algorithms and utility functions. Topics range from string manipulation to mathematical algorithms, search/sort implementations, and matrix operations. These are essential algorithm patterns for mastering problem-solving.

## Subfolders & Concepts

### 1. **Recursive String Utilities** - Recursive String Operations
Recursive algorithms for manipulating and analyzing strings.

**Common Operations:**
- **String Reversal:** Reverse string recursively
- **Palindrome Checking:** Check if string reads same forward/backward
- **Character Extraction:** Find/extract specific characters
- **Pattern Matching:** Find substring patterns

**Recursion Pattern:**
```cpp
// Base case: empty string or single char
// Recursive case: process char + recurse on rest
```

**Key Insight:** Process one character, recurse on remaining string

---

### 2. **Recursive String Problems** - Complex String Analysis
More advanced recursive string algorithms.

**Problem Types:**
- **Permutations:** Generate all string permutations
- **Combinations:** Generate subsets of characters
- **Pattern Matching:** Find all occurrences
- **Compression:** Encode repeated characters

**Complexity:** Often O(n!) for exhaustive problems

---

### 3. **Recursive Number Utilities** - Mathematical Algorithms
Recursive implementations of mathematical operations.

**Classic Problems:**
- **GCD (Greatest Common Divisor):** Euclidean algorithm
- **Fibonacci:** Sequence generation
- **Factorial:** n! = n * (n-1)!
- **Prime Checking:** Divisibility testing
- **Power Computation:** x^n efficiently

**Key Pattern:**
```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

---

### 4. **Pointer Based Checks** - Pointer Dereferencing & Validation
Programs validating and working with pointers.

**Operations:**
- **Null Checking:** Verify pointer validity
- **Dereferencing:** Safe pointer access
- **Pointer Arithmetic:** Navigate memory
- **Validity Verification:** Check pointer before use

**Use Cases:** Data structure operations, dynamic memory access

---

### 5. **Search And Sorting Utilities** - Core Algorithms
Implementations of fundamental search and sort algorithms.

**Searching:**
- **Linear Search:** O(n), works on any array
- **Binary Search:** O(log n), requires sorted array
- **Interpolation Search:** O(log log n) for uniform distribution

**Sorting:**
- **Bubble Sort:** O(n²), simple, rarely used
- **Selection Sort:** O(n²), minimal swaps
- **Insertion Sort:** O(n²), adaptive for nearly sorted
- **Merge Sort:** O(n log n), stable, requires O(n) space
- **Quick Sort:** O(n log n) avg, O(n²) worst, in-place
- **Heap Sort:** O(n log n), in-place, not stable

**Complexity Reference:**
| Algorithm | Best | Average | Worst | Space |
|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Insertion | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |

---

### 6. **Matrix Utilities** - 2D Array Operations
Algorithms working with matrices and 2D arrays.

**Operations:**
- **Matrix Multiplication:** C[i][j] = Σ(A[i][k] * B[k][j])
- **Matrix Transpose:** Swap rows and columns
- **Matrix Addition:** Element-wise addition
- **Determinant Calculation:** For square matrices
- **Pattern Finding:** Search in 2D arrays

**Time Complexity Notes:**
- Matrix multiplication: O(n³) standard, O(n^2.37) advanced
- Matrix transpose: O(n²)

---

### 7. **String Utilities** - Specialized String Functions
General string manipulation and analysis utilities.

**Operations:**
- **String Tokenization:** Split by delimiter
- **Case Conversion:** Upper/lowercase
- **Trimming:** Remove leading/trailing spaces
- **Substringing:** Extract portions
- **String Matching:** Find patterns
- **Word Counting:** Count occurrences

---

## File Count & Statistics

| Subcategory | Files | Difficulty |
|---|---|---|
| Recursive String Utilities | 2 | Intermediate |
| Recursive String Problems | 2 | Intermediate |
| Recursive Number Utilities | 2-3 | Beginner to Intermediate |
| Pointer Based Checks | 1-2 | Beginner |
| Search And Sorting | 2-3 | Beginner to Intermediate |
| Matrix Utilities | 2 | Intermediate |
| String Utilities | 2 | Beginner |

**Total Files: 15**

---

## Recursive Algorithm Tips

### Recursion Structure:
```cpp
returnType recursiveFunction(parameters) {
    // 1. Base case(s) - where recursion stops
    if(baseCaseCondition) {
        return baseValue;
    }
    
    // 2. Recursive case - progress toward base case
    return combineResults(
        recursiveFunction(modifiedParameters)
    );
}
```

### Stack Depth Concerns:
- 1000+ recursion depth may cause stack overflow
- For very deep recursion, consider iteration
- Typical stack limit: 1 MB (varies by system)

---

## Learning Path

### Level 1: Beginner
1. Simple recursive math (factorial, Fibonacci)
2. Linear and binary search
3. Basic string operations
4. Insertion sort

### Level 2: Intermediate
1. Complex string recursion
2. Advanced sorting (merge, quick)
3. Matrix operations
4. Pointer validation

### Level 3: Advanced
1. Optimize recursive algorithms
2. Complex pattern matching
3. Efficient number algorithms
4. Cache-aware operations

---

## Common Interview Questions

### Easy
- Reverse a string (recursive)
- Palindrome check
- Linear and binary search
- Factorial and Fibonacci

### Medium
- String permutations
- GCD calculation
- Merge sort implementation
- Matrix multiplication
- Quicksort implementation

### Hard
- Complex string algorithms
- Optimize sorting for specific data
- Advanced matrix operations
- Memory-optimal recursion

---

## Real-World Applications

| Application | Algorithm |
|---|---|
| **Search Engines** | Binary search, pattern matching |
| **Database Indexing** | Merge sort, quick sort |
| **Compiler Design** | Recursion, tokenization |
| **Graphics** | Matrix multiplication |
| **Cryptography** | GCD, number theory |
| **String Matching** | KMP, Boyer-Moore (advanced) |
| **Data Compression** | Sorting, pattern finding |

---

## Code Examples

### Recursive Palindrome:
```cpp
bool isPalindrome(string s, int left, int right) {
    if(left >= right) return true;  // Base case
    if(s[left] != s[right]) return false;
    return isPalindrome(s, left + 1, right - 1);
}
// Time: O(n), Space: O(n) for recursion stack
```

### Binary Search:
```cpp
int binarySearch(vector<int>& arr, int target, 
                 int left, int right) {
    if(left > right) return -1;
    int mid = left + (right - left) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) 
        return binarySearch(arr, target, left, mid - 1);
    else 
        return binarySearch(arr, target, mid + 1, right);
}
// Time: O(log n), Space: O(log n) stack
```

### GCD (Euclidean Algorithm):
```cpp
int gcd(int a, int b) {
    if(b == 0) return a;  // Base case
    return gcd(b, a % b);  // Recursive case
}
// Time: O(log min(a,b)), Space: O(log n)
```

---

## Compilation & Testing

```bash
g++ -std=c++11 filename.cpp -o utility_program
./utility_program

# Test with:
# - Small inputs first
# - Edge cases (empty string, zero, negative)
# - Large inputs for performance
# - Special characters
```

---

## Memory & Performance

### Recursion Stack Space:
```cpp
// Each recursive call uses ~32-64 bytes
// n recursive calls = n * 32-64 bytes
// Typical stack: 1 MB
// Safe recursion depth: ~15,000
```

### Optimization Opportunities:
1. **Memoization:** Store computed results
2. **Tail Recursion:** Compiler may optimize to loop
3. **Iterative Alternative:** Often more efficient
4. **Algorithm Selection:** Choose best for data

---

## Extension Ideas

1. **Memoization:** Cache recursive results
2. **Dynamic Programming:** Iterative recursion
3. **Advanced Sorting:** Radix sort, counting sort
4. **String Algorithms:** KMP, Boyer-Moore
5. **Optimizations:** Cache-aware implementations

---

## Common Mistakes

1. **Missing base case:** Infinite recursion
2. **Wrong recursion progression:** Not approaching base case
3. **Stack overflow:** Too deep recursion
4. **Off-by-one errors:** Array index issues
5. **Efficiency:** Unnecessary recursive calls

---

## Debugging Tips

1. **Print recursion depth:** Track call stack
2. **Add base case assertions:** Verify stopping
3. **Trace small input:** Simple case by hand
4. **Memory monitoring:** Watch stack usage
5. **Compare recursive/iterative:** Verify correctness

---

## Algorithm Selection Guide

| Problem | Algorithm | Reason |
|---|---|---|
| **Known size, random keys** | Quick sort | Fast average case |
| **Stability needed** | Merge sort | Guaranteed stability |
| **Nearly sorted** | Insertion sort | Adaptive O(n) |
| **Fixed memory** | Heap sort | O(1) extra space |
| **Searching sorted** | Binary search | O(log n) |

---

## Related Topics

- **Dynamic Programming:** Optimize recursion
- **Sorting Networks:** Parallel sorting
- **String Matching:** Pattern algorithms (KMP)
- **Numerical Methods:** Recursive algorithms
- **Graph Algorithms:** DFS/BFS use recursion

---

## Summary

This folder covers essential algorithms:
- ✓ Recursive problem solving
- ✓ String manipulation and analysis
- ✓ Mathematical algorithms
- ✓ Searching and sorting
- ✓ Matrix operations
- ✓ Pointer operations and validation

**Master these for interview preparation and problem-solving.**

---

**Difficulty Level:** Beginner to Intermediate  
**Prerequisite:** Basic C++, recursion, arrays  
**Applications:** Problem-solving, algorithms, system design  

Last Updated: 2026-03-11
