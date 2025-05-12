#include <iostream>
#include "Sales_item.h"

int main()
{
  Sales_item prev, curr;

  if (std::cin >> prev) {
    while (std::cin >> curr) {
      if (prev.isbn() == curr.isbn()) {
        prev += curr;
      } else {
        std::cout << prev << std::endl;
        prev = curr;
      }
    }
    std::cout << prev << std::endl;
  }

  return 0;
}