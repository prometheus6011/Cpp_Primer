#include <iostream>
#include "Sales_data.h"

int main() {

  Sales_data total;
  double price = 0.0;
  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;
      if (total.bookNo == trans.bookNo) {
        total.revenue += trans.revenue;
        total.units_sold += trans.units_sold;
      } else {
        std::cout << total.bookNo << " " 
                  << total.units_sold << " "
                  << total.revenue << " " 
                  << (total.revenue / total.units_sold) << std::endl;
        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }

    std::cout << total.bookNo << " " 
              << total.units_sold << " "
              << total.revenue << " " 
              << (total.revenue / total.units_sold) << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  return 0;
}