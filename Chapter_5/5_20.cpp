#include <iostream>
#include <string>

int main()
{
  std::string prev, curr;
  std::cin >> prev;

  bool repeat = false;
  while (std::cin >> curr) {
    if (curr == prev) {
      repeat = true;
      break;
    }
    prev = curr;
  }

  std::cout << (repeat ? curr : "No word was repeated") << std::endl;

  return 0;
}