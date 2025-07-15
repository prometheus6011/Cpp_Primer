#include <iostream>

int main()
{
  std::cout << "Enter two numbers: ";
  int start = 0, end = 0;
  std::cin >> start >> end;
  while (start <= end) {
    std::cout << start++ << std::endl;
  }
  return 0;
}