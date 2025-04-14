#include <iostream>

int main()
{
	int i;

	while (std::cin >> i && i != 42) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
