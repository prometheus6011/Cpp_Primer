#include <iostream>
#include <string>

int main()
{
	std::string s1, s2;

	std::cin >> s1 >> s2;

	if (s1 == s2)
		std::cout << "The strings are equal" << std::endl;
	else
		std::cout << "The strings are not equal" << std::endl;

	return 0;
}
