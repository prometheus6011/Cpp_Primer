#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec1 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
	std::vector<int> ivec2(10, 42);
	std::vector<int> ivec3;

	for (int i = 0; i < 10; ++i)
		ivec3.push_back(42);

	return 0;
}
