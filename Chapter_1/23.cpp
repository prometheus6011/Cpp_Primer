#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item prev, curr;
	if (std::cin >> prev) {
		int cnt = 1;
		while (std::cin >> curr) {
			if (prev.isbn() == curr.isbn()) {
				++cnt;
			} else {
				std::cout << cnt << std::endl;
				prev = curr;
				cnt = 1;
			}
		}
		std::cout << cnt << std::endl;
	}

	return 0;
}
