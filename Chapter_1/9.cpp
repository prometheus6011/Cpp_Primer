#include <iostream>

int main()
{
	int sum = 0, start = 50;
	while (start <= 100) {
		sum += start;
		++start;
	}

	std::cout << "The sum of the range of 50-100 inclusive is " << sum << std::endl;

	return 0;
}
