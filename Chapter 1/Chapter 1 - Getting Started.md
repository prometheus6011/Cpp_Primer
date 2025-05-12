### 1.1 - Writing a Simple C++ Program
- every c++ program contains one or more functions, one of which must be named `main`
- a function definition has 4 elements
	- return type
	- function name
	- (possibly empty) parameter list
	- function body
- the `main` function is required to have a return type of `int`, which is a type that represents integers
- the function body is a block of statements starting with an open curly brace and ending with a close curly
- `return`, a statement that terminates a function
	- send a value back to the function's caller
- on most systems, the value returned from `main` is a status indicator
	- a value of 0 indicates success, while nonzero indicates failure
### 1.2 - A First Look at Input/Output
- the c++ language does not define any statements to do input or output, includes an extensive standard library that provides IO
- use the `iostream` library
	- `istream` objects - input streams
	- `ostream` objects - output streams
- a stream is a sequence of characters read from or written to an IO device
- standard input and output objects
	- `istream` object `cin` to handle input
	- `ostream` object `cout` to handle output
	- `ostream` object `cerr` to handle standard error
	- `ostream` object `clog` to handle general information about the execution of the program
- example
	- the first line of our program tells the compiler that we want to use the `iostream` library
	- `#include` directives must appear outside any function
```cpp
#include <iostream>
int main()
{
	std::cout << "Enter two numbers: " << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;

	return 0;
}
```
- writing to a stream
	- an expression yields a result and is composed of one or more operands and an operator
	- use the output operator, `<<` to print a message on the standard output
		- the left operand must be an `ostream` object, the right hand operand is a value to print
		- the result of the output operator is its left-hand operand
	- the result of the operator returns its left-hand operand, the result of the first operator becomes the left-hand operator of the second
	- message is a string literal, a sequence of characters enclosed in double quotation marks
	- prints `endl`, a special value called a manipulator
		- ends the current line and flushes the buffer associated with that device
- using names from the standard library
	- the prefix `std::` indicates that the names `cout` and `endl` are defined inside the namespace names std
- reading from a stream
	- define variables to hold the input
	- the input operator, `>>` behaves analogously to the output operator
		- takes an `istream` as its left-hand operand and an object as its right-hand operand
		- reads data from the given `istream` and stores what was read in the given object
		- returns its left-hand operand as its result
### 1.3 - A Word about Comments
- comments help the human readers of our programs, the compiler ignores comments, so they have no effect on the program's behavior or performance
- kinds of comments in c++
	- single line - `//` everything to the right of the slashes on the current line is ignored by the compiler
	- pairs - `/*` and `*/`, treats everything that falls between the pairs as part of the comment
- comment pairs do not nest
### 1.4 - Flow of Control
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
- executes by testing the condition and executing the associated statement until the condition is false
	- condition is an expression that yields a result that is either true or false
	- so long as condition is true, statement is executed
- a block is a sequence of zero or more statements enclosed by curly braces
##### 1.4.2 - The `for` Statement
- using a variable in a condition and incrementing that variable in the body happens so often that the language defines the `for` statement
```cpp
#include <iostream>
int main()
{
	int sum = 0;
	// sum values from 1 through 10 inclusive
	for (int val = 1; val <= 10; ++val)
		sum += val;
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}
```
- two parts
	- header
		- controls how often the body is executed
		- init-statement, a condition, and an expression
	- body
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
- we read the data inside the condition of the while
- the input condition returns its left operand, `cin`
	- when using an `istream` object as a condition, the effect is to test the state of the stream
	- if the stream is valid then the test succeeds
	- an `istream` becomes invalid when we hit end-of-file or encounter an invalid input
##### 1.4.4 - The `if` Statement
- supports conditional execution
```cpp
#include <iostream>
int main()
{
	// currVal is the number we're counting; we'll read new values into val
	int currVal = 0, val = 0;
	// read first number and ensure that we have data to process
	if (std::cin >> currVal) {
		int cnt = 1;  // store the count for the current value we're processing
		while (std::cin >> val) {
			if (val == currVal)
				++cnt;
			else {
				std::cout << currVal << " occurs " 
					<< cnt << " times" << std::endl; 
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs" << cnt << " times" << std::endl;
	}

	return 0;
}
```
### 1.5 - Introducing Classes
- a class defines a type along with a collection of operations that are related to that type
##### 1.5.1 - The `Sales_item` Class
- represents the total revenue, number of copies sold, and average price for a book
- operations
	- call a function names `isbn` to fetch the ISBN from a `Sales_item` object
	- use the input, `>>` and output `<<` operators to read and write object of type `Sales_item`
	- use the assignment operator, `=` to assign one `Sales_item` object to another
	- use the addition operator to add `Sales_item` objects, both must have the same ISBN
	- use the compound assignment operator `+=` to add one `Sales_item` object to another
##### 1.5.2 - A First Look at Member Functions
- a member function is a function that is defined as part of a class
	- sometimes referred to as methods
- uses the dot operator, `.`, to say that we want the `isbn` member of the object named `item1`
	- the dot operator only applies to objects of class type
- call the function using the call operator, `()`
	- encloses a possibly empty list of arguments
### 1.6 - The Bookstore Program
```cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

	return 0;
}
```