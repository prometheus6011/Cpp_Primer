#include <iostream>

int main()
{
  int sum = 0;
  int val = 0;

  while (std::cin >> val) {
    sum += val;
  }

  std::cout << "the sum is: " << sum << std::endl;

  return 0;
}