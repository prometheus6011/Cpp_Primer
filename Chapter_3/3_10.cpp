#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string line;
	getline(std::cin, line);

	for (char c : line) {
		if (!std::ispunct(c)) {
			std::cout << c;
		}
	}

	std::cout << std::endl;

	return 0;
}
