#include <iostream>

using std::cout; using std::endl;

int counter() {
  static int ctr = 0;
  return ctr++;
}

int main() {
  for (int i = 0; i < 5; ++i) {
    cout << counter() << endl;
  }

  return 0;
}