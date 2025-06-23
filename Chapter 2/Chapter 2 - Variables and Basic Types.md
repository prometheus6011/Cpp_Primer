### 2.1 - Primitive Built-in Types
- C++ defines a set of primitive type that include the arithmetic types and a special type named `void`
##### 2.1.1 - Arithmetic Types
- integral types
	- `bool` - boolean
		- represents `true` or `false`
	- `char` - character (8 bits)
	- `wchar_t` - wide character (16 bits)
	- `char16_t` - Unicode character (16 bits)
	- `char32_t` - Unicode character (32 bits)
	- `short` - short integer (16 bits)
	- `int` - integer (16 bits)
	- `long` - long integer (32 bits)
	- `long long` - long integer (64 bits)
- floating-point types
	- `float` - single-precision floating-point (6 significant digits) (32 bits)
	- `double` - double-precision floating-point (10 significant digits) (64 bits)
	- `long double` - extended-precision floating-point (10 significant digits) (96 or 128 bits)
- Signed and Unsigned Types
	- integral types may be signed or unsigned
	- signed types represent negative or positive numbers, including zero; unsigned type represents only values greater than or equal to zero
##### 2.1.2 - Type Conversions
- ability to convert object of the given type to other, related types
```cpp
bool b = 42;           // b is true
int i = b;             // i is 1
i = 3.14;              // i is 3
double pi = i;         // pi = 3.0
unsigned char c = -1;  // assuming 8-bit chars, c = 255
signed char c2 = 256;  // assuming 8-bit chars, c2 = undefined
```
- the compiler applies these same type conversions when we use a value of one arithmetic type where a value of another arithmetic type is expected
- expressions involving unsigned types
	- is we use both `unsigned` and `int` values in an arithmetic expression, the `int` value ordinarily is converted to `unsigned`
##### 2.1.3 - Literals
- self-evident values
- integer and floating-point literals
	- write integer literals using decimal, octal, or hexadecimal notation
	- you can override default types using suffixes
- character and character string literals
	- character enclosed in single quotes is a literal of type `char`
	- zero or more characters enclosed in a double quotation marks is a string literal
		- the compiler appends a null character, `\0` to every string literal
- escape sequences
	- non-printable characters
- specifying the type of a literal
	- we can override the default type of an integer, floating-point or character literal by supplying a suffix or prefix
- boolean and pointer literals
	- `true` or `false`
### 2.2 - Variables
- variable is named storage that our programs can manipulate
##### 2.2.1 - Variable Definitions
- a simple variable definition consists of a type specifier, followed by a list of one or more variable named separated by commas, and ends with a semicolon
- a definition may (optionally) provide an initial value for one or more of the names it defines
- initializers
	- an object that is initialized gets the specified value at the moment it is created
- list initialization
	- the compiler will not let you initialize variables of built-in type if the initializer might lead to the loss of information
```cpp
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```
- default initialization
##### 2.2.2 - Variable Declarations and Definitions
- separate compilation lets us split our programs into several files, each of which can be compiled independently
- declarations make a name known to the program
- definition creates the associated entity
- to obtain a declaration that is not also a definition, we add the `extern` keyword and may not provide an explicit initializer
##### 2.2.3 - Identifiers
- identifiers in C++ can be composed of letters, digits, and the underscore character
- identifiers must begin with either a letter or an underscore
- reserved names cannot be used as identifiers
##### 2.2.4 - Scope of a Name
- each name is use refers to a specific entity - a variable, function, type and so on
- scope is a part of the program in which a name has a particular meaning
	- delimited by curly braces
- names defined outside a function has global scope, are accessible throughout the program
- Nested Scopes
	- scopes can contain other scopes, referred to as an inner scope and outer scope
	- the name defined in a scope can be used by scopes nested inside that scope
### 2.3 - Compound Types
- a type that is defined in terms of another types
##### 2.3.1 - References
- a reference defines an alternative name for an object
- ordinarily we copy the initializer into the object we are creating, defining a reference we bind the reference to its initializer
- there is no way to rebind a reference to refer to a different object
- a reference is an alias
	- all operations on the reference are actually on which the reference is bound
##### 2.3.2 - Pointers
- a pointer is a compound type that points to another object
- pointer is an object in its own right
- Taking the Address of an Object
	- a pointer holds the address of another object using the address-of `&` operator
	- the type of the pointer and the object to which it points must match
