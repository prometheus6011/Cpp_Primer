#include <iostream>
#include <vector>

using std::vector;
using std::cin; using std::cout; using std::endl;

int main() {
  vector<int> vi;
  int i;
  while (cin >> i)
    vi.push_back(i);

  auto beg = vi.begin(), end = vi.end() - 1;
  while (beg <= end) {
    cout << *beg + *end << " ";
    ++beg, --end;
  }
  cout << endl;

  return 0;
}