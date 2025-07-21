- types determine the meaning of the data and operations in our programs
### 2.1 - Primitive Built-in Types
- C+ defines a set of primitive types that include the arithmetic types and a special type named `void`
##### 2.1.1 - Arithmetic Types
- integral types
	- `bool` type represents the truth values `true` and `false`
	- several character types, most of which exist to support internationalization
	- the remaining integral types represent integer values
- floating point types
	- represent single-, double-, and extended-precision values
- Signed and Unsigned Types
	- a signed type represents negative or positive numbers (including zero)
	- an unsigned type represents only values greater than or equal to zero
##### 2.1.2 - Type Conversions
- the ability to convert objects of the given type to other, related types
- Expressions Involving Unsigned Types
	- an `int` value is converted to `unsigned`
##### 2.1.3 - Literals
- a literal is a value that is self-evident
- Integer and Floating-Point Literals
```
20 // decimal
024  // octal
0x14 // hexadecimal

3.14159 // double
3.14159e0
0.
0e0
.001
```
- Character and Character String Literals
```
'a'  // character literal
"Hello World!"  // string literal
```
- Escape Sequences - characters that have no visible image
### 2.2- Variables
- provides us with names storage that our programs can manipulate
- each variable has a type
##### 2.2.1 - Variable Definitions
- definition consists of a type specifier, followed by a list of one or more variable names separated by commas, and ends with a semicolon
- definition may provide an initial value for one or more of the names it defines
- Initializers
	- gets the specified value at the moment it is created
- List Initialization
	- braced lists of initializers can be used whenever we initialize an object and in some cases when we assign a new value to an object
	- compiler will not let us list initialize variables of built-in type if the initializer might lead to the loss of information
- Default Initialization
	- variables without an initializer, the variable is default initialized
	- variables of built-in type defined inside a function are uninitialized
##### 2.2.2 - Variable Declarations and Definitions
- separate compilation lets us split out programs into several files, each of which can be compiled independently
- a declaration makes a name known to the program
- definition creates the associated entity
- add the `extern` keyword and may not provide an explicit initializer
##### 2.2.3 - Identifiers
- can be composed of letters, digits, and the underscore character
- must begin with either a letter or an underscore
- reserves a set of names, may not be used as identifiers
##### 2.2.4 - Scope of a Name
- given name can be reused to refer to different entities at different points in the program
- scope is a part of the program in which a name has a particular meaning
- names are visible from the point where they are declared until the end of the scope in which the declaration appears
- global scope - named defined outside any curly braces
- block scope - names defined inside curly braces
### 2.3 -  Compound Types
- type that is defined in terms of another type
##### 2.3.1 - References
- reference defines an alternative name for an object
- bind the reference to its initializer
- a reference is an alias
##### 2.3.2 - Pointers
- pointers are used for indirect access to other objects
- unlike reference, a pointer is an object in its own right
- taking the address of an object
	- use the address-of operator, `&`
- pointer value
	- point to an object
	- point to the location just immediately past the end of the object
	- can be a null pointer, indicating that it is not bound to any object
	- can be invalid; values other than the preceding three
- using a pointer to access an object
	- use the dereference object, `*`
- null pointers
- assignment and pointers
##### 2.3.3 - Understanding Compound Type Declarations
### 2.4 - `const` Qualifier
- variable whose value we know cannot be changed
- prevent code from inadvertently giving a new value to the variable we use
- initialization and `const`
	- we may use only those operations that cannot change an object
- `const` objects are local to a file
##### 2.4.1 - References to `const`
- a reference that refers to a `const` type, cannot be used to change the object to which the reference is bound
- initialization and references to `const`
	- we can initialize a reference to `const` from any expression that can be converted to the type of the reference
	- a reference to `const` may refer to an object that is not `const`
##### 2.4.2 - Pointers and `const`
- we can define pointers that point to either `const` or non`const` types
- `const` Pointers
##### 2.4.3 - Top-Level `const`
- top-level const to indicate that the pointer itself is `const`
- low-level const to indicate the object the pointer points to is `const`
##### 2.4.4 - `constexpr` and Constant Expressions
- an expression whose value cannot change and that can be evaluated at compile time
```cpp
constexpr int mf = 20;
constexpr int limit = mf + 1;
constexpr int sz = size();
```
### 2.5 - Dealing with Types
##### 2.5.1 - Type Aliases
- synonym for another type
- use either `typdef` or `using` statements
##### 2.5.2 - The `auto` Type Specifier
- let the compiler figure out the type for us by using the `auto` type specifier
- Compound Types, `const`, and `auto`
	- when we use a reference, we are really using the object to which the reference refers
	- auto ignored top-level consts
##### 2.5.3 - The `decltype` Type Specifier
- compiler deduces from an expression but does not want to use that expression to initialize the variable
### 2.6 - Defining Our Own Data Structures
- a way to group together related data element and a strategy for using those data
##### 2.6.1 - Defining the `Sales_data` Type
```cpp
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
```
