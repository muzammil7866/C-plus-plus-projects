# Queue Implementations

## Overview
This folder contains 6 C++ programs implementing various queue data structures and designs. Queues follow FIFO (First-In-First-Out) principle and are fundamental for many real-world applications including scheduling, simulation, and breadth-first search.

## Subfolders & Concepts

### 1. **Array Queue Variants** - Fixed-Size Queue Implementations
Queues implemented using arrays with different design approaches.

**Simple Array Queue:**
- Fixed size array
- Front and rear pointers/indices
- Elements shift forward on dequeue
- Performance: Dequeue O(n) due to shifting

**Circular Array Queue:**
- Fixed size array used circularly
- Front and rear wrap around
- No shifting needed
- Performance: All operations O(1)

**Fixed-Size Limitations:**
- Can't grow beyond capacity
- Requires pre-allocation
- Risk of overflow

**Use Cases:** Embedded systems, real-time systems with bounded data

---

### 2. **Circular Queues** - Wraparound Index Design
Queue implementations using circular indexing to maximize efficiency.

**Circular Mechanism:**
- Indices wrap using modulo: (index + 1) % capacity
- Last position connects to first
- No unused space unlike linear arrays

**Circular Queue Operations:**
```
Enqueue: rear = (rear + 1) % capacity
Dequeue: front = (front + 1) % capacity
```

**Full/Empty Detection:**
- If front == rear: empty
- If (rear + 1) % capacity == front: full
- Or maintain separate count

**Advantages:**
- O(1) for all operations
- No space wastage with wraparound
- Cache-friendly

---

### 3. **Hybrid Queue Designs** - Combinations & Variations
Non-standard queue implementations and specialized designs.

**Queue with Dynamic Resizing:**
- Start with fixed size
- Grow when full
- Shrink when mostly empty

**Deque (Double-Ended Queue):**
- Insert/delete at both ends
- More flexible than standard queue
- O(1) operations at both ends

**Priority Queue:**
- Elements have priorities
- Higher priority extracted first
- Often implemented with heaps

**Multiple Queues:**
- Separate queues for different priorities
- Interleaved processing

---

### 3. **Deque Designs** - Double-Ended Queue
Complete implementations of double-ended queues.

**Deque Operations:**
- insertFront(x): Add at front
- insertRear(x): Add at rear
- deleteFront(): Remove from front
- deleteRear(): Remove from rear
- getFront(): Get front element
- getRear(): Get rear element

**Implementation Approaches:**
- Circular array (most efficient)
- Doubly linked list (simple)
- Block-based (std::deque approach)

**Use Cases:** Sliding window problems, undo/redo systems, restaurant queues with priorities

---

## File Count & Statistics

| Subcategory | Files | Complexity |
|---|---|---|
| Array Queue Variants | 2 | Beginner |
| Circular Queues | 2 | Beginner to Intermediate |
| Hybrid Queue Designs | 1-2 | Advanced |
| Deque Designs | 1-2 | Intermediate |

**Total Files: 6**

---

## Queue Terminology

| Term | Definition |
|---|---|
| **FIFO** | First-In-First-Out ordering |
| **Enqueue** | Add element to rear |
| **Dequeue** | Remove element from front |
| **Front** | Where elements are removed |
| **Rear** | Where elements are added |
| **Queue Full** | No space for new element |
| **Queue Empty** | No elements to remove |
| **Circular** | Last position connects to first |

---

## Complexity Analysis

| Operation | Array | Circular | Linked List | Deque |
|---|---|---|---|---|
| Enqueue | O(1) | O(1) | O(1) | O(1) |
| Dequeue | O(n)* | O(1) | O(1) | O(1) |
| Peek | O(1) | O(1) | O(1) | O(1) |
| Space | O(n) | O(n) | O(n) | O(n) |

*Without circular wraparound, elements must shift

---

## Program Structure Example

### Simple Array Queue:
```cpp
class Queue {
    vector<int> arr;
    int front = 0, rear = -1;
    
public:
    void enqueue(int x) {
        arr.push_back(x);
        rear++;
    }
    
    int dequeue() {
        if(front > rear) return -1;
        return arr[front++];  // O(1) but wastes space
    }
};
```

### Circular Array Queue:
```cpp
class CircularQueue {
    vector<int> arr;
    int front = 0, rear = -1;
    int capacity;
    
public:
    void enqueue(int x) {
        rear = (rear + 1) % capacity;
        arr[rear] = x;
    }
    
    int dequeue() {
        if(front == (rear + 1) % capacity) return -1;
        int val = arr[front];
        front = (front + 1) % capacity;
        return val;  // O(1) with wraparound
    }
};
```

