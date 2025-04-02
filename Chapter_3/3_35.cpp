#include <iostream>
#include <iterator>

int main()
{
	int ia[10];

	for (int i : ia) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (auto it = std::begin(ia); it != std::end(ia); ++it)
		*it = 0;

	for (int i : ia)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
