#include <iostream>

int main()
{
  int start, end;
  std::cin >> start >> end;
  if (end < start) {
    int temp = end;
    end = start;
    start = temp;
  }

  for (; start <= end; ++start) {
    std::cout << start << " ";
  }
  std::cout << std::endl;

  return 0;
}