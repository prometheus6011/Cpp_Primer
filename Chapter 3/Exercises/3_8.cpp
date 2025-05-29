#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
  string word;
  cin >> word;

  int i = 0;
  while (i++ < word.size()) 
    word[i] = 'X';

  for (auto i = 0; i < word.size(); ++i)
    word[i] = 'X';

  cout << word << endl;

  return 0;
}