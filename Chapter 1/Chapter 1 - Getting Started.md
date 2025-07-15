### 1.1 - Writing a Simple C++ Program
- every c++ program must contain one or more functions, one of which must be named `main`
- a function declaration has four elements
	- return type
	- function name
	- (possibly empty) parameter list
	- function body
- `main` function is required to have a return type of `int`
- the function body, is a block of statements starting with an open curly brace and ending with a close curly
##### 1.1.1 - Compiling and Executing Our Program
### 1.2 - A First Look at Input/Output
- c++ includes an extensive standard library that provides IO
- use the `iostream` library
	- `istream` objects
		- `cin` - for input
	- `ostream` objects
		- `cout` - for standard output
		- `cerr` - for standard error
		- `clog` - for general information about execution
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
- the first line `#include <iostream>` tells the compiler that we want to use the `iostream` library
	- refers to a header
	- `#include` directive
- Writing to a Stream
	- the first statement in the body executes an expression which yields a result and is composed of one or more operands and an operator
	- use the output operator, `<<`, to print a message on the standard output
	- the result of the output operator is its left-hand value of the given `ostream`
	- string literal, a sequence of characters enclosed in double quotation marks
	- `endl`, a manipulate, has the effect of ending the current line and flushing the buffer associated with that device
- Using Names from the Standard Library
	- the prefix `std::` indicates that the names `cout` and `endl` are defined inside the namespace names `std`
- Reading from a Stream
	- define two variables to hold the input
	- the input operator, `>>`, behaves analogously to the output operator
- Completing the Program
### 1.3 - A Word about Comments
- comments help the human readers of our programs
- single line comments - `//`
- multi line comments - `/* */`
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
- a `while` executes by testing the condition and executing the associated statement until the condition is false
- a condition is an expression that yields a result that is either true or false
##### 1.4.2 - The `for` Statement
```cpp
#include <iostream>
int main()
{
	int sum = 0;
	// sum values from 1 to 10 inclusive
	for (int val = 1; val <= 10; ++val) {
		sum += val;
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}
```
- header consists of init-statement, condition, and an expression
	- init-statement defines  an object and assigns it a value
	- the condition compares the current value and is tested each time through the loop
	- expression is executed after the `for` body
##### 1.4.3 - Reading an Unknown Number of Inputs
```cpp
#include <iostream>
int main()
{
	int sum = 0, val = 0;
	// read until end-of-file, calculating a running total of all values read
	while (std::cin >> value)
		sum += value;
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
```
- the condition reads the next number and stores the number
	- the condition will test `std::cin`, the effect is to test the state of the stream
	- becomes invalid when we hit end-of-file or encounter an invalid input
##### 1.4.4 - The `if` Statement
- supports conditional execution
```cpp
#include <iostream>
int main()
{
	// currVal is the nuber we're counting; we'll read new values into val
	int currVal = 0, val = 0;
	// read first number and ensure that we have data to process
	if (std::cin >> currVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == currVal)
				++cnt;
			else {
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
- `if` evaluates a condition, we execute the block that starts with the open curly following the condition
- if the condition is false, we execute the statement following the `else`
### 1.5 - Introducing Classes
- define a data structure to represent our transaction data
- define a class, defines a type along with a collection of operations that are related to that type
##### 1.5.2 - A First Look at Member Functions
- a member function is a function that is defined as part of a class
- sometimes referred to as methods
- uses the dot operator, `.`, to say that we want a member of the object
- we call a function using the call operator, `()`
### 1.6 - The Bookstore Program
```cpp
#include <iostream>
#include "Sales_item.h" 
int main()
{
	Sales_item total; // variable to hold data for the next transaction 
	// read the first transaction and ensure that there are data to process 
	if (std::cin >> total) { 
		Sales_item trans; // variable to hold the running sum 
		// read and process the remaining transactions 
		while (std::cin >> trans) { 
			// if we’re still processing the same book 
			if (total.isbn() == trans.isbn()) 
				total += trans; // update the running total 
			else { 
				// print results for the previous book 
				std::cout << total << std::endl; 
				total = trans; 
				// total now refers to the next book 
			}
		} 
		std::cout << total << std::endl; 
	} else {
		// no input! warn the user 
		std::cerr << "No data?!" << std::endl; 
		return -1; // indicate failure
	}
	return 0;
}
```