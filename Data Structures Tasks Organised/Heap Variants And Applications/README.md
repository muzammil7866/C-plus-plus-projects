# Heap Variants And Applications

## Overview
This folder contains 6 C++ programs implementing heap data structures and their practical applications. Heaps are specialized binary trees used for priority-based processing and efficient retrieval of minimum/maximum elements.

## Subfolders & Concepts

### 1. **Core Heap Variants** - Fundamental Heap Implementations
Different types of heaps and their properties.

**Min Heap:**
- Parent ≤ Children
- Smallest element at root
- Used for minimum priority operations
- Complete binary tree structure

**Max Heap:**
- Parent ≥ Children
- Largest element at root
- Used for maximum priority operations
- Often used for sorting (heapsort)

**Key Operations:**
- Insert: Add to end, "bubble up" (O(log n))
- Delete min/max: Remove root, bubble down (O(log n))
- Heapify: Convert array to heap (O(n))
- Peek: Get root without removing (O(1))

**Use Cases:** Priority queues, heapsort, median finding

---

### 2. **Application Systems** - Real-World Heap Applications
Practical systems using heaps for priority-based processing.

**Event Scheduling:**
- Events with different priorities
- Process highest priority first
- Common in simulations and operating systems

**Patient Admission:**
- Emergency vs regular patients
- Critical patients processed first
- Hospital management systems

**Other Applications:**
- CPU scheduling
- Huffman coding
- Dijkstra's shortest path
- A* pathfinding

**Use Cases:** Simulation systems, resource allocation, scheduling

---

## File Count & Statistics

| Subcategory | Focus | Difficulty |
|---|---|---|
| Core Heap Variants | Min/max heaps | Intermediate |
| Application Systems | Real-world usage | Intermediate to Advanced |

**Total Files: 6**

---

## Heap Terminology

| Term | Definition |
|---|---|
| **Heap Property** | Relationship between parent and children |
| **Complete Binary Tree** | All levels filled, last level left-justified |
| **Bubble Up (Sift Up)** | Move element up to maintain heap property |
| **Bubble Down (Sift Down)** | Move element down to maintain heap property |
| **Heapify** | Convert unordered array to heap |
| **Priority Queue** | Queue where highest priority extracted first |
| **Left Child** | Index 2*i + 1 for element at index i |
| **Right Child** | Index 2*i + 2 for element at index i |
| **Parent** | Index (i-1)/2 for element at index i |

---

## Heap Operations Complexity

| Operation | Time | Space | Notes |
|---|---|---|---|
| Insert | O(log n) | O(n) | Bubble up from leaf |
| Delete Min/Max | O(log n) | O(n) | Bubble down from root |
| Peek | O(1) | O(n) | Just return root |
| Heapify | O(n) | O(n) | Bottom-up heapify |
| Heapsort | O(n log n) | O(1) | In-place sorting |

---

## Program Structure Example

### Min Heap Implementation:
```cpp
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void bubbleUp(int i) {
        while(i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void bubbleDown(int i) {
        while(leftChild(i) < heap.size()) {
            int smaller = leftChild(i);
            if(rightChild(i) < heap.size() && 
               heap[rightChild(i)] < heap[smaller]) {
                smaller = rightChild(i);
            }
            if(heap[i] < heap[smaller]) break;
            swap(heap[i], heap[smaller]);
            i = smaller;
        }
    }
    
public:
    void insert(int val) {
        heap.push_back(val);
        bubbleUp(heap.size() - 1);
    }
    
    int extractMin() {
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        bubbleDown(0);
        return min;
    }
};
```

---

## Learning Path

### Level 1: Beginner
1. Understand complete binary tree concept
2. Learn parent-child indexing
3. Implement basic min/max heap

### Level 2: Intermediate
1. Master insert and delete operations
2. Understand bubbling up/down
3. Implement heapify for array

### Level 3: Advanced
1. Study application systems
2. Implement priority queue
3. Optimize for specific use cases

---

## Min Heap vs Max Heap

| Aspect | Min Heap | Max Heap |
|---|---|---|
| **Root** | Smallest element | Largest element |
| **Parent-Child** | Parent ≤ Children | Parent ≥ Children |
| **Use** | Priority queue (ascending) | Priority queue (descending) |
| **Example** | Task scheduling (urgent first) | Huffman coding (frequent first) |
| **Extraction** | Extract minimum in O(log n) | Extract maximum in O(log n) |

