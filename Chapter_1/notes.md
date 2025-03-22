# Chapter 1 - Getting Started
- this chapter introduces most of the basic elements of C++
    - types
    - variables
    - expressions
    - statements
    - functions

### 1.1 - Writing a Simple C++ Program
- every C++ program contains one or more functions, one of which must be named `main`
    - the operating system runs a c++ program by calling `main`

```cpp
int main()
{
    return 0;
}
```

- a function definition has four elements
    - return type
    - function name
    - parameter list (possibly empty)
    - function body
- the `main` function is required to have a return type of `int`, which is a type that represents integers
    - the `int` is a built-in type, which means that it is one of the types the languages defines
- the only statement in this block is a `return`, which is a statement that terminates a function
    - as is the vase here, a `return` can also send a value back to the function's caller
    - the value returns must have a type that is compatible with the return type of the function
- on most systems, the value returns from `main` is a status indicator
    - a value of 0 indicates success
    - a nonzero value has a meaning that is defined by the system

##### 1.1.1 - Compiling and Executing our Program
- program source file naming convention
- program files are normally referrs to as a source file

###### Exercises
1. `.cpp`
2. 2.cpp

### 1.2 - A First Look at Input/Output
- C++ includes an extensive standard library thatv provides IO (and many other facilities)
- `iostream` library
    - `istream`
        - `cin`-handles input
    - `ostream`
        - `cout`, handles output
        - `clog`, logs information about program
        - `cerr`, handles error output
- a stream is a sequence of characters read from or written to an IO device

```cpp
#include <iostream>
int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
    return 0;
}
```

- the first line of our program `#include <iostream>` tells the compiler that we want to use the `iostream` library
    - the name inside the angle brackets refers to a header
    - every program that uses a library facility must include its associated header
- writing to a stream
    - the first statement in the body of `main` executes an expression
        - an expression yields a result and is composed of one or more operands and usually and operator
    - the expressions in this statement use the output operator, `<<` to print a message on the standard output
    - the `<<` takes two operands: the left hand operand must be an `ostream` object; the right hand operand is a value to print
    - the `<<` operand returns its left-hand operand, the result of the first operator becomes the left-hand operand of the second
    - the first output operator prints a message to the user, that message is a string literal which is a sequence of characters enclosed in double quotation brackets
    - the second operator prints `endl`, which is a special value called a manipulator
        - writing `endl` has the affect of ending current line and flushing the buffer associated with that device
- using names from the standard library
    - the prefix `std::` indicates that the names `cout` and `endl` are defined inside the namespace names std
- reading from a stream
    - having asked the user for input, we next want to read that input, we start by defining two variables to hold the input
    - we define these variables with type `int`, and initialize them to 0 which gives it the indicated value at the same time the variable is created
    - the next statement reads the input using the input operator, `>>`
    - the `>>` operator takes an `istream` operand as its left-hand and an object as its right-hand operand and reads data from the given `istream` and stores what was read in the given object
- completing the program
    - what remains is to print our result

###### Exercises
3. `3.cpp`
4. `4.cpp`
5. `5.cpp`
6. the statement is not legal, there is no left-hand `ostream` object for the second and third lines

### 1.3 - A Word about Comments
- comments helps the human readers of our programs
- the copmpiler ignores comments, so they have no effect on the program's behavior or performance
- kinds of comments in C++
    - `//` - single line comments
    - `/*  */` - multi-line comments
- comment pairs do not nest

###### Exercises
7. `7.cpp`
8. incorrect statements, `8.cpp`
    - valid statement
    - valid statement
    - invalid statement, double quotes do not close
    - valid statement
