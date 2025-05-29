### 3.1 - Namespace `using` Declarations
- names user the scope operator, `::` which tells the compiler to look in the scope of the left-hand operand for the name of the right-hand operand
- a `using` declaration lets us use a name from a namespace without qualifying the name with a `namespace_name::prefix`
- a separate `using` declaration is required for each name
- headers should not include `using` declarations
### 3.2 - Library `string` Type
- a string is a variable-length sequence of characters, must include the string header
##### 3.2.1 - Defining and Initializing strings
```cpp
string s1;  // default initialization; s1 is the empty string
string s2 = s1;  // s1 is a copy of s1, does not include the null character
string s3 = "hiya";  // s3 is a copy of the string literal
string s4(10, 'c');  // s4 is cccccccccc

// when we include the =, we are asking the compiler to copy initialize
// when we omit the =, we are asking the compiler to direct initialize
string s5 = "hiya";  // copy initialization
string s6("hiya");  // direct initialization
string s7(10, 'c');  // direct initialization; s7 is cccccccccc

string s8 = string(10, 'c');  // copy initialization; s8 is cccccccccc

string temp(10, 'c');  // temp is cccccccccc
string s8 = temp;  // copy temp into s8
```
##### 3.2.2 - Operations on strings
```cpp
// reading and writing strings
string s;  // empty string
cin >> s;  // read a whitespace-seperated string into s
cout << s << endl;  // write s to the output

// reading an unknwon number of strings
string word;
while (cin >> word)  // read until end-of-file
	cout << word << endl;  // write each word followed by a new line

string line;
// read input a aline at a time until end-of-file
while (getline(cin, line))  // getline reads until a newline 
	cout << line << endl;

// empty and size operations
// read input a line at a time and discard blank lines
while (getline(cin, line))
	if (!line.empty())  // empty returns a bool indicating the string is empty
		cout << line << endl

// read input a line at a time and print line that are longer than 80 chars
while (getline(cin, line))
	if (line.size() > 80)  // size returns the length of the string 
		cout << line << endl;

// string::size_type
// an unsigned type big enough to hold the size of any string
auto len = line.size();  // len has type string::size_type

// comparing strings
// 1. if two strings have different lengths and if every character in the shorter string is equal to the corresponding character of the longer string, then the shorter string is less than the longer one
// 2. if any characters at corresponding positions in the two strings differ, then the result of the string comparison is the result of comparing the first character at which the strings differ
// uses normal equality operators == and !=
// uses normal equality operators <, <=, >, >=

// Assignment for strings
string st1(10, 'c'), st2;  // st1 is ccccccccccc, st2 is an empty string
st1 = st2;  // assignment: replace contents of st1 with a copy of st2, both st1 and st2 are now the empty string

// Adding two strings
// use the + operator to concatenate two strings
string s1 = "hello, ", s2 = "world\n";
string s3 = s1 + s2;  // s2 is "hello, world\n"
s1 += s2;  // equivalent to s1 = s1 + s2

// adding literals and strings
string s1 = "hello", s2 = "world";  // no punctuation in s1 or s2
string s3 = s1 + ", " + s2 + '\n';
// when we mix strings and and string or character literals, at least one operand to each + operator must be of string type
```
##### 3.2.3 - Dealing with the characters in a string
```cpp
// using range-based for
string str("some string");
// print the characters in str one character to a line
for (auto c : str)  // for every char in str
	cout << c << endl;  // print the current character followed by a newline

// using a range for to change the characters in a string
string s("Hello World!!!");
// convert s to uppercase
for (auto &c : s)  // for every char in s
	c = toupper(c);  // c is a reference, so the assignment changes the char in s

cout << s << endl;

// processing only some characters
// use the subscript operator []
	// bounds in the operator is from 0 to size - 1

// using a subscript for iteration
for (decltype(s.size()) index = 0;
	 index != s.size() && !isspace(s[index]); ++index)
		s[index] = toupper(s[index]);
```
### 3.3 - Library vector type
- collection of objects, all of which have the same type
- include the vector header
- vector is a class template
	- instructions to the compiler for generating classes or functions
