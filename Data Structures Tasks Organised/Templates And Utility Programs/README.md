# Templates And Utility Programs

## Overview
This folder contains 4 C++ programs demonstrating generic programming with templates and practical utility systems. Topics include generic data structures, template functions, and application-specific implementations like payroll systems.

## Subfolders & Concepts

### 1. **Template Utilities** - Generic Function Templates
Reusable template functions for common operations.

**Common Template Utilities:**
- **Swap Function:** Exchange values (generic type)
- **Min/Max Functions:** Find minimum or maximum
- **Find Function:** Search for element in container
- **Clone Function:** Deep copy of data structures
- **Sort Functions:** Generic sorting

**Template Syntax Example:**
```cpp
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}
```

**Advantages:**
- Type-safe at compile time
- Avoid code duplication
- No runtime overhead (compile-time resolution)
- Works with any type supporting operations

**Considerations:**
- Code bloat if templates used excessively
- Longer compilation time
- More difficult error messages
- Template instantiation overhead

---

### 2. **Template Demonstrations** - Template Classes
Generic class implementations demonstrating template design patterns.

**Template Class Example:**
```cpp
template <typename T>
class Container {
    vector<T> data;
public:
    void add(T element) { data.push_back(element); }
    T get(int index) { return data[index]; }
    int size() { return data.size(); }
};
```

**Common Template Classes:**
- **Generic Stack:** Stack<T> for any type
- **Generic Queue:** Queue<T> for any type
- **Generic List:** LinkedList<T> for any type
- **Generic Pair:** Tuple<T1, T2> for two types

**Multiple Type Parameters:**
```cpp
template <typename K, typename V>
class Map {
    vector<pair<K, V>> data;
};
```

---

### 3. **Payroll Calculations** - Application System Using Templates
Practical system demonstrating real-world template usage.

**Payroll System Components:**
- **Employee Class:** Store employee information
- **Salary Calculation:** Compute base salary, deductions
- **Bonus Calculation:** Performance-based bonuses
- **Tax Calculation:** Income tax, social security
- **Report Generation:** Print payroll summaries

**Template Benefits in Payroll:**
- Generic employee types (hourly, salaried, contract)
- Type-safe salary calculations
- Reusable calculation components
- Easy to extend for new employee types

**Sample Structure:**
```cpp
template <typename T>
class Employee {
    string name;
    T salary;
    vector<T> deductions;
    
public:
    T calculateNetSalary() {
        T total = salary;
        for(T deduction : deductions) {
            total -= deduction;
        }
        return total;
    }
};
```

---

## File Count & Statistics

| Subcategory | Files | Complexity |
|---|---|---|
| Template Utilities | 1-2 | Intermediate |
| Template Demonstrations | 1 | Intermediate |
| Payroll Calculations | 1-2 | Intermediate |

**Total Files: 4**

---

## Template Concepts

| Concept | Definition |
|---|---|
| **Template Parameter** | Placeholder for type/value |
| **Type Parameter** | typename T, represents actual type |
| **Non-type Parameter** | template parameter for values |
| **Template Instantiation** | Compiler generates code for specific type |
| **Specialization** | Custom template for specific type |
| **SFINAE** | Substitution Failure Is Not An Error |

---

## Template Best Practices

### When to Use Templates:
1. Need same logic for multiple types
2. Type safety is important
3. Performance-critical code
4. Generic data structures

### When NOT to Use:
1. Different logic for different types (use inheritance)
2. Types known at runtime
3. Minimal code reuse (overkill)
4. Very large templates (compilation time)

---

## Program Structure Examples

### Generic Min Function:
```cpp
template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}

// Usage:
int minInt = minimum(5, 3);      // 3
double minDouble = minimum(2.5, 3.7);  // 2.5
string minStr = minimum("apple", "zebra"); // "apple"
```

### Generic Stack:
```cpp
template <typename T>
class Stack {
    struct Node {
        T data;
        Node* next = nullptr;
    };
    Node* top = nullptr;
    
public:
    void push(T value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    
    T pop() {
        if(!top) throw exception();
        T value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
};
```

---

## Payroll System Example

```cpp
enum class EmployeeType { HOURLY, SALARIED, CONTRACT };

class Payroll {
    vector<Employee> employees;
    map<string, double> taxRates;
    
public:
    double calculateSalary(const Employee& emp) {
        double gross = emp.baseAmount();
        double tax = gross * taxRates[emp.getCountry()];
        double deductions = emp.getDeductions();
        return gross - tax - deductions;
    }
    
    void generatePayroll() {
        for(const auto& emp : employees) {
            double netSalary = calculateSalary(emp);
            cout << emp.getName() << ": " << netSalary << endl;
        }
    }
};
```

