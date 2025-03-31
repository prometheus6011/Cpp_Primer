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

