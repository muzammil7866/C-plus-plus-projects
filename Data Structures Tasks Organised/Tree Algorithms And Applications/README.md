# Tree Algorithms And Applications

## Overview
This folder contains 10 C++ programs implementing various tree data structures and algorithms. Topics range from basic Binary Search Trees (BST) to self-balancing AVL trees, and practical applications like student enrollment systems.

## Subfolders & Concepts

### 1. **Binary Search Tree Problems** - BST Operations
Programs implementing and solving problems with Binary Search Trees.

**BST Properties:**
- Left subtree values < parent value
- Right subtree values > parent value
- Enables efficient searching, insertion, deletion
- Average O(log n), worst case O(n) if unbalanced

**Core Operations:**
- **Search:** Find element in set O(log n) avg
- **Insertion:** Add new element maintaining BST property
- **Deletion:** Remove element with three cases:
  - No children: Simply remove
  - One child: Replace with child
  - Two children: Find inorder successor/predecessor

**Tree Traversals:**
- **In-order:** Left, Node, Right (sorted order)
- **Pre-order:** Node, Left, Right (prefix for expression tree)
- **Post-order:** Left, Right, Node (child before parent)
- **Level-order:** Row by row (breadth-first)

**Problems:**
- Find kth smallest/largest element
- Validate BST
- Find closest value
- Lowest common ancestor

---

### 2. **AVL Tree Operations** - Self-Balancing Trees
Programs implementing AVL trees with automatic balancing.

**AVL Properties:**
- Balanced BST: height(left) and height(right) differ by max 1
- All operations O(log n) guaranteed
- Requires rotations after insertion/deletion
- More complex but always efficient

**Balancing Factors:**
```
balance_factor = height(left_subtree) - height(right_subtree)
Valid: -1, 0, 1
```

**Rotation Types:**
- **LL Rotation:** Left-left imbalance, single right rotation
- **RR Rotation:** Right-right imbalance, single left rotation
- **LR Rotation:** Left-right imbalance, left then right rotation
- **RL Rotation:** Right-left imbalance, right then left rotation

**Operations:**
- Insertion with rebalancing
- Deletion with rebalancing
- Height maintenance
- Balance factor updates

**When to Use:**
- Need guaranteed O(log n) operations
- Frequent insertions/deletions
- Searching is critical

---

### 3. **Application Systems** - Practical Tree Applications
Real-world systems using tree data structures.

**Student Enrollment System:**
- Organize students in tree structure
- Query by ID, department, etc.
- Efficient searching and sorting
- Hierarchical organization

**Other Applications:**
- File systems (directory structure)
- Organization hierarchy
- Decision making (game trees)
- Expression trees
- Syntax trees (compilers)

---

## File Count & Statistics

| Subcategory | Files | Complexity |
|---|---|---|
| Binary Search Tree Problems | 5-6 | Intermediate |
| AVL Tree Operations | 3-4 | Intermediate to Advanced |
| Application Systems | 1-2 | Advanced |

**Total Files: 10**

---

## Tree Terminology

| Term | Definition |
|---|---|
| **Root** | Top node with no parent |
| **Leaf** | Node with no children |
| **Height** | Longest path from node to leaf |
| **Depth** | Path length from root to node |
| **Subtree** | Tree rooted at child node |
| **Balance Factor** | Height difference of subtrees |
| **Rotation** | Restructuring tree to maintain balance |
| **In-order Successor** | Smallest value in right subtree |
| **In-order Predecessor** | Largest value in left subtree |

---

## Complexity Analysis

### Binary Search Tree

| Operation | Best Case | Average | Worst Case |
|---|---|---|---|
| Search | O(1) at root | O(log n) | O(n) |
| Insert | O(log n) | O(log n) | O(n) |
| Delete | O(log n) | O(log n) | O(n) |
| Traverse | O(n) | O(n) | O(n) |

### AVL Tree

| Operation | Time | Notes |
|---|---|---|
| Search | O(log n) | Always balanced |
| Insert | O(log n) | With rebalancing |
| Delete | O(log n) | With rebalancing |
| Traverse | O(n) | Level-order or in-order |

---

## Program Structure Example

### Node Definition:
```cpp
struct TreeNode {
    int value;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    int height = 1;  // For AVL trees
};
```

### Basic BST Class:
```cpp
class BST {
    TreeNode* root = nullptr;
    
public:
    void insert(int value) {
        root = insertHelper(root, value);
    }
    
    TreeNode* insertHelper(TreeNode* node, int value) {
        if(node == nullptr) {
            return new TreeNode{value};
        }
        if(value < node->value) {
            node->left = insertHelper(node->left, value);
        } else {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }
    
    bool search(int value) {
        return searchHelper(root, value);
    }
    
    bool searchHelper(TreeNode* node, int value) {
        if(node == nullptr) return false;
        if(node->value == value) return true;
        if(value < node->value) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }
};
```

### In-order Traversal (Sorted):
```cpp
void inOrder(TreeNode* node) {
    if(node == nullptr) return;
    inOrder(node->left);           // Left
    cout << node->value << " ";     // Node
    inOrder(node->right);           // Right
}
```

