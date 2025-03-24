#include <iostream>

int main()
{
	int start = 0, end = 0;
	std::cin >> start >> end;

	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}

	for (int i = start; i <= end; ++i) {
		std::cout << i << std::endl;
	}

	return 0;
}
