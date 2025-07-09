#include <string>

using std::string;

using str_arr = string[10];
str_arr &foo1();

auto foo2() -> string(&)[10];

string strs[10] = {};
decltype(strs) &foo3();