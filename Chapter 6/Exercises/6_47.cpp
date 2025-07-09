#include <vector>
#include <iostream>

void printVecInt(const std::vector<int>::iterator bg,
                 const std::vector<int>::iterator ed) {
#ifndef NDEBUG
  std::cout << "In function: " << __func__ << ", "
            << "Vector size: " << ed - bg << std::endl;
#endif
  if (bg == ed)
    return;
  std::cout << *bg << std::endl;
  printVecInt(bg + 1, ed);
}

int main() {
  std::vector<int> vi = {1, 2,3, 4,5};

  printVecInt(vi.begin(), vi.end());

  return 0;
}