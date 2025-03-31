#include <iostream>
#include <string>

int main()
{
	std::string line, word;
	while (std::cin >> word)
		line += (word + " ");

	std::cout << line << std::endl;

	return 0;
}
