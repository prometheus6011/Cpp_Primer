#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;

	int i = 0;
	while (i < s.size()) {
		s[i] = 'X';
		++i;
	}

	for (int i = 0; i < s.size(); ++i) {
		s[i] = 'X';
	}

	for (char &c : s) 
		c = 'X';

	return 0;
}
