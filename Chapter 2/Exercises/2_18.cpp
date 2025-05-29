#include <iostream>

int main()
{
  int i1 = 42;
  int *p1;

  p1 = &i1;
  std::cout << *p1 << std::endl;

  *p1 = 7;
  std::cout << *p1 << std::endl;

  return 0;
}