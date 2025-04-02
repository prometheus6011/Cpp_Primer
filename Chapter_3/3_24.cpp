#include <iostream>
#include <vector>

int main()
{
	int t;
	std::vector<int> ivec;

	while (std::cin >> t)
		ivec.push_back(t);

	auto left = ivec.begin();
	auto right = ivec.end() - 1;

	while (left <= right) {
		std::cout << *left + *right << std::endl;
		left++;
		right--;
	}

	return 0;
}
