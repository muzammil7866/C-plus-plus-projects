# Graph Algorithms And Representations

## Overview
This folder contains 7 C++ programs implementing graph data structures and fundamental graph algorithms. Topics include different graph representations, connectivity analysis, and traversal methods essential for solving complex problems.

## Subfolders & Concepts

### 1. **Graph Representations** - Storing Graphs Efficiently
Programs demonstrating different ways to represent graphs in memory.

**Adjacency List:**
- Most memory-efficient (O(V + E) space)
- Better for sparse graphs
- Array of linked lists or vectors
- Preferred in most applications

**Adjacency Matrix:**
- Simple 2D array representation
- O(V²) space complexity
- Better for dense graphs
- Faster lookup of specific edges

**Use Cases:** Understanding pros/cons of different representations

---

### 2. **Connectivity Analysis** - Exploring Graph Structure
Programs analyzing connections and relationships in graphs.
- Checking if two nodes are connected
- Finding connected components
- Path existence verification
- Component counting algorithms

**Key Algorithms:** DFS-based or BFS-based connectivity checks

---

### 3. **Traversal and MST** - Exploring & Optimizing Graphs
Programs implementing standard graph algorithms.

**Traversal Methods:**
- Depth-First Search (DFS) - Uses stack, explores deeply
- Breadth-First Search (BFS) - Uses queue, level-by-level exploration

**Minimum Spanning Tree:**
- Kruskal's Algorithm - Edge-based, greedy approach
- Prim's Algorithm - Node-based, greedy approach
- Connects all vertices with minimum total edge weight

**Use Cases:** Network routing, minimum cost connections, pathfinding

---

## File Count & Statistics

| Subcategory | Focus | Difficulty |
|---|---|---|
| Graph Representations | ADT design | Intermediate |
| Connectivity Analysis | DFS/BFS | Intermediate |
| Traversal and MST | Complex algorithms | Intermediate to Advanced |

**Total Files: 7**

---

## Graph Terminology Reference

| Term | Definition |
|---|---|
| **Vertex (Node)** | A point in the graph |
| **Edge** | Connection between two vertices |
| **Weighted Edge** | Edge with associated weight/cost |
| **Directed Graph** | Edges have direction (one-way) |
| **Undirected Graph** | Edges work both ways |
| **Degree** | Number of edges connected to a vertex |
| **Path** | Sequence of vertices connected by edges |
| **Cycle** | Path that starts and ends at same vertex |
| **Connected** | Path exists between all vertex pairs |
| **Spanning Tree** | Tree containing all vertices with V-1 edges |

---

## Key Algorithms & Complexity

### Depth-First Search (DFS)
```
Time: O(V + E)
Space: O(V) for recursion stack
Use: Connectivity, cycles, topological sort
```

### Breadth-First Search (BFS)
```
Time: O(V + E)
Space: O(V) for queue
Use: Shortest path in unweighted graphs, level-order
```

### Kruskal's Algorithm (MST)
```
Time: O(E log E) due to sorting
Space: O(V) for Union-Find
Best for: Sparse graphs
```

### Prim's Algorithm (MST)
```
Time: O(E + V log V) with min heap
Space: O(V)
Best for: Dense graphs
```

---

## Program Structure Example

### Adjacency List Graph:
```cpp
#include <vector>
using namespace std;

class Graph {
    vector<vector<int>> adjList;  // Adjacency list
    int vertices;
    
public:
    Graph(int v) : vertices(v), adjList(v) {}
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // For undirected
    }
    
    void dfs(int start) { /* ... */ }
    void bfs(int start) { /* ... */ }
};
```

---

## Learning Path

### Level 1: Beginner
1. Study adjacency list vs. matrix representations
2. Understand graph terminology
3. Implement basic graph with add/remove operations

### Level 2: Intermediate
1. Learn DFS algorithm and implementation
2. Learn BFS algorithm and implementation
3. Practice connectivity checking

### Level 3: Advanced
1. Study MST algorithms (Kruskal, Prim)
2. Understand weighted graphs
3. Implement Union-Find for Kruskal's algorithm

---

## Common Interview Questions

### Easy
- Is graph connected?
- Find path between two nodes
- Count connected components

### Medium
- Implement DFS/BFS
- Find minimum spanning tree
- Cycle detection

### Hard
- Topological sort
- Shortest path (Dijkstra)
- Network flow problems

---

## Real-World Applications

| Application | Graph Type | Algorithm |
|---|---|---|
| Social Networks | Undirected | BFS for friend suggestions |
| Road Networks | Weighted Directed | Dijkstra for navigation |
| Network Routing | Directed | DFS for path finding |
| Airport Connections | Undirected Weighted | MST for minimum distance |
| Web Crawling | Directed | DFS/BFS traversal |

---

## Common Patterns

### DFS Pattern (Recursive):
```cpp
void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[node] = true;
    // Process node
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, visited, adj);
        }
    }
}
```

### BFS Pattern:
```cpp
void bfs(int start, vector<vector<int>>& adj) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

---

## Compilation & Testing

```bash
# Compile
g++ -std=c++11 filename.cpp -o graph_program

# Run
./graph_program

# Test with sample graph:
# Input format example:
# 5 6      (vertices, edges)
# 0 1
# 0 2
# 1 2
# 3 4
# etc.
```

---

## Visualization Tips

### Represent Graphs on Paper:
```
    1 --- 2
   /|     |
  0 |     3
   \|    /
    4 --5
```

### Track Algorithms Mentally:
- **DFS:** Go deep first, backtrack when stuck
- **BFS:** Explore layer by layer
- **MST:** Greedily select minimum weight edges

---

## Memory Considerations

### Adjacency List:
- Better space: O(V + E)
- Suitable for sparse graphs
- Each vertex stores neighbors only

### Adjacency Matrix:
- Simple to implement
- O(V²) space always
- Better for dense graphs
- Faster edge lookups

---

## Extension Ideas

1. **Weighted Graphs:** Add edge weights
2. **Directed Graphs:** One-way edges
3. **Cycle Detection:** Track parent nodes
4. **Shortest Path:** Dijkstra's algorithm
5. **Topological Sort:** DFS-based ordering
6. **Bipartite Check:** 2-coloring with BFS/DFS

---

## Common Mistakes

1. **Forgetting visited array:** Infinite loops in cyclic graphs
2. **Queue vs. Stack confusion:** Using wrong data structure
3. **Undirected edge:** Forgetting to add reverse edge
4. **Index errors:** Graph nodes numbered 0 to V-1
5. **Memory leaks:** Not freeing dynamically allocated edges

---

## Tips for Understanding

1. **Draw the graph:** Visualize with nodes and edges
2. **Trace execution:** Follow algorithm step-by-step
3. **Test with simple cases:** 3-4 node graphs first
4. **Add comments:** Explain each algorithm step
5. **Compare approaches:** Understand when to use what

---

## Related Topics

- **Trees:** Acyclic connected graphs
- **Shortest Path:** Dijkstra, Bellman-Ford algorithms
- **Network Flow:** Advanced graph algorithms
- **Topological Sort:** For directed acyclic graphs

---

## Summary

This folder covers essential graph concepts:
- ✓ Graph representations (adjacency list/matrix)
- ✓ DFS and BFS traversal
- ✓ Connectivity analysis
- ✓ Minimum spanning trees
- ✓ Algorithm complexity analysis

**Master these before advanced algorithms like Dijkstra or network flow.**

---

**Difficulty Level:** Intermediate  
**Prerequisite:** Arrays, Linked Lists, Stacks, Queues  
**Next Topics:** Advanced graph algorithms, network problems  

Last Updated: 2026-03-11
