# Chapter 3 - Strings, Vectors, and Arrays

### 3.1 - Namespace `using` Declarations
- a `using` delcaration lets us use a name from a namespace without qualifying the name with a `namespace_name::`prefix
- a seperate `using` decleration is required for each name
- headers should not include `using` declarations

###### Exercises
1. `3_1.cpp`

### 3.2 - Library `string` Type
- a string is a variable-length sequence of characters

##### 3.2.1 - Defining and Initializing Strings
- we can default initialize a string, which creates an empty string 
- direct and copy froms of initialization
    - when we initialize the string using `=`, we use copy initialization
    - when we initialize the string without using `=`, we use direct initialization

```cpp
string s1 = "hiya";  // copy initialization
string s2("hiya");   // direct initialization
string s3(10, 'c');  // direct initialization
string s4 = string(10, 'c');  // copy initialization
```

##### 3.2.2 - Operations on strings
- reading and writing strings
    - we can use the same IO operators as the built-in types to read and write strings
- reading an unknown number of strings

```cpp
int main()
{
    string word;
    while (cin >> word)
        cout << word << endl;
    return 0;
}
```

- using `getline` to Read an entire line

```cpp
int main()
{
    string line;

    while (getline(cin, line))
        cout << line << endl;

    return 0;
}
```

- the string `empty` and `size` operations
    - the `empty` function returns a `bool` indicating whether the string is empty
    - the `size` member returns the length of a string
- comparing strings
    - two strings are equal if they have the same length and have the same characters at the same locations
    - if two strings have different lengths and if every character in the shorter string is equal to the corresponding character of the longer string, then the shorter string is less than the longer one
    - if any characters at corresponding positions in the two strings differ, then the result of the string comparison is the result of comparing the first character at which the strings differ
- assignment for strings
- adding two strings
    - adding two strings yields a new string that is the concatenation of the left-hand followed by the right-hand operand
- adding literals and strings
    - at least one operand to each `+` operator must be of string type

###### Exercises
2. `3_2.cpp`
3. for the string input operator, the first whitespace is treated as the delimiter, for the `getline` function, the first newline character is treated as the delimiter
4. `3_4.cpp`
5. `3_5.cpp`

##### 3.2.3 - Dealing with the Characters in a string
- processing every character? used a range-based `for`
    - this statement iterates through the elements in a given sequence and performs some operation on each value in that sequence

```cpp
string str("some string");
// print the characters in str one character to a line
for (auto c : str) {
    cout << c << endl;
}
```

- using a range `for` to change the characters in a string
    - define the loop variable as a reference type
- processing only some characters
    - the subscript operator, `[]` takes a `string::size_type` value that denotes the position of the character we want to access
    - the result of using an index outside the range of the suitable values is undefined
    - the value is referred to as an index

###### Exercises
6. `3_6.cpp`
7. if the loop control variable was `char` it would only copy the value into `c` instead of referencing it
8. `3_8.cpp`, for this specific exercise i would use the range `for`
9. it is valid, but the behavior is undefined since there is no way of bounds checking a subscript
10. `3_10.cpp`
11. the type of `c` is a `const char&`

### 3.3 - Library `vector` Type
- a vector is a collection of objects, all of which have the same type
- a vector is a class template

##### 3.3.1 - Defining and Initializing vectors
- default initialize a vector, which creates an empty vector of the specified type
- list initialize a vector

```cpp
vector<string> articles = {"a", "an", "the"};
vector<string> articles{"a", "an", "the"};
```

- creating a specified number of elements

```cpp
vector<int> ivec(10, -1);
vector<string> svec(10, "hi!");
```

- list initializer or element count?
    - when we use parentheses, we are saying that the values we supply are to be used to construct the object
    - when we use curly braces, we want to list initialize the object

###### Exercises
12. defintions
    - valid
    - invalid, needs to be a `vector<string>`
    - valid
13. elements and sizes
    - 0 elements
    - 10 elements, all zero
    - 10 elements, all 42
    - 1 element, 10
    - 2 elements, 10 and 42
    - 10 elements, all ""
    - 10 elements, all "hi"

##### 3.3.2 - Adding Elements to a vector
- `push_back`, member function to add elements onto the back of the vector

###### Exercises
14. `3_14.cpp`
15. `3_15.cpp`
16. `3_16.cpp`
17. `3_17.cpp`
18. it is undefined since the vector has no elements and is trying to access the first element
19. `3_19.cpp`
20. `3_20.cpp`

### 3.4 - Introducing Iterators
- iterators give us indirect access to the object

###### 3.4.1 - Using iterators
- members named `begin` and `end` returns iterators
    - `begin` returns the first element in the container
    - `end` returns one past the last element in the container
- iterator operations
    - comparison, `==` and `!=`
        - iterators are equal if they denote the same element or if they are both off-the-end iterators for the same container
        - unequal otherwise
    - `*`, dereference like a pointer
- moving iterators from one element to another
    - use the `++` increment operator to move from one element to another
- iterator types
    - `iterator` and `const_iterator`
        - `const_iterator` is like a pointer to const
- the `begin` and `end` operations
- combining dereference and member access
    - use the arrow operator to get a data member from a pointer

###### Exercises
21. `3_21.cpp`

##### 3.4.2 - Iterator Arithmetic
- arithmetic operations on iterators
    - add or subtract integral values and an iterator
    - returns a iterator forwards or backwards that many elements
    - we can also subtract two iterators so long as they refer to elements in, or off the end of, the same `vector` or `string`

###### Exercises
24. `3_24.cpp`
26. we wrote it this way to make sure we never come up with an invalid value and go off the end of the container

### 3.5 - Arrays
- arrays have fixed sizes; we cannot add elements to an array

##### 3.5.1 - Defining and Initializing Built-in Arrays
- dimension must be known at compile time, therefore a `constexpr`

```cpp
constexpr unsigned int sz = 42;

int arr[10];  // array of ten ints
int *parr[sz];  // array of 42 pointers to ints
```

- arrays can only hold objects, therefore no arrays of references
- explicitly initializing array elements
    - we can list initialize elements in an array, we can omit the dimension if this is the case
- character arrays are special since string literals always end with a null character
- no copy or assignment

###### Exercises
27. definitions
    - illegal, `buf_size` is not a `constexpr`
    - legal
    - legal
    - illegal, dimension needs to be one more for the space of the null character
28. values
    - `sa` is a array of empty strings
    - `ia` is an array of 10 0's
    - `sa2` is an array of 10 empty strings
    - `ia2` is an array of 10 undefined integers
29. arrays are not dynamic and cannot be resized
30. `ix` needs to start at 0 and go to `array_size - 1`
31. `3_31.cpp`
35. `3_35.cpp`  
