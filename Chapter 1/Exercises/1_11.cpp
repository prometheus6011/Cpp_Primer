#include <iostream>

int main()
{
  int start = 0, end = 0;
  std::cout << "Enter two numbers: ";
  std::cin >> start >> end;

  while (start <= end) {
    std::cout << start << std::endl;
    ++start;
  }

  return 0;
}