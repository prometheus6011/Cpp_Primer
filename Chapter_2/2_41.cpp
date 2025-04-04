#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	Sales_data total, trans;
	double price = 0;

	if (std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			} else {
				std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
				if (total.units_sold != 0)
					std::cout << total.revenue / total.units_sold << std::endl;
				else
					std::cout << "(No sales)" << std::endl;
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}

		std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
		if (total.units_sold != 0)
			std::cout << total.revenue / total.units_sold << std::endl;
		else
			std::cout << "(No sales)" << std::endl;
	} else {
		std::cerr << "No data for item!" << std::endl;
		return -1;
	}

	return 0;
}
