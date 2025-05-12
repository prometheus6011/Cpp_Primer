#include <iostream>

int main()
{
  std::cout << "/*";
  std::cout << "*/";
  std::cout << /* "*/" */";  // illegal, needed a double quotes to finish the string literal
  std::cout << /* "*/" /* "/*" */;

  return 0;
}
