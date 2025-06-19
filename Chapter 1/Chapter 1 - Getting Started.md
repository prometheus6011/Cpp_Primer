### 1.1 - Writing a Simple C++ Program
- every c++ program contains one or more functions, one of which must be named `main`
	- operating system runs a c++ program by calling `main`
- function definition has four elements
	- return type
	- function name
	- parameter list
	- function body
- `return` is a statement that terminates a function
	- value returns from `main` is a status indicator, `0` indicates success
### 1.2 - A First Look at Input/Output
- extensive standard library that provides IO
- fundamental to the `iostream` library are two types named `istream` and `ostream`
- standard input and output objects
	- the library defines four IO objects
		- `istream` object named `cin`
		- `ostream` object named `cout`, `cerr`, `clog`
```cpp
#include <iostream>
int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
	return 0;
}
```
- the name inside angle brackets refers to a header, every program that uses a library facility must include its associated header
- writing to a stream
	- an expression yields a result and is composed of one or more operands and (usually) an operator
	- the expressions use the output operator, `<<`
		- the left-hand operand must be an `ostream` object; the right hand operand is a value to print
- using names from the standard library
	- the prefix `std::` indicates that the named `cout` and `endl` are defined inside the namespace named `std`
- reading from a stream
	- the input operator, `>>` behaves analogously to the output operator
### 1.3 - A Word about Comments
- comments help the human readers of our programs
- compiler ignores comments, so they have no effect on the program's behavior or performance
- kinds of comments in c++
	- single line comments: `//`
	- comment blocks: `/* */`
### 1.4 - Flow of Control
##### 1.4.1 - The `while` Statement
- repeatedly executes a section of code so long as a given condition is true
```cpp
#include <iostream>
int main()
{
	int sum = 0, val = 1;
	while (val <= 10) {
		sum += val;
		++val;
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}
```
##### 1.4.2 - The `for` Statement
- same as `while` but can initialize a variable and a condition in one statement
```cpp
#include <iostream>
int main()
{
	int sum = 0;
	for (int val = 1; val <= 10; ++val) {
		sum += val;
	}
	std::cout << "Sum of 1 to 10 inclusive is "
		<< sum << std::endl;
	return 0;
}
```

##### 1.4.3 - Reading an Unknown Number of Inputs
```cpp
#include <iostream>
int main()
{
	int sum = 0, val = 0;
	while (std::cin >> value)
		sum += value;
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
```
##### 1.4.4 - The `if` Statement
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
### 1.5 - Introducing Classes
- a class defines a type along with a collection of operations that are related to that type
##### 1.5.2 - A First Look at Member Functions
- calls a member function of the class
- uses the `.` (dot) operator
- call a function using the call operator, `()`
### 1.6 - The Bookstore Program
```cpp
#include <iostream>
#include "Sales_item.h"
int main() {
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