#include <iostream>

int main()
{
  int start = 0, end = 0;
  std::cin >> start >> end;
  for (; start <= end; ++start) {
    std::cout << start << std::endl;
  }
  return 0;
}