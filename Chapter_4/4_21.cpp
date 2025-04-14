#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec;
	int i;

	while (std::cin >> i) ivec.push_back(i);

	for (int i : ivec) {
		std::cout << (i % 2 == 0 ? i : i * 2) << std::endl;
	}

	return 0;
}
