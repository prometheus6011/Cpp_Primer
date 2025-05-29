#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::cin; using std::cout;
using std::endl; using std::string;

int main() {
  vector<string> res;
  string s;

  while (cin >> s)
    res.push_back(s);

  for (string r : res)
    cout << r << endl;

  return 0;
}