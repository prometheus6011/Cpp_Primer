#include <iostream>
#include "Sales_item.h"

int main()
{
  Sales_item item, curr_item;
  std::cin >> item;

  int cnt = 1;
  while (std::cin >> curr_item) {
    if (item.isbn() == curr_item.isbn()) {
      item += curr_item;
      ++cnt;
    } else {
      std::cout << item << " occured " << cnt << " times" << std::endl;
      item= curr_item;
      cnt = 1;
    }
  }

  std::cout << item << " occured " << cnt << " times" << std::endl;

  return 0;
}