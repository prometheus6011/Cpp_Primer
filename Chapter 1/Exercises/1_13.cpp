#include <iostream>

int main()
{
  int sum = 0;
  for (int start = 50; start <= 100; ++start) {
    sum += start;
  }
  std::cout << sum << std::endl;

  return 0;
}