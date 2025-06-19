#include <iostream>

int main()
{
  int sum = 0, start = 50;

  while (start <= 100) {
    sum += start;
    ++start;
  }

  std::cout << "The sum of 50 to 100 inclusive is: "
    << sum << std::endl;

  return 0;
}