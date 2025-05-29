#include <iostream>
#include <vector>

using std::vector;

int main() {
  vector<int> vi = {1, 2, 3, 4, 5};
  int ia[5];
  for (int i = 0; i < vi.size(); ++i) {
    ia[i] = vi[i];
  }

  return 0;
}