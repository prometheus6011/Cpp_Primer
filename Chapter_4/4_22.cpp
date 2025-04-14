#include <iostream>

int main()
{
	int grade;
	std::cin >> grade;

	std::cout << (grade < 60 ? "Fail" :
			grade <= 75 ? "Pass" : "High Pass") << std::endl;

	return 0;
}
