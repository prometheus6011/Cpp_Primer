#include <iostream>
#include "Sales_item.h"

int main()
{
  Sales_item item, total;
  std::cin >> total;
  while (std::cin >> item) {
    if (total.isbn() != item.isbn()) {
      std::cout << total << std::endl;
      return 0;
    }
    total += item;
  }

  return 0;
}