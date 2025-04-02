#include <iostream>

int main()
{
	constexpr unsigned int sz = 10;
	int arr[sz];

	for (int i = 0; i < sz; ++i) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < sz; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
