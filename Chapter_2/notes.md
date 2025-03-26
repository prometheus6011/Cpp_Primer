# Chapter 2 - Variables and Basic Types
- types determine the meaning of the data and operations in our programs

### 2.1 - Primitive Built-in Types
- defines a set of primitive types that include the arithmetic types and a special named `void`
- the arithmetic types represent characters, integers, booleans values, and floating point numbers
- the `void` type has no associated value and can be used in only a few circumstances

##### 2.1.1 - Arithmetic Types
- integral types
- floating point types
- the `bool` type represents the truth values `true` and `false`
- several character types
    - the basic character type is `char`
        - a `char` is gaurenteed to be big enough to hold numeric values correspoinding to the characters in the machine's basic character set
    - the remaining types, `whcar_t`, `char16_t`, and `char32_t`
        - used for extended character sets
        - `wchar_t` is gaurenteed to be large enough to hold any character in the machine's largest extended character set
        - `char16_t` and `char32_t` are intended for Unicode characters
    - reamaining integral types represent integer values of (potentially) different sizes
        - `int` will be as least as large as a `short`
        - a `long` at least as large as an `int`
        - `long long` at least as large as a `long`
- the floating point types represent single-, double-, and extended-precision values
    - `float`s are represented as 32 bits
    - `double`s are represented as 64 bits
    - `long double`s are represented in either 96 or 128 bites

- signed and unsigned types
    - a signed type represents negative and positive numbers
    - an unsigned type represents values only greater than or equal to 0

###### Exercises
1. the differences between `int`, `long long`, and `short` are the number of bits and therefore the range they can hold, the difference between `unsigned` and `signed` is `signed` can be negative while `unsigned` can only be positive and 0, the difference between a `float` and `double` are the number of bits and therefore the precision they show
2. `doubles`

##### 2.1.2 - Type Conversions
- the type of an object defines the data that an object might contain and what operations that object can perform
- among the operations that many types support is the ability to conver objects of the given type to other, related types

```cpp
bool b = 42;   // b is true
int i = b;     // i is 1
i = 3.14;      // i is 3
double pi = i;   // pi has value 3.0
unsigned char c = -1;   // assuming 8-bit chars, c has value 255
signed char c2 = 256;   // assuming 8-bit chars, the value of c2 is undefined
```

- expressions involving the unsigned types
    - is we use both `unsigned` and `int` values in an arithmetic expression, the `int` value ordinarily is converted to `unsigned`

###### Exercises
3. code output
    - 32
    - garbage value
    - 32
    - -32
    - 0
    - 0
4. `2_4.cpp`

##### 2.1.3 - Literals
- a literal is a self-evident value

- integer and floating-point literals
    - integers that start with 0 are octal
    - integers that begin with `0x` are hexadecimal
    - floating point literals include either a decimal point or an exponent specified using scientific notation
- character and character string literals
    - a character enclosed within single quotes is a literal of type `char`
    - zero or more characters enclosed in double quotations marks is a string literal
        - the type of string literal is array of constant `char`s
- escape sequences
    - characters that are nonprintable or have special meaning in the language are represented using escape sequences
- specifying the type of the literal
    - we can override the default type of an integer, floating-point, or character literal by supplying a suffix or prefix as listed
- boolean and pointer literals
    - the words `true` and `false` are literals of type `bool`
    - the word `nullptr` is a pointer literal

###### Exercises
5. types
    - character literal, wide character literal, string literal, string literal of wide characters
    - `int`, `unsigned int`, `long`, `unsigned long`, octal `int`, hexadecimal `int`
    - `double`, `float`, `long double`
    - `int`, `unsigned int`, `double`, `double`
6. the first line uses integer decimal literals, the second line uses integer octal literals
7. literal representations
    - string literal
    - double literal
    - float literal
    - long double literal
8. `2_8.cpp`

### 2.2 - Variables
- a variable provides us with named storage that our programs can manipulate
    - each variable has a type
    - the type determines the size and layout of the variable's memory, the range of values that can be stored within that memory, and the set of operations that can be applied to a variable

##### 2.2.1 - Variable Defintions
- a simple definition consists of a type specifier, followed by a list of one or more variable names seperated by commas, and ends with a semicolon
- a definition may optionally provide an initial value

- initializers
    - an object that is initialized gets the specified value at the moment it is created
- list initializations
    - the language defines several different forms of initializations
    - braced lists of initializers can be now be used whenever we initialize an object and in some cases when we assign a new value to an object
    - the compiler will not let us list initialize variables of built-in type if the initializer might lead to the loss of informatio
- default initialization
    - when we define a variable without an initializer, the variable is default initialized
    - variables are given the "default" value, which depends on the type of the variable and may also depend on where the variable is defined

###### Exercises
9. definitions
    - illegal definition, definitions have to be made on different lines that input
    - illegal, narrowing occurs
    - illegal, has to be done on seperate line
    - legal, truncation occurs