### Deque:
```cpp
class Deque {
    deque<int> dq;
    
public:
    void insertFront(int x) { dq.push_front(x); }
    void insertRear(int x) { dq.push_back(x); }
    int deleteFront() { 
        int x = dq.front(); 
        dq.pop_front(); 
        return x; 
    }
    int deleteRear() { 
        int x = dq.back(); 
        dq.pop_back(); 
        return x; 
    }
};
```

---

## Learning Path

### Level 1: Beginner
1. Understand FIFO principle
2. Implement simple array queue
3. Understand circular wraparound

### Level 2: Intermediate
1. Implement circular queue
2. Implement linked list queue
3. Compare space/time trade-offs

### Level 3: Advanced
1. Implement deques
2. Dynamic resizing strategies
3. Hybrid designs for specific needs

---

## Real-World Applications

| Application | Queue Type | Reason |
|---|---|---|
| **CPU Scheduling** | Priority Queue | Different priority processes |
| **Printer Queue** | Standard Queue | Print jobs in order |
| **BFS Traversal** | Simple Queue | Level-order exploration |
| **Network Buffers** | Circular Queue | Fixed bandwidth |
| **Restaurant** | Deque | VIPs can be served first |
| **Sliding Window** | Deque | Min/max in window |
| **Undo/Redo** | Deque | Navigate backward/forward |

---

## Common Interview Questions

### Easy
- Implement queue with two stacks
- Implement circular queue
- Check if queue is empty

### Medium
- Implement deque
- Sliding window maximum (with deque)
- Circular queue with dynamic resizing
- Queue reconstruction by height

### Hard
- Serialize/deserialize queue
- Queue with dynamic resizing
- Optimized for specific access pattern
- Multiple queue management

---

## Common Patterns

### BFS using Queue:
```cpp
void bfs(int start) {
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        process(node);
        
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

### Sliding Window Maximum (Deque):
```cpp
vector<int> slideMaximum(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    
    for(int i = 0; i < arr.size(); i++) {
        // Remove elements outside window
        while(!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements
        while(!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if(i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}  // Time: O(n), Space: O(k)
```

---

## Memory Considerations

### Circular Array:
- Fixed pre-allocated memory
- No dynamic allocation overhead
- Predictable memory usage
- Wraparound wastes no space

### Linked List Queue:
- Dynamic allocation per node
- Pointer overhead (8 bytes per node)
- No pre-allocation needed
- More flexible size

---

## Compilation & Testing

```bash
g++ -std=c++11 filename.cpp -o queue_program
./queue_program

# Test cases:
# - Enqueue/dequeue sequence
# - Circular wraparound
# - Empty/full conditions
# - Boundary conditions
```

---

## Extension Ideas

1. **Priority Queue:** Different extraction order
2. **Double-Ended Queue:** Deque operations
3. **Thread-Safe Queue:** For concurrent access
4. **Ring Buffer:** Fixed circular buffer
5. **Stable Priority Queue:** Maintain insertion order for equal priorities

---

## Common Mistakes

1. **Off-by-one errors:** Index calculations
2. **Wrong modulo:** Circular wraparound
3. **No empty check:** Dequeuing from empty queue
4. **No full check:** Enqueuing to full queue
5. **Memory leaks:** Not freeing linked list nodes

---

## Debugging Strategies

1. **Print state:** Display front, rear, elements
2. **Visualize:** Draw queue after each operation
3. **Test edge cases:** Empty, single element, full
4. **Count elements:** Ensure correct count
5. **Verify FIFO:** Check order is correct

---

## Tips for Understanding

1. **Visualize FIFO:** Think of real-world queue (line)
2. **Trace indices:** Follow front/rear changes
3. **Draw wraparound:** Understand circular modulo
4. **Test small cases:** 3-5 elements first
5. **Compare implementations:** Understand trade-offs

---

## Performance Comparison

### Time Complexity Per Operation
| Implementation | Enqueue | Dequeue | Space |
|---|---|---|---|
| Simple Array | O(1) | O(n) | O(n) |
| Circular Array | O(1) | O(1) | O(n) |
| Linked List | O(1) | O(1) | O(n) |
| Deque | O(1) | O(1) | O(n) |

**Recommendation:** Use circular array or linked list for best performance

---

## Related Topics

- **Stacks:** LIFO vs FIFO
- **Deques:** Double-ended variant
- **Priority Queues:** Ordered extraction
- **BFS:** Uses queue for traversal
- **System Queues:** OS process scheduling

---

## Summary

This folder covers queue implementations:
- ✓ Simple array queues
- ✓ Circular array queues
- ✓ Linked list queues
- ✓ Deque (double-ended queue)
- ✓ FIFO principle
- ✓ Real-world applications

**Essential for BFS, scheduling, and buffer management.**

---

**Difficulty Level:** Beginner to Intermediate  
**Prerequisite:** Arrays, linked lists, basic data structures  
**Applications:** BFS, scheduling, buffering, simulation  

Last Updated: 2026-03-11
