# Stack Applications

## Overview
This folder contains 5 C++ programs implementing stack data structures and demonstrating practical applications. Stacks follow LIFO (Last-In-First-Out) principle and are essential for expression evaluation, undo/redo systems, and depth-first search.

## Subfolders & Concepts

### 1. **Core Stack Operations** - Basic Stack Implementation
Fundamental stack operations and implementations.

**Basic Operations:**
- **Push:** Add element to top (O(1))
- **Pop:** Remove element from top (O(1))
- **Peek:** View top without removing (O(1))
- **isEmpty/isFull:** Check state (O(1))
- **size:** Get element count (O(1))

**Implementation Methods:**
- **Array-based:** Fixed size, simple
- **Linked list-based:** Dynamic size, flexible
- **Vector-based:** Dynamic array, flexible

**LIFO Behavior Example:**
```
Push 1:   [1]
Push 2:   [1, 2]
Push 3:   [1, 2, 3]
Pop:      [1, 2]        returns 3
Pop:      [1]           returns 2
```

---

### 2. **Expression Conversion** - Infix and Postfix Conversion
Converting mathematical expressions between notations.

**Notations:**
- **Infix:** Standard notation: a + b * c
- **Prefix (Polish):** Operator first: + a * b c
- **Postfix (RPN):** Operator last: a b c * +

**Infix to Postfix Conversion:**
Uses stack to handle operator precedence and associativity.

**Precedence Rules:**
- Parentheses: highest
- *, /: multiplication and division
- +, -: addition and subtraction
- Lower precedence operators processed later

**Algorithm:**
1. Scan infix expression left-to-right
2. Operands → directly to output
3. Operators → stack (handle precedence)
4. Right parenthesis → pop until left parenthesis
5. End → pop all remaining operators

**Postfix Evaluation:**
Using stack to evaluate postfix expressions efficiently.

---

### 3. **Editor Utilities** - Undo/Redo System
Stack-based implementation of undo/redo functionality.

**Undo Stack:**
- Stores previous states
- On undo: pop from undo, push to redo
- On action: push to undo, clear redo

**Redo Stack:**
- Stores undone states
- On redo: pop from redo, push to undo
- On new action: clear redo

**Implementation Pattern:**
```cpp
class Editor {
    stack<string> undoStack;
    stack<string> redoStack;
    string currentText;
    
public:
    void type(string text) {
        undoStack.push(currentText);
        currentText += text;
        redoStack = stack<string>();  // Clear redo
    }
    
    void undo() {
        if(!undoStack.empty()) {
            redoStack.push(currentText);
            currentText = undoStack.top();
            undoStack.pop();
        }
    }
    
    void redo() {
        if(!redoStack.empty()) {
            undoStack.push(currentText);
            currentText = redoStack.top();
            redoStack.pop();
        }
    }
};
```

---

## File Count & Statistics

| Subcategory | Files | Complexity |
|---|---|---|
| Core Stack Operations | 1-2 | Beginner |
| Expression Conversion | 1-2 | Intermediate |
| Editor Utilities | 1-2 | Intermediate |

**Total Files: 5**

---

## Stack Terminology

| Term | Definition |
|---|---|
| **LIFO** | Last-In-First-Out ordering |
| **Push** | Add element to stack top |
| **Pop** | Remove element from stack top |
| **Peek/Top** | View top element without removing |
| **Empty** | No elements in stack |
| **Full** | No space for new element (array-based) |
| **Stack Overflow** | Pushing to full stack |
| **Stack Underflow** | Popping from empty stack |

---

## Complexity Analysis

| Operation | Time | Space |
|---|---|---|
| Push | O(1) | Per operation |
| Pop | O(1) | Per operation |
| Peek | O(1) | Per operation |
| Access element at position k | O(k) | Can't access directly |

---

## Program Structure Example

### Basic Stack Implementation:
```cpp
template <typename T>
class Stack {
    vector<T> elements;
    
public:
    void push(T value) {
        elements.push_back(value);
    }
    
    T pop() {
        if(elements.empty()) throw exception();
        T val = elements.back();
        elements.pop_back();
        return val;
    }
    
    T peek() const {
        if(elements.empty()) throw exception();
        return elements.back();
    }
    
    bool isEmpty() const {
        return elements.empty();
    }
    
    int size() const {
        return elements.size();
    }
};
```

### Infix to Postfix Conversion:
```cpp
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    
    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;  // Operand
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();  // Remove '('
        } else {  // Operator
            while(!st.empty() && precedence[st.top()] >= precedence[c]) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
```

