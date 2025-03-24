#include <iostream>

int main()
{
	int sum = 0;
	for (int start = 50; start <= 100; ++start) {
		sum += start;
	}

	std::cout << "The sum of the range 50-100 inclusive is " << sum << std::endl;

	for (int start = 10; start >= 0; --start) {
		std::cout << start << std::endl;
	}

	return 0;
}
