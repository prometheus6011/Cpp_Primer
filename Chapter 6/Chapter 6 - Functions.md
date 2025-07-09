- chapter describes how to define and declare functions
- a function is a block of code with a name
	- execute the code by calling the function
### 6.1 - Function Basics
- a function definition typically consists of
	- return type
	- name
	- list of zero or more parameters
		- specified in a comma-separated list enclosed in parentheses
	- body
		- actions that the function performs
- execute a function through the call operator, a pair of parentheses
	- comma-separated list of arguments
- writing a function
	- function named `fact`
	- takes one `int` parameter and returns an `int` value
```cpp
// factorial of val is val * (val - 1) * (val - 2) ... * ((val - (val - 1)) * 1)
int fact(int val)
{
	int ret = 1;  // local variable to hold the result as we calculate it
	while (val > 1)
		ret *= val--;  // assign ret * val to ret and decrement val
	return ret;  // return the result
}
```
- calling a function
	- function call does two things
		- initializes the function's parameters from the corresponding arguments
		- it transfers control to that function
	- execution of the calling function is suspended and execution of the called function begins
	- execution of a function ends when a `return` statement is encountered
		- returns the value in the `return`
		- transfers control out of the called function back to the calling function
```cpp
int main()
{
	int j = fact(5);  // j equals 120
	cout << "5! is " << j << endl;
	return 0;
}
```
- parameters and arguments
	- arguments are the initializers for a function's parameters
	- the type of each argument must match the corresponding parameter in the same way that the type of any initializer must match the type of the object it initializes
	- must pass exactly the same number of arguments as the function has parameters
- function parameter list
	- function's parameter list can be empty but cannot be omitted
	- typically consists of a comma-separated list of parameters, each of which looks like a declaration with a single declarator
- function return type
	- most types can be used as the return type of a function
	- it may not be an array type or a function type
##### 6.1.1 - Local Objects
- C++ names have scope and objects have lifetimes
	- the scope of a name is the part of the program's text in which that name is visible
	- the lifetime of an object is the time during the program's execution that the object exists
- parameters and variables defined inside a function body are referred to as local variables
- objects defined outside any function exist throughout the program's execution
- automatic objects
	- objects that only exist while a block is executing
- local `static` objects
	- local variable whose lifetime continues across calls to the function
	- objects are not destroyed when a function ends, they are destroyed when the program terminates
```cpp
size_t count_calls()
{
	static size_t ctr = 0;
	return ++ctr;
}
```
##### 6.1.2 - Function Declarations
- the name of a function must be declared before we can use it
	- may be defined only one time but can be declared multiple times
	- we can declare a function that is not defined so long as we never use that function
- function declarations go in header files
	- variables are declared in header files and defines in source files, same with functions
##### 6.1.3 - Separate Compilation
- lets us split our programs into several files, each of which can be compiled independently
- compiling and linking multiple source files
### 6.2 - Argument Passing
- each time we call a function, its parameters are created and initialized by the arguments passed in the call
##### 6.2.1 - Passing Arguments by Value
- when we initialize a nonreference type variable, the value of the initializer is copied
	- changes made to the variable have no effect on the initializer
- pointer parameters
	- when we copy a pointer, the value of the pointer is copied
	- pointers give indirect access to the object to which the pointer points
##### 6.2.2 - Passing Arguments by Reference
- operations on reference are actually operations on the object to which the reference refers
- using references to avoid copies
	- it can be inefficient to copy objects of large class types or large containers
```cpp
// compare the length of two strings
bool isShorter(const string &s1, const string &s2) 
{
	return s1.size() < s2.size();
}
```
- using reference parameters to return additional information
	- reference parameters let us effectively return multiple results
##### 6.2.3 - `const` Parameters and Arguments
- when we copy an argument to initialize a parameter, top-level `const`s are ignored
- pointer or reference parameters and `const`
	- we can initialize an object with a low-level `const` from a non`const` object but not vice versa
- use reference to `const` when possible
##### 6.2.4 - Array Parameters
- we cannot copy an array, and when we use an array it is usually converted to a pointer
- using marker to specify the extent of an array
```cpp
void print(const char *cp)
{
	if (cp)  // if cp is not a null pointer
		while (*cp)  // so long as the character it points to is not a null character
			cout << *cp++;  // print the character and advance the pointer
}
```
- using the standard library conventions
```cpp
void print(const int *beg, const int *end)
{
	// print every element starting at beg up to but not including end
	while (beg != end)
		cout << *beg++ << endl;  // print the current element and advance the pointer
}

int j[2] = {0, 1};
print(begin(j), end(j));
```
- explicitly passing a size parameter
```cpp
void print(const int ia[], size_t size)
{
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << endl;
	}
}
```
- array reference parameters
```cpp
void print(int (&arr)[10])
{
	for (auto elem : arr)
		cout << elem << endl;
}
```
##### 6.2.5 - `main`: Handling Command-Line Options
```cpp
int main(int argc, char *argv[])
{

}
```
##### 6.2.6 - Functions with Varying Parameters
```cpp
void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout *beg << " ";
	cout << endl;
}

if (expected != actual)
	error_msg({"functionX", expected, actual});
```
- ellipsis parameters
```cpp
void foo(parm_list, ...);
```
### 6.3 - Return Types and the `return` Statement
- terminates the function that is currently executing and returns control to the point from which the function was called
##### 6.3.1 - Functions with No Return Value
- a `return` with no value may be used only in a function that has a return type of `void`
- `void` function use a `return` to exit the function at an intermediate point
```cpp
void swap(int &v1, int &v2)
{
	if (v1 == v2)
		return;

	int tmp = v2;
	v2 = v1;
	v1 = tmp;
}
```
##### 6.3.2 - Functions that Return a Value
- the value returned must have the same type as the function return type, or it must have a type that can be implicitly converted to that type
```cpp
bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;

	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}
```
- How Values are Returned
	- the return value is used to initialize a temporary at the call site, and that temporary is the result of the function call
	- the return type of this function is `string`, which means the return value is copied to the call site
