#include <iostream>

int main()
{
  int i = 7;
  int *ip = &i;

  *ip = 3;
  std::cout << *ip << std::endl;

  return 0;
}