---

## Learning Path

### Level 1: Beginner
1. Understand template syntax
2. Write simple template functions
3. Use STL templates (vector, map)
4. Understand template instantiation

### Level 2: Intermediate
1. Write template classes
2. Multiple type parameters
3. Template specialization
4. Understand compilation process

### Level 3: Advanced
1. SFINAE techniques
2. Variadic templates
3. Template metaprogramming
4. Policy-based design

---

## Compilation Considerations

### Template Compilation:
- Templates instantiated at compile time
- Larger executable size (code generation)
- Slower compilation (multiple instantiations)
- Fast runtime (no overhead)

### Compilation Command:
```bash
g++ -std=c++17 -O2 filename.cpp -o program
# -std=c++17 for modern template features
# -O2 for optimization
```

---

## Real-World Applications

| Application | Template Use |
|---|---|
| **STL Containers** | vector<T>, map<K,V>, set<T> |
| **Database Libraries** | Generic queries and results |
| **Game Engines** | Generic resource management |
| **Scientific Computing** | Generic numerical operations |
| **Payroll Systems** | Generic employee/salary types |
| **Graphics Libraries** | Generic vector/matrix operations |

---

## Common Template Patterns

### Swap Function:
```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

### Generic Array Class:
```cpp
template <typename T, int SIZE>
class Array {
    T data[SIZE];
    int count = 0;
public:
    void add(T element) { 
        if(count < SIZE) data[count++] = element; 
    }
    T get(int index) { return data[index]; }
};
```

---

## Debugging Templates

### Common Template Errors:
1. **Type mismatch:** Comparing incompatible types
2. **Missing operators:** Type doesn't support needed operation
3. **Instantiation errors:** Compilation fails for certain types
4. **Performance:** Unexpected code bloat

### Debugging Strategies:
1. Start with concrete types
2. Test with simple types first
3. Check operator requirements
4. Use static_assert for compile-time checks

---

## Extension Ideas

1. **Variadic Templates:** Variable argument counts
2. **Concept-Based Design:** Define type requirements
3. **Template Metaprogramming:** Compile-time computation
4. **Policy-Based Design:** Customize behavior per type
5. **SFINAE:** Conditional template instantiation

---

## Compilation Tips

1. **Separate declaration/definition:** Put in header files
2. **Explicit instantiation:** Pre-generate common types
3. **Avoid unnecessary instantiation:** Use type constraints
4. **Monitor compilation time:** Very large templates slow compilation
5. **Use concepts (C++20):** Replace SFINAE for clarity

---

## Common Mistakes

1. **Forgetting typename:** `template <T>` instead of `template <typename T>`
2. **Type constraints missing:** Assuming operations exist
3. **Forgot semicolon:** After template class definition
4. **Mixing templates and inheritance:** Complex interactions
5. **Code bloat:** Unnecessary instantiations

---

## Performance Considerations

### Advantages:
- Zero runtime overhead (compile-time resolution)
- Specialized code per type
- Better optimization opportunities

### Disadvantages:
- Larger executable size
- Longer compilation time
- Template instantiation overhead
- Complex error messages

---

## Tips for Understanding

1. **Trace substitution:** Mentally replace T with actual type
2. **Think compile-time:** Templates resolved at compile time
3. **Start simple:** Begin with simple template functions
4. **Test with types:** Try with int, double, string, custom classes
5. **Read error messages:** Tell you what went wrong

---

## Related Topics

- **STL Containers:** Standard template library
- **Generic Programming:** Design philosophy
- **Inheritance:** Alternative to templates
- **Concepts (C++20):** Type constraints for templates
- **Metaprogramming:** Advanced template techniques

---

## Summary

This folder covers template programming:
- ✓ Template functions and classes
- ✓ Generic utility implementations
- ✓ Multiple type parameters
- ✓ Template specialization
- ✓ Practical applications (payroll)
- ✓ Compilation considerations

**Essential for modern C++ and understanding STL.**

---

**Difficulty Level:** Intermediate  
**Prerequisite:** Basic C++, classes, understanding of parameterization  
**Applications:** STL containers, reusable components, applications  

Last Updated: 2026-03-11
