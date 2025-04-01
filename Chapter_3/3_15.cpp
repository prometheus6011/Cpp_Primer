#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string word;
	std::vector<std::string> svec;

	while (std::cin >> word)
		svec.push_back(word);

	for (std::string s : svec)
		std::cout << s << " ";
	std::cout << std::endl;

	return 0;
}