10. initial values
    - `global_str` is the empty string
    - `global_int` is the value 0
    - `local_int` is undefined
    - `local_str` is the empty string

##### 2.2.2 - Variable Declarations and Definitions
- seperate compilation lets us split out programs into several files, each of which can be compiled independently
- distinguishes between declarations and definitions
    - a declaration makes a name known to the program
    - a definition creates the associated entity
- to obtain a declaration that is not also a defintion, we add the `extern` keyword and may not probide and explicit initializer
- any declaration that includes an explicit initializer is a definition

###### Exercises
11. declarations/definitions
    - definition
    - definition
    - declaration

##### 2.2.3 - Identifiers
- can be composed of letters, digits, and the underscore chaarcter
- must begin with either a letter or an underscore

###### Exercises
12. valid identifiers
    - invalid, `double` is a reserved word
    - valid
    - invalid, dashes cannot be used in identifier names
    - invalid, identifiers cannot start with numbers
    - valid

##### 2.2.4 - Scope of a Name
- a scope is a part of a program in which a name has a particular meaning
- names are visible from the point they are declared until the end of scope in wich the declaration appears
- global scope are accessible throughout the entire program
- block scope, accessible only within the block and subsequent blocks they are defined in
- nested scope
    - the contained scope is referred to as an inner scope, the containing scope is the outer scope

###### Exercises
13. the value of j is 100
14. this is a valid program, the output is "100 45"

### 2.3 - Compound Types
- a compound type is a type that is defined in terms of another type

##### 2.3.1 - References
- a reference defined an alternative name for an object

```cpp
int ival = 1024;
int &refVal = ival;   // refVal refers to another name ival
int &refVal;          // error; a reference must be initializer
```

- instead of copying the initializer's value, we bind the reference to its initializer
- there is no way to rebind a reference to refer to a different object
- references must initialized
- a reference is an alias
    - all operations on that reference are actually operations on the object to which the reference is bound

###### Exercises
15. definitions
    - valid, truncation occurs
    - invalid, does not refer to an object
    - valid
    - invalid, references must be initialized on defintion
16. assignments
    - valid
    - valid
    - valid
    - invalid, d is not an `int` type
17. "10 10"

##### 2.3.2 - Pointers
- a pointer is a compound type that "points to" another type
- pointers are objects in their own right
- taking the address of an object
    - the pointer holds the address of an object, we get the address of an object by using the address-of operator
- pointer value
    - it can point to an object
    - point to the locations just immediately past the end of an object
    - can be a null pointer, indicating that it is not bound to any object
    - it can be incalidl values other than the preceding three are invalid
- using a pointer to accesss an object
    - we can use the dereference operator, `*`, to access that object
- null pointers
    - does not point to any object
- assignment and pointers
    - pointers and references give indirect access to other objects
    - once we have defined a reference, there is no way to make that reference refer to a different object
- other pointer operations
    - we can use pointers in a condition given that it has valid value
    - eqaulity can be done to show if they hold the same address
- `void*` pointers
    - can hold the address of any object
    - the type of the object at that address is unknown

###### Exercises
18. `2_18.cpp`
19. pointers are objects in their own right while references are not, pointers can point to multiple things in their lifetime while references cannot
20. sqaures i
21. definitions
    - illegal, `dp` can only point to addresses of type `double`
    - illegal, cannot assign a value 0 to a pointer through another variable
    - legal
22. the first condition chercks to see if it's a valid pointer, the second condition checks to see if the value is 0 or not
23. there is no way to check to see if a pointer points to a valid object
24. `*lp` can only point to variables that are `long` where `i` is an `int`

##### 2.3.3 - Understanding Compound Type Declarations
- a variable definition consists of a base type and list of declarators
- defining multiple variables
    - the type modifier of a variable does not apply to all the variables defined in a single statement
- pointers to pointers
    - no limit to how many type modifers can be applied to a declarator
    - `*` indicates each pointer level
- references to pointers
    - we may not have a pointer to a reference
    - read the definition from right to left

###### Exercises
25. types/values
    - `ip` is a pointer to an int and is NULL, `i` is an `int` and is default initialized, `&r` is a reference to an `int` and refers to the default initalized `i`
    - `i` is an int and is default initialized, `*ip` is a pointer to NULL
    - `*ip` is a pointer to NULL, `ip2` is a `int` which is default initialized

### 2.4 - `const` Qualifier
- prevent coe from inadvertently giving a new value to the variable we use, use `const`
- initialization and `const`
    - a `const` type can use most but not all of the same operations as the non`const` version
    - the `const`ness of `ci` matters only for operations that might change `ci`
- by default, `const` objects are local to a file

###### Exercises
26. legal declarations/defintions
    - illegal, `const` objects must be initialized
    - legal
    - legal, legal to copy values into a `const` object
    - illegal, `cnt` can be incremented, `sz` is const and is immutable
