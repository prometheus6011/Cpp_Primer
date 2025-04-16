#include <cctype>
#include <iostream>
#include <string>

int main()
{
  std::string line;
  std::getline(std::cin, line);

  int vowel_cnt = 0;
  int blanks_space = 0;
  int tabs = 0;
  int newlines = 0;
  int f__times = 0;
  for (int i = 0; i < line.size(); ++i) {
    line[i] = std::tolower(line[i]);
    if (line[i] == '\t') {
      ++tabs;
    } else if (line[i] == ' ') {
      ++blanks_space;
    } else if (line[i] == '\n') {
      ++newlines;
    } else if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') {
      ++vowel_cnt;
    } else if (line[i] == 'f' && (line[i + 1] == 'f' || line[i + 1] == 'l' || line[i + 1] == 'i')) {
      ++f__times;
    }
  }

  std::cout << vowel_cnt << std::endl;

  return 0;
}