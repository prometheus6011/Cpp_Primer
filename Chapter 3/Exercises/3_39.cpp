#include <iostream>
#include <cstddef>

using std::cout; using std::endl;

int main() {
  const char ca1[] = "First string";
  const char ca2[] = "Second string";

  if (strcmp(ca1, ca2) < 0) {
    cout << ca1 << endl;
  } else if (strcmp(ca1, ca2) == 0) {
    cout << "Same" << endl;
  } else {
    cout << ca2 << endl;
  }

  return 0;
}