#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
  string w1, w2;
  cin >> w1 >> w2;

  if (w1.size() == w2.size()) {
    cout << "Both Strings have the same length" << endl;
  } else if (w1.size() > w2.size()) {
    cout << "Word 1 is longer" << endl;
  } else {
    cout << "Word 2 is longer" << endl;
  }

  return 0;
}