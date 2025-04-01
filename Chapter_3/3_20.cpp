#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec;
	int t;

	while (std::cin >> t)
		ivec.push_back(t);

	for (int i = 0; i < ivec.size() - 1; ++i)
		std::cout << ivec[i] + ivec[i + 1] << " ";
	std::cout << std::endl;

	int left = 0;
	int right = ivec.size() - 1;
	while (left <= right) {
		std::cout << ivec[left] + ivec[right] << " ";
		++left;
		--right;
	}

	std::cout << std::endl;

	return 0;
}
