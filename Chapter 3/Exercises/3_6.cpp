#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
  string word;
  cin >> word;

  for (auto &c : word)
    c = 'X';

  cout << word << endl;

  return 0;
}