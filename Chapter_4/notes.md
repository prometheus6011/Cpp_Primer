# Chapter 4 - Expressions
- an expression is composed of one or more operands and yields a result when it is evaluated

### 4.1 - Fundamentals

##### 4.1.1 - Basic Concepts
- unary operators
    - these act on one operand
- binary operators
    - act on two operands
- one ternary operator, that takes three operands
- one operator, function call, takes an unlimited number of operands
- the context in which a symbol is used determines whether the symbol represnts a unary or binary operator

- grouping operators and operands
    - understanding expressions with multiple operatores requires understanding of precedence and associativity of the operators and may depend on the order of evaluation of the operands
- operand conversions
    - small integeral type operands are generally promoted to a larger integral type
- overloaded operators
    - defines what the operators mean when applied to built-in and compound types
    - operators depend on how the operator is defined
- Lvalues and Rvalues
    - lvalues could stand on the left-hand side of an assignment whereas rvalues could not
    - an lvalue expression yields an object or a function

##### 4.1.2 - Precedence and Associativity
- an expression with two or more operators is a compound expression
- programmers can override rules of precedence by parenthesizing compound expressions to force a particular grouping

###### Exercises
1. 105
2. grouping operands
    - `(*vec.begin())`
    - `(*vec.begin()) + 1`

##### 4.2 - Arithmetic Operators

###### Exercises
4. `((12 / 3) * 4) + (5 * 15) + ((25 % 4) / 2)`
5. expression results
    - -86
    - -18
    - 0
    - -2
6. `i % 2 == 0`
7. overflow is when an integer value is added to an integral type and the result requires more bits than the integral type has, therefore the value wraps around and produces an incorrect value

##### 4.3 - Logical and relational operators
- take operands of any type that can be converted to `bool`

###### Exercises
8. operands are evaluated in the `AND` from left-to-right and the first `false` value that comes it stops and returns `false`, `OR` evaluates from left-to-right and the `true` value that comes it stops and returns `true`, equality will test the left-side first and make sure it's valid, then will check the right-hand-side
9. the following `if` statement checks to see if the pointer is valid, then will check if the value of the pointer is not `NULL`, and will return `true` if both are valid
10. `4_10.cpp`
11. `4_11.cpp`
12. `(i != j) < k`, if `i` is not equal to `j`, it compares the `bool` value to the integer `k` value

### 4.4 - Assignment Operators
- the result of an assignment is its left-hand operand, which is an lvalue
- if the types differ, the right-hand operand is converted to the type of the left
- we can also used a brace initializer list on the right-hand side

###### Exercises
13. assignment
    - `i` is not 3, `d` is 3.0
    - `d` is 3.5, `i` is 3
14. the first `if` statement is invalid, the second checks to see if 42 can be assigned to `i`
15. `4_15.cpp`
16. assignment has a realitively low precedence
    - `if ((p = getPtr()) != 0)`
    - `if (i == 1024)`

### 4.5 - Increment and Decrement Operators
- the prefix form yields the changed result, the postfix form yields a copy of the original, unchanged value as its result

###### Exercises
17. the prefix operator stores the original value, increments the value and returns the original value, the postfix operator increments the value and returns itself
18. it would skip the first element, and at the end try to derference a nonexistant element
19. increments/decrements
    - incorrect, should be `ptr != 0 && (*ptr)++`
    - correct
    - incorrect, precedence for greater than or equal to is undefined

### 4.6 - The Member Access Operators
- the dot operator fetches a member from an object of class type
- arrow is defined to fetch a member from an object of pointer class type

###### Exercises
20. legal expressions
    - legal
    - illegal
    - `(*iter).empty()`
    - legal
    - illegal
    - `(iter++)->empty()`

### 4.7 - The Conditional Operator
- `?:` lets us embed simple if-else logic inside an expression

###### Exercises
21. `4_21.cpp`
22. `4_22.cpp`
23. the plus operator has the highest precedence, it should be `s + (s[s.size() - 1] == 's') ? "" : "s"`
24. `(grade > 90 ? "high pass" : grade < 60) ? "fail" : "pass")`

