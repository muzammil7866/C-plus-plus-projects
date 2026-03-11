# Hash Table Techniques

## Overview
This folder contains 4 C++ programs implementing different hash table collision resolution techniques. Hash tables are fundamental for efficient searching, providing O(1) average-case lookup, insertion, and deletion operations.

## Subfolders & Concepts

### 1. **Open Addressing** - Probing for Empty Slots
Hash tables that store all elements within the table itself, finding empty slots when collisions occur.

**Linear Probing:**
- h(k, i) = (h(k) + i) mod m
- Check slots at offsets 0, 1, 2, 3, ...
- Simple but suffers from clustering

**Quadratic Probing:**
- h(k, i) = (h(k) + i²) mod m
- Check slots at offsets 0, 1, 4, 9, 16, ...
- Reduces primary clustering
- May not check all slots

**Double Hashing:**
- h(k, i) = (h(k) + i * h₂(k)) mod m
- Uses second hash function for offset
- Eliminates clustering
- Most robust open addressing

**Use Cases:** Memory-efficient when capacity is fixed and known

---

### 2. **Separate Chaining** - Using Linked Lists
Hash tables that use linked lists for collision resolution.

**How It Works:**
- Each table entry points to a linked list
- Colliding elements are added to the list
- Search traverses list for matching key
- Can grow beyond table size

**Advantages:**
- Simple to implement
- Good for unknown data size
- No clustering issues
- Deletion is straightforward

**Disadvantages:**
- Extra space for pointers
- Cache-unfriendly
- Performance depends on chain length

**Use Cases:** Most common practical implementation (std::unordered_map uses this)

---

### 3. **Bucketing** - Multiple Slots Per Bucket
Hash tables that group multiple slots together as buckets.

**Bucket Concept:**
- Table divided into buckets
- Multiple slots per bucket
- Better cache locality
- Hybrid of arrays and chaining

**Overflow Handling:**
- Primary bucket stores several elements
- Overflow bucket when primary fills
- Still requires collision resolution

**Use Cases:** Database systems, large-scale storage

---

### 4. **Hash Utilities** - Hash Function Design
Programs focusing on hash function implementation and analysis.

**Good Hash Function Properties:**
- Uniform distribution
- Fast computation
- Minimal collisions
- Avalanche effect (small change → large hash difference)

**Common Hash Functions:**
- Division method: h(k) = k mod m
- Multiplication method: h(k) = ⌊m(kA mod 1)⌋
- String hashing: Polynomial rolling hash
- Cryptographic hashing: For security

**Use Cases:** Understanding hash quality and performance

---

## File Count & Statistics

| Subcategory | Focus | Complexity |
|---|---|---|
| Open Addressing | Probing strategies | Intermediate |
| Separate Chaining | Linked lists + tables | Intermediate |
| Bucketing | Multi-slot handling | Advanced |
| Hash Utilities | Function design | Intermediate |

**Total Files: 4**

---

## Hash Table Terminology

| Term | Definition |
|---|---|
| **Hash Function** | Maps keys to table indices |
| **Collision** | Two keys hash to same index |
| **Load Factor** | α = n/m (elements / capacity) |
| **Probe** | Check of a table position |
| **Cluster** | Group of consecutive filled slots |
| **Primary Cluster** | Clustering in linear probing |
| **Secondary Cluster** | Clustering in quadratic probing |
| **Rehashing** | Growing table when too full |

---

## Complexity Analysis

### Open Addressing (Linear Probing)
```
Insertion (avg):  O(1)
Insertion (worst): O(n)
Search (avg):     O(1/(1-α))    where α = load factor
Space:            O(m)          m = table size
```

### Separate Chaining
```
Insertion:    O(1)
Search (avg): O(1 + α)   where α = average chain length
Search (worst): O(n)
Space:        O(n + m)
```

### Load Factor Impact
- Low α (< 0.5): Less collisions, more space wasted
- Moderate α (0.5-0.75): Good balance
- High α (> 0.9): Many collisions, rehashing needed

---

## Program Structure Example

### Simple Hash Table with Separate Chaining:
```cpp
#include <list>
#include <vector>
using namespace std;

template <typename K, typename V>
class HashTable {
    vector<list<pair<K, V>>> table;
    int size;
    
    int hashFunction(K key) {
        return abs(hash<K>()(key)) % size;
    }
    
public:
    HashTable(int s = 100) : size(s), table(s) {}
    
    void insert(K key, V value) {
        int idx = hashFunction(key);
        table[idx].push_back({key, value});
    }
    
    V search(K key) {
        int idx = hashFunction(key);
        for(auto& p : table[idx]) {
            if(p.first == key) return p.second;
        }
        return V();  // Not found
    }
};
```

---

## Learning Path

### Level 1: Beginner
1. Understand hash function basics
2. Learn about collisions
3. Study simple separate chaining

### Level 2: Intermediate
1. Implement linear and quadratic probing
2. Understand load factor impact
3. Practice collision resolution

