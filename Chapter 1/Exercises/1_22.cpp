#include <iostream>
#include "Sales_item.h"

int main()
{
  Sales_item sum, item;
  std::cin >> sum;
  while (std::cin >> item && item.isbn() == sum.isbn()) {
    sum += item;
  }
  std::cout << sum << std::endl;

  return 0;
}