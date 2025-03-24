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
    - invalid statement, extra closing comment sequence

### 1.4 - Flow of Control
- programming languages provide various flow-of-control statements that allow for more complicated execution paths

##### 1.4.1 - The `while` Statement
- repeatedly executes a section of code so long as a given condition is true

```cpp
#include <iostream>

int main()
{
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10) {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}
```

- a `while` executes by testing the condition and executing the associated statement until the condition is false
    - a condition is an expression that yields a result that is either true or false
- a block is a sequence of zero or more statements enclosed by curly braces

###### Exercises
9. `9.cpp`
10. `10.cpp`
11. `11.cpp`

##### 1.4.2 - The `for` Statement

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    // sum values from 1 to 10 inclusive
    for (int val = 1; val <= 10; ++val)
        sum += val;
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}
```

- each `for` statement has two parts
    - the header controls hopw often the body is executed
        - the header itself contains three parts: an init-statement, a condition, and an expression
    - a body

###### Exercises
12. the following for loop calculates the sum of [-100, 100], the final result is 0
13. `13.cpp`

##### 1.4.3 - Reading an Unknown Number of Inputs

```cpp
#include <iostream>

int main()
{
    int sum = 0, value = 0;
    // read until end-of-file, calculating a running total of all values read
    while (std::cin >> value)
        sum += value;
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}
```

- the condition reads the next number from the standard input and stores that number in value
- when we use an `istream` as a condition, the effect is to test the state of the stream
    - if the stream if valid - that is the stream hasn't encountered an error - then the test succeeds
    - an `istream` becomes invalid when we hit end-of-file or encounter a invalid input, such as reading a value that is not an integer

###### Exercises
16. `16.cpp`

##### 1.4.4 - The `if` Statement
- the `if` statement supports conditional execution

```cpp
#include <iostream>

int main()
{
    int currVal = 0, val = 0;
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal) {
                ++cnt;
            } else {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }

    return 0;
}
```

- `if` evaluates a condition
    - if the `if` succeeds, then the condition is ture and we execute the block that starts with the open curly following the condition

###### Exercises
17. if all the input values are equal, then the program will print one line with the number and the amount of times it was entered, if all the input values are different, then the program will print a line for each number
18. `18.cpp`
19. `19.cpp`

### 1.5 - Introducing Classes
- a class defines a type along with a collection of operations that are related to that type

##### 1.5.1 - The `Sales_item` Class
- represents the total revenue, numbers of copies sold, and average price for a book
- operations
    - call a function `isbn` to fetch the ISBN from a `Sales_object`
    - use the input (`>>`) and output (`<<`) operators to read and write objects of type `Sales_item`
    - assignment (`=`) to assign one `Sales_item` object
    - use the addition (`+`) operator to add two `Sales_item` objects
        - they must have the same ISBN
        - the result is a new `Sales_item` object whose ISBN is that of its operands and whose numbers sold and revenue are the sum of the corresponding vallues in its operands
    - use the compound assignment operator (`+=`) to add one `Sales_item` object into another

- Reading and Writing `Sales_item`s