### 4.8 - The Bitwise Operators
- bitwise shift operators
    - left shift will shift the left most bits to the left
    - right shift will shift the right most bits to the right and discard those bits
        - right shift will either shift the most significant bit onto the right or will insert 1's onto the right of the data structure
- bitwise `NOT` Operator
    - invert each bit
- bitwise `AND`, `OR`, and `XOR` operators

###### Exercises
25. `10001110` `->` `01000000`
26. there wouldn't be enough bits for every student
27. results
    - 3
    - 7
    - true
    - true

### 4.9 - The `sizeof` Operator
- the `sizeof` operator returns the size, in bytes, of an expression or a type name

###### Exercises
28. `4_28.cpp`
29. the first line will return 10, the size of the array, the second line will return the division of the size of the pointer and the size of the underlying integer
30. parenthesize
    - `(sizeof x) + y`
    - `(sizeof p->mem[i])`
    - `(sizeof a) < b`
    - `(sizeof f())`

### 4.10 - Comma Operator
- the comma operator takes two operands, which evaluates from left to right

###### Exercises
31. no changes would have to be made to the program itself, prefix will be used as a performance benefit since there is no need to store the original value so why return a reference to it
32. its a loop that uses both the pointer to the first element and a counter to the size as a way to keep track of each element in the loop
33. if `someValue` is true, then increment x and y and decrement y, otherwise decrement x and then decrement y

### 4.11 - Type Conversions
- when implicit conversions occur
    - values of integral types smaller than `int` are first promotoed to an appropriate larger integral type
    - in conditions, non`bool` expressions are converted to `bool`
    - in initializations, the initializer is converted to the type of the variable; in assignments, the right-hand operand is converted to the type of the left-hand
    - in arithmetic and relational expressions with operands of mixed types, the types are converted to a common type
    - conversions also happen during function calls

##### 4.11.1 - The Arithmetic Conversions
- operands to an operator are converted to the widest type
- integral promotions
    - convert the small integral types to a larger integral type
- operands of unsigned type
    - when the signed type has a type larger than than the unsigned type, the result is machine dependent
    - when the unsigned type has a type larger than the signed type, it is always converted to the unsgined type

###### Exercises
34. implicit conversions
    - `fval` is converted to a `bool`
    - `ival` is converted to a `float`, the sum is converted to a `double`
    - `cval` is converted to a `int`, then the multiplier is converted to a `double`
35. implicit conversions
    - `a` is converted to a `int`, then converted back to `char`
    - `ival` is converted to a `double`, then converted to `unsigned int`, then the result is converted to `float`
    - `ui` is converted to a float, then the multiplier is converted to a `double`
    - `ival` is converted to a `float`, the sum is converted to  `double`, the sum of that is then converted to a `char`

##### 4.11.2 - Other Implicit Conversions
- Array to Pointer Conversions
    - when we use an array, the array is automatically converted to a pointer to the first element in that array
- Pointer Conversions
    - a pointer of non`const` type can be converted to `void*`
    - a pointer to any type can be converted to a `const void*`
- conversions to `bool`
- conversion to `const`
- conversions defined by class types

##### 4.11.3 - Explicit Conversions
- `static_cast`
    - any well-defined conversion, other than those involving low-level `const`, can be requested using `static_cast`
    - often useful when a larger arithmetic type is assigned to a smaller type
- `const_cast`
    - changes only low-level `const`
- `reinterpret_cast`
    - generally performs a low-level reinterpretation of the bit pattern of its operands

###### Exercises
36. `i *= static_cast<int>(d);`
37. named cast usage
    - `pv = static_cast<void*>(const_cast<std::string*>(ps));`
    - `i = static_cast<int>(*pc);`
    - `pv = static_cast<void*>(d);`
    - `pc = static_cast<char*>(pv);`
38. the integer division of `j/i` happens, then is converted to a double`
