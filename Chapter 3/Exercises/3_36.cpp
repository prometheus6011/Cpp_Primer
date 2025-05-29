#include <iostream>

using std::cout; using std::endl;

int main() {
  int ia1[10];
  int ia2[10];

  for (int i = 0; i != 10; ++i) {
    if (ia1[i] != ia2[i]) {
      cout << "false" << endl;
      return 0;
    }
  }

  cout << "true" << endl;

  return 0;
}