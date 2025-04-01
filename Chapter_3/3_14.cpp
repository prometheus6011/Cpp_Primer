#include <iostream>
#include <vector>

int main()
{
	int t;
	std::vector<int> ivec;

	while (std::cin >> t) {
		ivec.push_back(t);
	}

	for (int i : ivec)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
