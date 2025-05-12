#include <iostream>

int main()
{
  int start = 50;
  int sum = 0;

  while (start <= 100) {
    sum += start;
    ++start;
  }

  std::cout << "The sum of values from 50 to 100 (inclusive): " << sum << std::endl;

  return 0;
}