##### 3.3.1 - Defining and Initializing vectors
```cpp
vector<string> svec;  // default initializatiom, svec has no elements

vector<int> ivec;  // initially empty
// give ivec some values
vector<int> ivec2(ivec);  // copy elements of ivec into ivec2
vector<int> ivec3 = ivec;  // copy elements of ivec into ivec3
vector<string> svec(ivec2);  // error: svec holds strings, not ints

// list initalizaing a vector
vector<string> articles = {"a", "an", "the"};
vector<string> v1{"a", "an", "the"};
vector<string> v2("a", "an", "the");  // error

// creating a specified number of elements
vector<int> ivec(10, -1);  // ten int elements, each initialized to -1
vector<string> svec(10, "hi!");  // tehn string, each element is "hi!"

// value initialization
vector<int> ivec(10);  // ten elements, each initialized to 0
vector<string> svec(10);  // ten elements, each an empty string
```
##### 3.3.2 - Adding Elements to a vector
```cpp
// push_back adds elements at run time and psuhsed that value as a new element onto the back of the vector
vector<int> v2;  // empty vector
for (int i = 0; i != 100; ++i)
	v2.push_back(i);  // append sequantial integers to v2
// at end of loop v2 has 100 elements, values 0...99
```
##### 3.3.3 - Other vector operations
```cpp
// using a range for on a vector
vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
for (auto &i : v)  // for each element in v
	i *= i;  // square the element value

for (auto i : v) // for each element in v
	cout << i << " ";  // print the element
cout << endl;

// the same empty and size memebers behave as they do the corresponding string members
// size() returns vector<T>::size_type

// equality and relational operators have the same behavior

// computing a vector index
vector<unsigned> scores(11, 0);  // 11 buckets, all initially 0
unsigned grade;
while (cin >> grade) {  // read the rade 
	if (grade <= 100)  // handle only valid grades
		++scores[grade/10];  // increment the counter for the current cluster
}

// subscripting does not add elements
```
### 3.4 - Introducing Iterators
- iterators is a more general mechanism to access characters in containers
- like pointers, iterators give us indirect access to an object
###### 3.4.1 - using iterators
```cpp
// members named begin and end to return iterators
auto b = v.begin(), e = v.end();
// end positions an iterator one past the end of the associated container

// iterator operations
// compare two valid iterators using == or !=, equal if they denote the same element
string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
	auto it = s.begin();  // it denotes the first character in s
	*it = toupper(*it);  // make that character uppercase
}

// moving iterators from on element to another
// use the increment and decrement operator to move from on element to the next
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
	*it = toupper(*it);
}

// iterator types
vector<int>::iterator it;  // it can read and write vector<int> elements
string::iterator it2;  // it2 can read and write characters in a string
vector<int>::const_iterator it3;  // it3 can read but not write elements
string::const_iterator it4;  // it4 can read but not write elements

// the begin and end operations
vector<int> v;
const vector<int> cv;
auto it1 = v.begin();  // it1 has type vector<int>::iterator
auto it2 = cv.begin();  // it2 has type vector<int>::const_iterator
auto it3 = v.cbegin();  // it3 has type vector<int>::const_iterator

// combining dereference and member access
(*it).empty();
it->empty();
```
##### 3.4.2 - Iterator Arithmetic
```cpp
// arithmetic operations on iterators

// compute an iterator to the element closest to the midpoint of vi
auto mid = vi.begin() + vi.size() / 2;

if (it < mid)
	// process elements in the first half of vi

// using iterator arithmetic

// text must be sorted
// beg and end will denote the range we're searching
auto beg = text.begin(), end = text.end();
auto mid = text.begin() + (end - beg) / 2;
while (mid != end && *mid != sought) {
	if (sought < *mid)
		end = mid;
	else
		beg = mid + 1;
	mid = beg + (end - beg) / 2;
}
```
### 3.5 - Arrays
##### 3.5.1 - defining and initializing built-in arrays
```cpp
unsigned cnt = 42;  // not a constant expression
constexpr unsigned sz = 42;  // constant expression

int arr[10];  // array of ten ints
int *parr[sz];  // array of 42 pointers to int
string bad[cnt];  // error: cnt is not a constant expression

// explicitly initializing array elements
const unsigned sz = 3;
int ia1[sz] = {0, 1, 2};
int a2[] = {0, 1, 2};
int a3[5] = {0, 1, 2};
string a4[3] = {"hi", "bye"};
int a5[2] = {0, 1, 2};  // error

// character arrays are special
char a1[] = {'C', '+', '+'};  // no null
char a2[] = {'C', '+', '+', '\0'};  // explicit null
char a3[] = "C++";  // null added auto
const char a4[6] = "Daniel";  // error, no space for null

// no copy or assignment
int a[] = {0, 1, 2};  // array of 3 ints
int a2[] = a;  // cannot initialize one array to another
a2 = a;  // cannot assign one array to another

// understanding complicated array declarations
int *ptrs[10];  // ptrs is an array of ten pointers to int
int &refs[10] = /* ? */;  // no arrays of references
int (*Parray)[10] = &arr;  // Parray points to an array of ten ints
int (&arrRef)[10] = arr;  // arrRef refers to an array of ten ints
```
##### 3.5.2 - Accessing the elements of an array
```cpp
unsigned scores[11] = {};
unsigned grade;
while (cin >> grade)
	if (grade <= 100)
		++scoares[grade / 10];

for (auto i : scores)
	cout << i << " ";
cout << endl;
```
##### 3.5.3 - Pointers and Arrays
```cpp
string nums[] = {"one", "two", "three"};  // array of strings
string *p = &nums[0];  // p points to the first element in nums
string *p2 = nums;  // equivalant to p2 = &nums[0]

// pointers are iterators
int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *b = arr;
++b;
int *e = &arr[10];
for (int *b = arr; b != e; ++b)
	cout << *b << endl;

// library begin and end functions
int *beg = begin(ia);
int *end = end(ia);

// pointer arithmetic
constexpr size_t sz = 5;
int arr[sz] = {1, 2, 3, 4, 5};
int *ip = arr[0];
int *ip2 = ip + 4;  // arr[4]
```
##### 3.5.4 - C-Style Character Strings
```cpp
// C Library String functions
char ca[] = {'C', '+', '+'};  // not null terminated
cout << strlen(ca) << endl;  // disaster: ca is not null terminated

// comparing two strings
const char ca1[] = "A string example";
const char ca2[] = "A different string";
if (ca1 < ca2) // undefined
if (strcmp(ca1, ca2) < 0) // same affect as string comparison s1 < s2

// caller is responsible for size of a destination string
// disastrous if we miscalculate the size of largeStr
strcpy(largeStr, cal);
strcat(largeStr, " ");
strcat(largeStr, ca2);
```
##### 3.5.5 - Interfacing to Older Code
```cpp
const char *str = s.c_str();
```
### 3.6 - Multidimensional Arrays
- arrays of arrays
```cpp
int ia[3][4];  // array of size 3, each element is an array of ints of size 4
int arr[10][20][30] = {0};  // initialize all elements to 0

// initializing the elements of a multidimensional array
int ia[3][4] = {
	{0, 1, 2, 3},
	{4, 5, 6, 7},
	{8, 9, 10, 11}
}
int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int ia[3][4] = {{0}, {4}, {8}};
int ix[3][4] = {0, 3, 6, 9}; // only first row

// subscripting a multidimensional array
ia[2][3] = arr[0][0][0];
int (&row)[4] = ia[1];

// using a range for
size_t cnt = 0;
for (auto &row : ia)
	for (auto &col : row) {
		col = cnt;
		++cnt;
	}
// always use references when doing this
```