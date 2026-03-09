# 08 Operator Overloading

## Files
- `CountingIncrementOperator.cpp`: Overloads prefix increment to customize how an object’s count value evolves per `++` call.
- `MatrixAdditionOperator.cpp`: Overloads `+` for matrix-like objects and performs element-wise addition before displaying results.
- `MatrixMultiplicationOperator.cpp`: Overloads `*` to perform matrix multiplication with dimension compatibility checks.
- `NumberAdditionOperator.cpp`: Overloads numeric addition for a wrapper class and returns object-based sum result.
- `Matrix Module/Matrix.h`: Declares matrix class interface, dimensions/storage members, and operator signatures used by matrix implementations.
- `Matrix Module/MatrixClassHeaderBasedOps.cpp`: Provides matrix class operations through header-linked implementation and executes matrix workflows from main.
- `Matrix Module/MatrixTransposeUnaryOperator.cpp`: Uses overloaded unary operator to perform matrix transpose behavior.
- `Unsigned Integer Module/Task 2.h`: Declares unsigned-integer class hierarchy and operation/status interfaces for specialized widths.
- `Unsigned Integer Module/Task 3.h`: Declares overloaded arithmetic and assignment operators for UInt family classes.
- `Unsigned Integer Module/UInt16.h`: Defines UInt16-specific API for construction, assignment, status checks, and arithmetic wrappers.
- `Unsigned Integer Module/UInt16ClassImplementation.cpp`: Implements UInt16 constructors and core member functions for value/state management.
- `Unsigned Integer Module/UInt16OperatorOverloads.cpp`: Implements overloaded arithmetic/assignment operators for UInt classes with status handling.
- `Unsigned Integer Module/UInt16TemplateCommentStub.cpp`: Demonstrates UInt-style object creation and operation flow as a compact practice driver.
- `Unsigned Integer Module/UInt16UsageDemo.cpp`: Runs end-to-end UInt16 usage: constructors, setter/getter, status check, and arithmetic operators.
- `Unsigned Integer Module/UInt8UsageDemo.cpp`: Demonstrates the UInt8 variant with constructor/copy and operation calls.
- `Unsigned Integer Module/UIntArithmeticOperators.cpp`: Implements base UInt arithmetic behavior shared by width-specific derived classes.
- `Vector3D Module/Vector3D.h`: Declares vector operators for add/subtract/dot/cross and increment/decrement-style vector updates.
- `Vector3D Module/Vector3DClassOperations.cpp`: Implements vector arithmetic operators and computes resulting vectors/scalars.
- `Vector3D Module/Vector3DUsageDemo.cpp`: Demonstrates vector operation calls and prints outcomes for overloaded operators.

Total source files: 19