---

## AVL Tree Rotation Example

### Right Rotation (LL Case):
```cpp
TreeNode* rotateRight(TreeNode* node) {
    TreeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    
    // Update heights
    node->height = 1 + max(height(node->left), height(node->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));
    
    return newRoot;
}
```

---

## Learning Path

### Level 1: Beginner
1. Understand tree structure
2. Learn BST properties
3. Implement insertion and search
4. Practice in-order traversal

### Level 2: Intermediate
1. Implement BST deletion
2. Understand space/time trade-offs
3. Learn AVL concepts
4. Basic rotations

### Level 3: Advanced
1. Master AVL insertion/deletion
2. Complex balancing cases
3. Application systems
4. Performance optimization

---

## Common Interview Questions

### Easy
- In-order traversal
- Validate BST
- Find minimum/maximum
- Tree height

### Medium
- Lowest common ancestor (LCA)
- Kth smallest element
- Distance between nodes
- Serialize/deserialize tree

### Hard
- AVL tree balancing
- Complex tree problems
- Optimize for specific constraints
- Memory-efficient implementations

---

## Real-World Applications

| Application | Tree Type | Benefit |
|---|---|---|
| **Databases** | B-trees | Indexed searching |
| **File Systems** | N-ary trees | Directory hierarchy |
| **Compilers** | Syntax trees | Parse expressions |
| **Decision Making** | Decision trees | Organized choices |
| **Game AI** | Game trees | Move evaluation |
| **Dictionary** | Trie trees | Fast word lookup |

---

## Traversal Comparison

| Traversal | Order | Use Case |
|---|---|---|
| **In-order** | Left-Node-Right | BST sorted order |
| **Pre-order** | Node-Left-Right | Clone tree, prefix expression |
| **Post-order** | Left-Right-Node | Delete tree, postfix expression |
| **Level-order** | Row by row | Breadth-first search |

---

## Compilation & Testing

```bash
g++ -std=c++11 filename.cpp -o tree_program
./tree_program

# Test with:
# - Various insertion orders
# - Deletion scenarios
# - Balanced vs unbalanced trees
# - Large datasets for performance
```

---

## Memory Management

### Proper Cleanup:
```cpp
void deleteTree(TreeNode* node) {
    if(node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Call in destructor
~BST() {
    deleteTree(root);
}
```

---

## Extension Ideas

1. **Self-Balancing Variants:** Red-Black trees, Treaps
2. **N-ary Trees:** More than 2 children
3. **Trie Trees:** For string searching
4. **Segment Trees:** Range queries
5. **Fenwick Trees:** Efficient updates and queries

---

## Common Mistakes

1. **Wrong comparison:** < vs ≤ in insertion
2. **Forgetting recursion base case:** Never stops
3. **Memory leaks:** Not deleting nodes
4. **Balance factor errors:** Wrong calculation
5. **Rotation issues:** Wrong rotation type for imbalance

---

## Debugging Tips

1. **Print tree structure:** Visualize before/after changes
2. **Verify BST property:** Check all nodes satisfy constraint
3. **Check heights:** Especially for AVL trees
4. **Trace searches:** Follow path for target value
5. **Test common cases:** Already sorted, reverse sorted, random

---

## Visualization Tips

### Simple Tree Drawing:
```
       50
      /  \
    30    70
   / \   /  \
  20 40 60  80
```

### In-order: 20 30 40 50 60 70 80  
### Pre-order: 50 30 20 40 70 60 80  
### Post-order: 20 40 30 60 80 70 50

---

## Performance Comparison

| Operation | Unsorted Array | BST | AVL Tree |
|---|---|---|---|
| Search | O(n) | O(log n) avg | O(log n) |
| Insert | O(1) | O(log n) avg | O(log n) |
| Delete | O(n) | O(log n) avg | O(log n) |
| Memory | O(1/node) | O(2 pointers) | O(2 pointers + height) |

---

## Tips for Understanding

1. **Draw frequently:** Visualize changes
2. **Trace operations:** Step through small cases
3. **Compare:** BST vs AVL trade-offs
4. **Test edge cases:** Single node, two nodes, unbalanced
5. **Understand rotations:** Practice manually

---

## Related Topics

- **B-trees:** Generalization for disk storage
- **Red-Black Trees:** Alternative balancing
- **Heaps:** Priority-based trees
- **Tries:** String-based trees
- **Graphs:** Trees are special graphs

---

## Summary

This folder covers essential tree concepts:
- ✓ Binary Search Tree operations
- ✓ BST insertion, deletion, searching
- ✓ Tree traversals (in, pre, post, level-order)
- ✓ AVL tree balancing and rotations
- ✓ Guaranteed O(log n) operations
- ✓ Practical application systems
- ✓ Performance analysis and optimization

**Essential for interviews, databases, and system design.**

---

**Difficulty Level:** Intermediate to Advanced  
**Prerequisite:** Recursion, pointers, binary tree basics  
**Applications:** Databases, file systems, compilers, system design  

Last Updated: 2026-03-11