- Pointer Value
	- it can point to an object
	- it can point to the location just immediately past the end of an object
	- it can be a null pointer, indicating that it is not bound to any object
	- it can be invalid; values other than the preceding three are invalid
- using a pointer to access an object
	- when a pointer points to an object, we can use the dereference operator (`*`) operator
- Null Pointers
	- does not point to any object
	- initialize the pointer using the literal `nullptr`
	- it is illegal to assign an int variable to a pointer
- Assignment and Pointers
	- both pointers and references give indirect access to other objects
	- we give the pointer itself a new value when assigning
- Other Pointer Operations
- `void*` Pointers
	- special pointer type that can hold the address of any object
##### 2.3.3 - Understanding Compound Type Declarations
- defining multiple variables
	- variables defined in a single statement that have type modifiers are only affected if a type modifier prefixes them
- Pointers to Pointers
- References to pointers
	- read the definition from right to left, starting from the symbol closest to the name of the variable
### 2.4 - `const` Qualifiers
- define a variable whose value we know cannot be changes
- Initialization and `const`
	- we may use only those operations that cannot change an object
- By default, `const` Objects are Local to a File
	- the compiler will usually replace uses of the variable with its corresponding value during compilation
##### 2.4.1 - references to `const`
- bind a reference to an object of a `const` type
- a reference that refers to a `const` type
- Initialization and References to `const`
	- we can initialize a reference to `const` from any expression that can be converted to the type of the reference
	- to bind a type that is not of the same type the compiler builds a temporary object and is not bound to that
- a reference to `const` may refer to n object that is not `const`
##### 2.4.2 - Pointers and `const`
- we can define pointers that point to either `const` or non`const` types
- a pointer to `const` may not be used to change the object to which the pointer points
- we can use a pointer to `const` to point to a non`const` object
- `const` Pointers
	- the value that the pointer holds, the address, may not be changed
##### 2.4.3 - Top-Level `const`
- the term top-level `const` to indicate that the pointer itself is a `const`
	- appear in any object type
- when a pointer can point to a `const` object, we refer to that `const` as a low-level `const`
	- appears in the base type of compound types such as pointers or references
- when we copy an object, top-level `const`s are ignored
##### 2.4.4 - `constexpr` and Constant Expressions
- constant expression is an expression whose value cannot change and that can be evaluated at compile time
- `constexpr` variables
	- declare a variable in a `constexpr` declaration
	- implicitly `const` and must be initialized by constant expressions
- Literal Types
	- must be evaluated at compile time, there are limits on the types that we can use in a `constexpr` declaration
### 2.5 - Dealing with Types
##### 2.5.1 - Type Aliases
- type alias is a name that is a synonym for another type
- traditionally we use `typedef`
```cpp
typedef double wages;
```
- we can also use an alias declaration
```cpp
using SI = Sales_item;
```
- Pointers, `const`, and Type Aliases
```cpp
typedef char *pstring;
const pstring cstr = 0;  // cstr is a constant pointer to char
const pstring *ps;  //ps is a pointer to a constant pointer to char
```
##### 2.5.2 - The `auto` Type Specifier
- we can let the compiler figure out the type for us by using the `auto` type specifier
- must have an initializer
- Compound Types, `const`, and `auto`
	- when we use a reference, we are really using the object to which the reference refers
	- `auto` ordinarily ignored top-level `const`s
##### 2.3.5 - The `decltype` Type Specifier
- we want to define a variable with a type that the compiler deduces from an expression but do not want to use that expression to initialize the variable
- `decltype` can be used
```cpp
const int ci = 0, &cy = ci;
decltype(ci) x = 0;  // x has type const int
decltype(cj) y = x;  // y has type const int& and is bound to x
decltype(cj) z;  // error: z is a reference and must be initialized
```
- `decltype` and references
	- `decltype` returns a reference type for expressions that yield objects that can stand on the left-hand side of the assignment
### 2.6 - Defining Our Own Data Structures
##### 2.6.1 - Defining the `Sales_data` Type
```cpp
struct Sales_data {
	std::string bookNo;
	unsigned int units_sold = 0;
	double revenue = 0.0;
};
```
- Class Data Members
	- data members of a class define the contents of the objects of that class type
##### 2.6.2 - Using the `Sales_data` Class
- 