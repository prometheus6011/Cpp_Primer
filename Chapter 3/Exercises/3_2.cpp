#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline;

int main() {
  string word;
  while (cin >> word)
    cout << word << endl;

  string line;
  while (getline(cin, line))
    cout << line << endl;

  return 0;
}