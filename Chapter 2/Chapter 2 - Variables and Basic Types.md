- types determine the meaning of the data and operations in our programs
### 2.1 - Primitive Built-in Types
- defines a set of primitive types that include the arithmetic types and a special type named `void`
	- arithmetic types represent characters, integers, boolean values, and floating-point numbers
	- `void` type has no associated values and can be used in only a few circumstances
##### 2.1.1 - Arithmetic Types
- integral types
- floating-point types
- the `bool` type represents the truth values `true` or `false`
- character types
	- the basic type is `char`
	- `wchar_t`, `char16_t`, and `char32_t` are used for extended character sets
- integer values
	- `int` is as long as a `short`
	- `long` is as long as a `int`
	- `long long` at least as large as a `long`
- floating-point types
	- `floats` are one word
	- `doubles` are two words
	- `long double` are either 3-4 words
- signed and unsigned types
	- integral types may be signed or unsigned
	- signed type represents negative or positive numbers
	- unsigned types represent values greater than or equal to zero
##### 2.1.2 - Type Conversions
- the type of an object defines the data that an object might contain and what operations that object can perform
- the ability to convert objects of the given type to other, related types
```cpp
bool b = 42;  // b is true
int i = b;    // i has value 1
i = 3.14;     // i has value 3
double pi = i;  // pi has value 3.0
unsigned char c = -1;  // assuming 8-bit chars, c has a value 255
signed char c2 = 256;  // assuming 8-bit chars, the value of c2 is undefined
```
- expressions involving unsigned types
	- if we use both `unsigned` and `int` values in an arithmetic expression, the `int` value ordinarily is converted to `unsigned`
	- if we subtract a value from an `unsigned`, we must be sure that the result cannot be negative
##### 2.1.3 - Literals
- a value that is self-evident
- integer and floating-point literals
	- write integer using decimal, octal, or hexadecimal notation
		- integer literals that begin with `0`, are octal
		- integer literals that begin with `0X`, are hexadecimal
	- type of an integer literals are signed
	- floating-point literals include either a decimal point or an exponent specified using scientific notation
		- the exponent is indicated by either `E` or `e`
	- floating-point literals have type `double` by default
- character and character string literals
	- a character enclosed within single quotes is a literal of type `char`
	- zero or more characters enclosed in double quotation marks is a string literal
		- the compiler appends a null character to every string literal
- escape sequences
	- used to represent non-printable characters or characters that have a special meaning in the language
- specifying the type of a literal
	- supply a suffix or prefix to specify the type
- boolean and pointer literals
	- `true` and `false` are literals of type `bool`
	- `nullptr` is a pointer literal
### 2.2 - Variables
- a variable provides us with named storage that our programs can manipulate
- the type determines the size and layout of the variable's memory, the range of values that can be stored within that memory
##### 2.2.1 - Variable Definitions
- a simple variable definition consists of a type specifier, followed by a list of one or more variable names separated by commas, and ends with a semicolon
- a definition may (optionally) provide an initial value for one or more of the names it defines
- initializers
	- an object that is initializes gets the specified value at the moment it is created
	- initialization happens when a variable is given a value when it is created, assignment obliterated an object's current value and replaces that value with a new one
- list initialization
	- use curly braces for initialization
	- be used whenever we initialize an object
	- the compiler will not let us list initialize variables of built-in type if the initializer might lead to the loss of information
- default initialization
	- when we define a variable without an initializer
	- default values is depends on the type of the variable and may also depend on where the variable is defined
	- the value of an uninitialized variable of built-in type id defined when inside a function
##### 2.2.2 - Variable Declarations and Definitions
- C++ supports separate compilation, split our programs into several files, each of which can be compiled independently
- C++ distinguishes between declarations and definitions
	- declarations makes a name known to the program
		- specifies the type and name of a variable
	- definition creates the associated entity
		- in addition to being a declaration, it also allocates storage and may provide the variable with an initial value
- to obtain a declaration that is not also a definition, we add the `extern` keyword
	- it is an error to provide an initializer on an `extern` inside a function
##### 2.2.3 - Identifiers
- can be composed of letters, digits, and the underscore character
- must begin with either a letter or an underscore
- case sensitive
- reserved names cannot be used as identifiers
##### 2.2.4 - Scope of a name
- scope is part of the program in which a name has a particular meaning
- names are visible from the point where they are declared until the end of the scope in which the declaration appears
- global scope - defined outside any function and outside any curly braces
	- accessible throughout the program
