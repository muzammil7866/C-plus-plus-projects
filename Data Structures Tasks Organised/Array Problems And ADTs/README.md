# Array Problems And ADTs

## Overview
This folder contains 8 C++ programs focusing on array manipulation, dynamic array implementations, and array-based algorithms. Programs range from basic array operations to advanced abstractions like Abstract Data Types (ADTs).

## Subfolders & Concepts

### 1. **Dynamic Array ADTs** - Abstract Data Type Implementations
Programs that implement array ADTs with encapsulation and memory management.
- Dynamic allocation of arrays
- Resizing strategies
- ADT interface design
- Memory cleanup and destructors

**Use Cases:** Understanding how libraries implement dynamic containers (like std::vector)

---

### 2. **Array Rearrangement** - Element Reorganization Algorithms
Programs focusing on rearranging array elements based on specific criteria.
- Segregating elements (even/odd, positive/negative)
- In-place rearrangement
- Rotation operations
- Custom sorting criteria

**Use Cases:** Interview questions, data preprocessing, partitioning algorithms

---

### 3. **Array Statistics** - Statistical Calculations
Programs computing statistical measures from array data.
- Mean (average)
- Median (middle value)
- Mode (most frequent)
- Standard deviation
- Variance

**Key Algorithm:** Single-pass vs. multi-pass algorithms, handling edge cases

---

### 4. **Polynomial and Sequence Problems** - Mathematical Array Operations
Programs dealing with polynomial arithmetic and sequence operations.
- Polynomial addition/multiplication
- Coefficient storage and manipulation
- Sequence generation
- Mathematical transformations

**Applications:** Signal processing, algebra systems, numerical computing

---

### 5. **Searching and Sorting** - Core Array Search/Sort Algorithms
Implementations of fundamental searching and sorting algorithms.
- Linear search
- Binary search (requires sorted array)
- Bubble sort, selection sort, insertion sort (O(n²))
- Quick sort, merge sort (O(n log n))

**Study Focus:** Algorithm complexity, implementation details, when to use which algorithm

---

### 6. **String Matrix Experiments** - 2D Array and String Operations
Programs working with 2D arrays and string matrices.
- 2D array manipulation
- String storage in matrices
- Matrix transformations
- Multi-dimensional operations

**Concept:** Extension of 1D arrays to higher dimensions

---

## File Count & Statistics

| Subcategory | Typical File Count | Complexity Level |
|---|---|---|
| Dynamic Array ADTs | 1-2 | Intermediate |
| Array Rearrangement | 1-2 | Intermediate |
| Array Statistics | 1-2 | Beginner |
| Polynomial Operations | 1-2 | Intermediate |
| Searching & Sorting | 1-2 | Beginner to Intermediate |
| String Matrix | 1-2 | Beginner |

**Total Files: 8**

---

## Key Algorithms & Concepts

### Time Complexity Reference
| Operation | Time | Notes |
|---|---|---|
| Linear Search | O(n) | Unsorted arrays |
| Binary Search | O(log n) | Sorted arrays only |
| Bubble Sort | O(n²) | Simple, rarely used in practice |
| Quick Sort | O(n log n) avg | Most commonly used |
| Merge Sort | O(n log n) | Guaranteed, stable |
| Array Resize | O(n) | Copying all elements |

### Space Complexity
- **In-place algorithms:** O(1) extra space
- **Merge sort:** O(n) extra space needed
- **Dynamic arrays:** O(n) for current capacity

---

## Learning Path for This Folder

### Level 1: Beginner
1. Study `Array Statistics` for basic array traversal
2. Learn `Searching and Sorting` - linear and binary search
3. Understand simple sorting (bubble, selection, insertion)

### Level 2: Intermediate
1. Study `Dynamic Array ADTs` for memory management
2. Learn `Array Rearrangement` algorithms
3. Understand advanced sorting (quick sort, merge sort)

### Level 3: Advanced
1. Study `Polynomial and Sequence Problems` for mathematical applications
2. Explore `String Matrix Experiments` for 2D operations
3. Optimize algorithms for specific constraints

---

## Common Interview Questions

### Easy
- Find maximum/minimum in array
- Search for element (linear & binary)
- Reverse array in-place
- Rotate array

### Medium
- Find median of sorted arrays
- Segregate positive/negative numbers
- Polynomial addition
- Find kth largest element

### Hard
- Optimize for specific time/space constraints
- Handle edge cases gracefully
- Design custom ADT with specific requirements

---

## Program Structure Example

```cpp
// Typical array program structure:
#include <iostream>
using namespace std;

int main() {
    // 1. Input: Create/read array
    int arr[] = {5, 2, 8, 1, 9};
    int n = 5;
    
    // 2. Process: Apply algorithm
    // sorting, searching, statistics, etc.
    
    // 3. Output: Display results
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
```

---

## Compilation & Testing

### Compile Single File:
```bash
g++ -std=c++11 filename.cpp -o output
./output
```

### Test with Different Inputs:
```bash
# Small array test
echo "3" | ./output

# Large array test
# Create test file with array size and elements
```

---

## Common Modifications & Exercises

1. **Modify input size:** Change array dimensions
2. **Add bounds checking:** Prevent out-of-bounds access
3. **Performance testing:** Time large arrays
4. **Error handling:** Handle invalid inputs
5. **Algorithm variants:** Compare different approaches

---

## Memory Management Notes

### Dynamic Arrays:
```cpp
int* arr = new int[size];   // Allocation
// ... use array
delete[] arr;               // Deallocation (note: [])
```

### Key Points:
- Always `delete[]` for arrays (not just `delete`)
- Avoid memory leaks by cleaning up in all code paths
- Use const for read-only data

---

## Tips for Understanding

1. **Draw it out:** Visualize array transformations on paper
2. **Trace execution:** Follow algorithm step-by-step with sample data
3. **Modify and test:** Change one thing and observe effects
4. **Compare approaches:** Understand trade-offs between algorithms
5. **Optimize:** Reduce operations for better performance

---

## Related Topics

- **Linked Lists:** Dynamic data structure alternative
- **Vectors:** C++ standard library dynamic array (std::vector)
- **Advanced Algorithms:** Dynamic programming uses arrays as foundation
- **Matrix Operations:** 2D arrays in linear algebra

---

## Summary

This folder provides essential foundation knowledge:
- ✓ Array basics and operations
- ✓ Searching and sorting fundamentals
- ✓ Dynamic memory management
- ✓ Algorithm complexity analysis
- ✓ Statistical computations

**Master these concepts before moving to linked lists and advanced data structures.**

---

**Difficulty Level:** Beginner to Intermediate  
**Prerequisite Knowledge:** Basic C++ (variables, loops, functions)  
**Next Topic:** Linked List Applications  

Last Updated: 2026-03-11
