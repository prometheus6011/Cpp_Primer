#include <iostream>
#include <vector>

using std::vector;
using std::begin; using std::end;

int main() {
  int ia[] = {1, 2, 3, 4, 5};
  vector<int> iv(begin(ia), end(ia));

  return 0;
}