#include <iostream>
#include <vector>

using std::vector; using std::cin; using std::cout;
using std::endl;

int main() {
  vector<int> res;
  int i;

  while (cin >> i)
    res.push_back(i);

  for (int i : res)
    cout << i << endl;

  return 0;
}