- block scope - accessible from its point of declaration but not outside of it
- nested scope - inner and outer scope
	- names declared in a scope can be used by scopes nested inside that scope
	- names declared in the outer scope can also be redefined in an inner scope
### 2.3 - Compound types
- a type that is defined in terms of other types
##### 2.3.1 - References
- a reference defines an alternative name for an object
- write a declarator of the form `&d`
- instead of copying the initializer's value, we bind the reference to its initializer
- there is no way to rebind a reference to refer to a different object, therefore reference must be initialized
- a reference is an alias
	- all operations on that reference are actually operations on the object to which the reference is bound
	- we may not define a reference to a reference
- the type of a reference and the object to which the reference refers must match exactly
- a reference may be bound only to an object, not to a literal or to the result of a more general expression
##### 2.3.2 - Pointers
- a pointer is a compound type that points to another type
- a pointer is an object in its own right
- can be assigned and copied; a single pointer can point to several different objects over its lifetime
- doesn't need to be initialized at the time it is defined
- writing a declarator `*d`
- taking the address of an object
	- pointers hold the address of another object, get the address using the address-of operator, `&`
	- we may not define a pointer to a reference since they don't have addresses
	- the types of the pointer and the object to which it points must match
- pointer value
	- can point to an object
	- can point to the location just immediately past the end of an object
	- can be a null pointer, indicating that it is not bound to any object
	- can be invalid; values other than the preceding three are invalid
- using a pointer to access an object
	- use the dereference operator, `*` to find the object that the pointer points
- null pointers
	- do not point to any object
	- it is illegal to assign an `int` variable to a pointer, even if the variable's value happens to be 0
- assignment and pointers
##### 2.3.3 - Understanding Compound Type Declarations
- a variable consists of a base type and a list of declarators
- defining multiple variables
	- the type modifier only applies to each variable defined after it
- pointers to pointers
- references to pointers
	- we may not have a pointer to a reference
	- we can define a reference to a pointer
	- read the definition right to left
```cpp
int *&r = p;  // r is a reference to the pointer p
```
### 2.4 - `const` Qualifier
- make a variable unchangeable by defining the variable's type as `const`
- must be initialized
- initialization and `const`
	- we may use only those operations that cannot change an object
- by default, `const` objects are Local to a file
	- the compiler usually replace uses of the variable with its corresponding value during compilation
##### 2.4.1 - References to `const`
- a reference that refers to a const type
- a reference to const cannot be used to change the object to which the reference is bound
- initialization and references to const
	- we can initialize a reference to const from any expression that can be converted to the type of the reference
		- we can bind a reference to const to a non-const object, a literal, or a more general expression
	- temporary object is an unnamed object created by the compiler when it needs a place to store a result from evaluating an expression
- a reference to const may refer to an object that is not const
	- binding a reference to const to an object says nothing about whether the underlying object itself is const
##### 2.4.2 - Pointers and const
- we can define pointers that point to const or non-const types
- we can use a pointer to const to point to a non-const object
- const pointers
	- a const pointer must be initialized, and once initialized, its value may not be changed
	- put the const after the `*`
##### 2.4.3 - Top-Level const
- top-level const is used to indicate that the pointer itself is const
- low-level const is used to indicate the what a pointer points to is a const object
- when we copy an object, top-level const is ignored
##### 2.4.4 - `constexpr` and Constant Expressions
- a constant expression is an expression whose value cannot change and that can be evaluated at compile time
- `constexpr` Variables
- literal types
### 2.5 - Dealing with Types
##### 2.5.1 - Type aliases
- a name that is a synonym for another type
- use `typedef`
- or use an alias declaration
- pointers, const, and type aliases
##### 2.5.2 - The `auto` type specifier
- let the compiler figure out the type for us by using the auto type specifier
- compound types, const, and auto
	- when we use a reference as an initializer, the initializer is the corresponding object
	- ignored top-level const
	- when asking for a reference to an auto-deduced type, top-level const in the initializer are not ignored
##### 2.5.3 - The `decltype` Type Specifier
- returns the type of its operand
- when the expression to which we apply decltype is a variable, decltype returns the type of that variable, including top-level const and references
- decltype and references
	- when the expression provided is not a variable, we get the type that the expression yields
### 2.6 - Defining our own Data Structures
##### 2.6.1 - Defining the `Sales_data` Type
```cpp
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
```
- class data members
	- data members of a class define the contents of the objects of that class type
	- supply in-class initializer for a data member
##### 2.6.2 - Using the `Sales_data` Class
##### 2.6.3 - Writing Our Own header Files
