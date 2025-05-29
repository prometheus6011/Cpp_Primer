#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
  int i;
  vector<int> v1;

  while (cin >> i)
    v1.push_back(i);

  for (int i = 1; i < v1.size(); ++i)
    cout << v1[i] + v1[i - 1] << " ";
  cout << endl;

  for (int i = 0; i <= v1.size() / 2; ++i)
    cout << v1[i] + v1[v1.size() - 1 - i] << " ";
  cout << endl;

  return 0;
}