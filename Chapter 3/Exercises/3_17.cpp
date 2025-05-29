#include <cctype>
#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
  vector<string> para;
  string s;
  while (cin >> s)
    para.push_back(s);

  for (int i = 0; i < para.size(); ++i) {
    if (i != 0 && i % 8 == 0) {
      cout << endl;
    }
    for (char c : para[i])
      cout << (char)std::toupper(c);
    cout << " ";
  }
  cout << endl;

  return 0;
}