#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

int main() {
  std::vector<int> iv(10);
  for (int i = 0; i != 10; ++i)
    std::cin >> iv[i];
  for (auto it = iv.begin(); it != iv.end(); ++it)
    *it *= 2;
  for (const auto & elem : iv)
    std::cout << elem << " ";
  std::cout << std::endl;

  return 0;
}