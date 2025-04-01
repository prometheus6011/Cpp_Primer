#include <iostream>
#include <vector>

int main()
{
	int t;
	std::vector<int> ivec;

	while (std::cin >> t)
		ivec.push_back(t);

	std::cout << ivec.cend() - ivec.begin() << std::endl;

	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
		std::cout << *it << std::endl;

	return 0;
}
