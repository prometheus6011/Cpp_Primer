#include <iostream>

int main()
{
	int i1 = 0, i2 = 0;
	std::cin >> i1 >> i2;

	while (i1 <= i2) {
		std::cout << i1 << std::endl;
		++i1;
	}

	return 0;
}
