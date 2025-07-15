#include <iostream>
#include "Sales_item.h"

int main()
{
  Sales_item total, item;
  std::cin >> total;

  while (std::cin >> item) {
    if (item.isbn() != total.isbn()) {
      std::cout << total << std::endl;
      total = item;
    } else {
      total += item;
    }
  }

  std::cout << total << std::endl;

  return 0;
}