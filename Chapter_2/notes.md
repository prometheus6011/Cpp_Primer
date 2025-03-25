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