---

## Learning Path

### Level 1: Beginner
1. Understand LIFO principle
2. Implement basic push/pop
3. Master stack operations
4. Use stack for simple problems

### Level 2: Intermediate
1. Learn expression notation conversions
2. Implement infix to postfix
3. Evaluate postfix expressions
4. Basic bracket matching

### Level 3: Advanced
1. Complex expression evaluation
2. Undo/redo systems
3. Recursive vs stack approaches
4. Optimize for specific use cases

---

## Real-World Applications

| Application | Purpose |
|---|---|
| **Browser Back Button** | Store visited URLs |
| **Function Call Stack** | Memory management in programs |
| **Expression Evaluation** | Calculators, compilers |
| **Undo/Redo** | Text editors, graphics software |
| **Depth-First Search** | Graph traversal |
| **Syntax Parsing** | Bracket matching, compiler |
| **Memory Management** | Stack allocation |

---

## Common Interview Questions

### Easy
- Implement basic stack
- Check balanced parentheses
- Reverse string using stack

### Medium
- Infix to postfix conversion
- Evaluate postfix expression
- Implement undo/redo
- Trapping rain water
- Largest rectangle in histogram

### Hard
- Complex expression evaluation
- Asteroids collision
- Daily temperatures with monotonic stack
- Maximal rectangle

---

## Common Patterns

### Bracket Matching:
```cpp
bool isBalanced(string s) {
    stack<char> st;
    map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if(c == ')' || c == ']' || c == '}') {
            if(st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}  // Time: O(n), Space: O(n)
```

### Postfix Evaluation:
```cpp
int evaluatePostfix(string expr) {
    stack<int> st;
    
    for(char c : expr) {
        if(isdigit(c)) {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch(c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}  // Time: O(n), Space: O(n)
```

---

## Compilation & Testing

```bash
g++ -std=c++11 filename.cpp -o stack_program
./stack_program

# Test with:
# - Push/pop sequences
# - Expression conversions
# - Undo/redo operations
# - Empty/full conditions
```

---

## Memory Considerations

### Array-Based Stack:
- Pre-allocated fixed size
- No dynamic overhead
- Risk of overflow
- Excellent cache locality

### Linked List Stack:
- Dynamic allocation per push
- Pointer overhead (8 bytes)
- No risk of overflow
- Worse cache behavior

---

## Extension Ideas

1. **Min/Max Stack:** Track minimum/maximum element
2. **Monotonic Stack:** Maintain ordered elements
3. **Daily Temperatures:** Stack-based problem
4. **Calculator:** Complete expression evaluation
5. **Incremental Undo:** Store only changes, not full state

---

## Common Mistakes

1. **Empty check:** Popping from empty stack
2. **Full check:** Pushing to full stack (array-based)
3. **Operator precedence:** Wrong precedence in conversion
4. **Parentheses matching:** Not handling properly
5. **State management:** Undo/redo logic errors

---

## Debugging Tips

1. **Print stack:** After each operation
2. **Trace expressions:** Step-by-step conversion
3. **Visualize:** Draw stack state changes
4. **Test edge cases:** Empty, one element, all same
5. **Compare:** Manual vs program results

---

## Tips for Understanding

1. **Visualize LIFO:** Think of Pringles can
2. **Trace operations:** Follow push/pop manually
3. **Practice conversions:** By hand first, then code
4. **Test small cases:** 3-5 elements first
5. **Understand precedence:** Critical for expressions

---

## Performance Tips

1. **Avoid unnecessary copies:** Use references
2. **Pre-allocate space:** If size known
3. **Use std::stack:** Optimized implementation
4. **Minimize allocations:** Linked list overhead
5. **Cache efficiency:** Array-based better

---

## Related Topics

- **Queues:** FIFO vs LIFO
- **DFS:** Recursive or stack-based
- **Expression Trees:** Alternative representation
- **Compiler Design:** Syntax parsing
- **Memory Management:** Activation records

---

## Summary

This folder covers stack fundamentals:
- ✓ LIFO data structure
- ✓ Push, pop, peek operations
- ✓ Expression notation conversions
- ✓ Infix to postfix conversion
- ✓ Postfix evaluation
- ✓ Undo/redo systems
- ✓ Practical applications

**Essential for expression processing and system design.**

---

**Difficulty Level:** Beginner to Intermediate  
**Prerequisite:** Basic data structures  
**Applications:** Calculators, editors, parsing, DFS  

Last Updated: 2026-03-11