```cpp
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}
```
```cpp
const string &shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
```
- never return a reference or pointer to a local object
- reference returns are lvalues
```cpp
char &get_val(string &str, string::size_type ix)
{
	return str[ix];
}

int main()
{
	string s("a value");
	cout << s << endl;
	get_val(s, 0) = 'A';
	cout << s << endl;
	return 0;
}
```
- list initializing the return value
```cpp
vector<string> process()
{
	if (expected.empty())
		return {};
	else if (expected == actual)
		return {"functionX", "okay"};
	else
		return {"functionX", expected, actual};
}
```
- return from `main`
```cpp
int main()
{
	if (some_failer)
		return EXIT_FAILURE;
	else
		return EXIT_SUCCESS;
}
```
- recursion
```cpp
int factorial(int val)
{
	if (val > 1)
		return factorial(val - 1) * val;
	return 1;
}
```
##### 6.3.3 - Returning a Pointer to an Array
- since we cannot copy an array, a function cannot return an array
- can return a pointer or a reference to an array
### 6.4 - Overloaded Functions
- functions that have the same name but different parameter lists and that appear in the same scope are overloaded
- same general action but apply to different parameter types, compiler deduces which function we want based on the argument type we pass
- it is an error for two functions to differ only in terms of their return types
- when declaring a function with `const` parameters it is different from a normal function
- calling an overloaded function
	- finds exactly one function that is a best match for the actual arguments and generated code to call that function
	- there is no function with parameters that match the arguments in the call, in which the case the compiler issues an error message that there was no match
	- there is more than one function that matches and none of the matches is clearly best. This case as also an error; it is an ambiguous call
##### 6.4.1 - Overloading and Scope
- names do not overload across scopes
### 6.5 - Features for Specialized Uses
##### 6.5.1 - Default Arguments
- functions have parameters that are given a particular value in most, but not all calls
- declare that common value as a default argument for the function
##### 6.5.2 - Inline and `constexpr` Functions
- benefits of defining a function for such a small operation
	- easier to read and understand a call to `shorterString` that it would be to read and understand the equivalent conditional expression
	- using a function ensures uniform behavior, each test is guaranteed to be done the same way
	- if we need to change the computation, it is easier to change the function than to find and change every occurrence of the equivalent expression
	- the function can be reused rather than rewritten for other applications
- `inline` functions avoid function call overhead
	- expanded "in line" at each call
	- meant to optimize small, straight-line functions that are called frequently
- `constexpr` functions
	- can be used in a constant expression
	- the `return` type and type of each parameter in it must be literal type and the function body must contain exactly one `return` statement
	- must generate no actions at run time
- put `inline` and `constexpr` functions in header files
##### 6.5.3 - aids for debugging
- the `assert` Preprocessor Macro
	- takes a single expression, which it uses as a condition
	- if the expression provided is false, then assert writes a message and terminates the program
### 6.6 - Function Matching
- determining the candidate and viable functions
	- the functions in the set of overloaded functions considered for a call are the candidate functions
	- from the set of candidate functions those functions that can be called with the arguments in the given call are the viable functions
		- eliminate candidate functions based on the number of arguments
- finding the best match, if any
	- looks at each argument in the call and selects the viable function (or functions) for which the corresponding parameter best matches the argument
- function matching with multiple parameters
	- set of viable functions is selected in the same way as when there is only one parameter
##### 6.6.1 - Argument Type Conversions
- order to determine the best match, the compiler ranks the conversions that could be used to convert each argument to the type of its corresponding parameter
- ranking
	- an exact match
		- argument and parameter types are identical
		- argument is converted from an array or function type to the corresponding pointer type
		- top-level const is added to or discarded from the argument
	- match through const conversion
	- match through a promotion
	- match through an arithmetic or pointer conversion
	- match through a class-type conversions, covers these conversions
- matches requiring promotion or arithmetic conversion
	- small integral types always promote to `int` or to a larger integral type
- function matching and `const` Arguments
### 6.7 - Pointers to Functions
- a pointer that denotes a function rather than an object
```cpp
bool (*pf)(const string&, const string&);
```
- using function pointers
	- the function is automatically converted to a pointer