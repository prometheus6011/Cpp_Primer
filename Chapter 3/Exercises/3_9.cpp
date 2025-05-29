#include <cctype>
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::ispunct;

int main() {
  string word;
  getline(cin, word);

  for (auto c : word) {
    if (!ispunct(c)) {
      cout << c;
    }
  }
  cout << endl;

  return 0;
}