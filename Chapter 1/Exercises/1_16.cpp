#include <iostream>

int main()
{
  int temp, sum;
  while (std::cin >> temp)
    sum += temp;

  std::cout << "Sum is: " << sum << std::endl;

  return 0;
}