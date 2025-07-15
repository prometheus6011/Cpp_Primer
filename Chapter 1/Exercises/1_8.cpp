#include <iostream>

int main()
{
  std::cout << "/*" << std::endl;  // valid
  std::cout << "*/" << std::endl;  // valid
  std::cout << /* "*/" */ << std::endl;  // invalid
  std::cout << /* "*/" /* "/*" */ << std::endl;  // valid
  return 0; 
}