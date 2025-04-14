#include <iostream>

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	if (a > b && a > c && a > d) {
		std::cout << "A is largest" << std::endl;
	} else {
		std::cout << "A is not largest" << std::endl;
	}

	return 0;
}
