#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main()
{
	std::string word;
	std::vector<std::string> svec;

	while (std::cin >> word)
		svec.push_back(word);

	for (std::string &s : svec) {
		for (char &c : s) {
			c = std::toupper(c);
		}
	}

	for (int i = 1; i <= svec.size(); ++i) {
		if (i % 8 == 0) {
			std::cout << svec[i - 1] << std::endl;
		} else {
			std::cout << svec[i - 1] << " ";
		}
	}

	std::cout << std::endl;

	return 0;
}
