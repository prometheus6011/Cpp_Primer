#include <iostream>

using int_arr = int[4];

using std::cout; using std::endl;

int main() {
  int_arr ia[3] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11}
  };

  for (const int_arr (&row) : ia) {
    for (const int& col : row) {
      cout << col << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << ia[i][j] << " ";
    }
    cout << endl;
  }

  for (int_arr *p = ia; p != ia + 3; ++p) {
    for (int *q = *p; q != *p + 4; ++q) {
      cout << *q << " ";
    }
    cout << endl;
  }

  return 0;
}