---

## Common Interview Questions

### Easy
- What is a heap?
- Min heap vs max heap
- How to check if binary tree is heap?

### Medium
- Implement min heap with insert/delete
- Convert array to heap
- Find kth smallest/largest element

### Hard
- Merge k sorted lists using heap
- Median of data stream
- Design priority queue
- Huffman coding with heap

---

## Real-World Applications

| Application | Heap Type | Reason |
|---|---|---|
| Priority Queue | Min/Max | Access highest priority quickly |
| Event Simulation | Min (by time) | Process events in order |
| Heapsort | Min or Max | O(n log n) sorting |
| Dijkstra's Algorithm | Min | Extract nearest node |
| Huffman Coding | Max | Merge frequent nodes |
| Task Scheduling | Min (by deadline) | Critical tasks first |
| Load Balancing | Min (by load) | Assign to least loaded |

---

## Heapsort Example

```cpp
void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Build heap
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements one by one
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Time: O(n log n), Space: O(1)
```

---

## Compilation & Testing

```bash
g++ -std=c++11 filename.cpp -o heap_program
./heap_program

# Test with different priorities
# Observe insertion and extraction order
# Compare with standard priority_queue
```

---

## Common Patterns

### Priority Queue Pattern:
```cpp
#include <queue>
using namespace std;

int main() {
    // Max heap (default)
    priority_queue<int> maxHeap;
    
    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(8);
    
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";  // 2 5 8
        minHeap.pop();
    }
}
```

---

## Memory Considerations

### Array-Based Heap:
- No pointer overhead
- Cache-friendly
- Good locality
- Easy to resize

### Index Calculations:
- Parent: (i-1)/2
- Left: 2i+1
- Right: 2i+2
- Simple mathematics, no storage

---

## Optimization Techniques

1. **Bottom-up heapify:** O(n) instead of O(n log n)
2. **Lazy deletion:** Mark as deleted, remove later
3. **Binomial heaps:** Merge operation O(log n)
4. **Fibonacci heaps:** Better amortized complexity
5. **d-ary heaps:** Broader trees for cache efficiency

---

## Debugging Tips

1. **Visualize tree:** Draw heap structure
2. **Trace operations:** Follow bubble up/down
3. **Index mapping:** Verify parent-child calculations
4. **Heap property:** Check after each operation
5. **Array representation:** Ensure complete tree property

---

## Extension Ideas

1. **Implement Heapsort:** Use heap for sorting
2. **Fibonacci Heap:** Advanced merge-efficient heap
3. **Binomial Heap:** Union operation
4. **Pairing Heap:** Simpler than Fibonacci
5. **Treap:** Randomized BST with heap ordering

---

## Common Mistakes

1. **Wrong parent-child index:** Off-by-one errors
2. **Breaking heap property:** After insertion/deletion
3. **Not comparing correctly:** Min vs max confusion
4. **Array out of bounds:** Forgetting size checks
5. **Wrong heapify direction:** Top-down vs bottom-up

---

## Tips for Understanding

1. **Draw the tree:** Visualize heap structure
2. **Trace operations:** Mark elements during bubble
3. **Test with small data:** 5-10 elements first
4. **Verify heap property:** Check after each step
5. **Compare with sorting:** Understand heapsort

---

## Related Topics

- **Priority Queues:** Abstract data type using heaps
- **Sorting Algorithms:** Heapsort O(n log n)
- **Shortest Path:** Dijkstra uses min-heap
- **Huffman Coding:** Max-heap for frequent chars
- **Median Finding:** Two heaps (min + max)

---

## Summary

This folder covers heap fundamentals:
- ✓ Min and max heap properties
- ✓ Efficient insertion and deletion
- ✓ Array-based heap representation
- ✓ Heapify operations
- ✓ Priority queue implementation
- ✓ Real-world applications

**Essential for understanding priority queues and many advanced algorithms.**

---

**Difficulty Level:** Intermediate  
**Prerequisite:** Binary trees, array indexing  
**Applications:** Scheduling, Dijkstra, Huffman coding  

Last Updated: 2026-03-11