### Level 3: Advanced
1. Compare all four techniques
2. Understand rehashing
3. Optimize for specific use cases

---

## Collision Resolution Comparison

| Technique | Space | Avg Search | Implementation | Best For |
|---|---|---|---|---|
| **Linear Probing** | O(m) | O(1/(1-α)) | Simple | Fixed capacity |
| **Quadratic Probing** | O(m) | O(1) if α < 0.5 | Moderate | Known upper bound |
| **Double Hashing** | O(m) | O(1/(1-α)) | Complex | Random distribution |
| **Separate Ch.** | O(n+m) | O(1+α) | Simple | Unknown size |
| **Bucketing** | O(m*b) | O(1/(1-α/b)) | Complex | Large elements |

---

## Common Interview Questions

### Easy
- What is a hash table?
- Explain collision resolution
- Hash function for strings

### Medium
- Implement hash table with chaining
- Compare open addressing vs chaining
- Calculate load factor and resize

### Hard
- Implement double hashing
- Design hash function with good distribution
- Optimize for cache locality
- Handle key removal in open addressing

---

## Real-World Applications

| Use Case | Technique | Reason |
|---|---|---|
| Dictionary/Map | Separate Chaining | Simple, dynamic sizing |
| Database indexing | Bucketing | Fixed records, efficiency |
| Caching | Open Addressing | Memory constrained |
| Compiler symbol tables | Separate Chaining | Variable size input |
| Cryptography | Custom hashing | Collision resistance needed |

---

## Common Patterns

### Insert Operation:
```cpp
void insert(int key, int value) {
    int idx = hash(key);
    // For open addressing: find empty slot
    while (table[idx] != empty) {
        idx = nextProbe(idx);
    }
    table[idx] = value;
}
```

### Search Operation:
```cpp
int search(int key) {
    int idx = hash(key);
    // For open addressing: probe until found or empty
    while (table[idx] != empty) {
        if (table[idx].key == key) return table[idx].value;
        idx = nextProbe(idx);
    }
    return notFound;
}
```

---

## Hash Function Good vs Bad

### Good Hash Function:
```cpp
// String hashing - good distribution
int hashString(string s, int m) {
    int hash = 0;
    for(char c : s) {
        hash = (hash * 31 + c) % m;
    }
    return hash;
}
```

### Bad Hash Function:
```cpp
// Returns same value for many keys
int badHash(int x, int m) {
    return 0;  // Everything collides!
}

// Ignores high-order bits
int badHash2(int x, int m) {
    return x % 10;  // Only uses last digit
}
```

---

## Compilation & Testing

```bash
g++ -std=c++11 filename.cpp -o hash_program
./hash_program

# Test with various load factors
# Observe performance degradation
# Test collision resolution strategies
```

---

## Memory Considerations

### Separate Chaining:
- Each entry needs pointer (8 bytes)
- List nodes need pointers (16+ bytes)
- More memory overhead but flexible

### Open Addressing:
- Direct array storage
- Minimal overhead
- No pointer indirection
- Better cache locality

---

## Rehashing Strategy

When table becomes too full (α > 0.75):
1. Create new, larger table
2. Rehash all elements to new table
3. Time: O(n) for entire table
4. Amortized O(1) insertion

---

## Extension Ideas

1. **Dynamic Resizing:** Automatically rehash when full
2. **Perfect Hashing:** Guarantee O(1) worst-case
3. **Cuckoo Hashing:** Use two hash functions
4. **Bloom Filters:** Space-efficient membership test
5. **Consistent Hashing:** For distributed systems

---

## Common Mistakes

1. **Poor hash function:** Leading to high collision rate
2. **Wrong load factor:** Too high causes many collisions
3. **Forgetting rehashing:** Table efficiency degrades
4. **Not handling deletion:** Affecting subsequent probes
5. **Wrong modulo size:** Better when size is prime

---

## Debugging Tips

1. **Track collisions:** Count collision occurrences
2. **Hash distribution:** Check histogram of hash values
3. **Load factor monitoring:** Know α at all times
4. **Probe sequence:** Trace where collisions go
5. **Performance testing:** Measure actual vs theoretical

---

## Related Topics

- **Bloom Filters:** Space-efficient set membership
- **Cuckoo Hashing:** Alternative collision strategy
- **Consistent Hashing:** Distributed hash tables
- **Cryptographic Hashing:** For security applications

---

## Summary

This folder covers essential hash table concepts:
- ✓ Collision resolution strategies
- ✓ Open addressing techniques (linear, quadratic, double hashing)
- ✓ Separate chaining with linked lists
- ✓ Bucketing strategies
- ✓ Hash function design and analysis
- ✓ Performance optimization

**Essential for understanding std::unordered_map, dictionaries, and caching systems.**

---

**Difficulty Level:** Intermediate  
**Prerequisite:** Arrays, Linked Lists, Hash Functions  
**Application:** Databases, caching, symbol tables  

Last Updated: 2026-03-11
