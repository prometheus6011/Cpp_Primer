#include <iostream>
#include <vector>

int main()
{
  std::vector<int> ivec = {0, 1, 1, 2};
  std::vector<int> ivec2 = {0, 1, 1, 2, 3, 5, 8};

  for (int i = 0; i < ivec.size(); ++i) {
    if (ivec[i] != ivec2[i]) {
      std::cout << "False" << std::endl;
      return 0;
    }
  }

  std::cout << "True" << std::endl;

  return 0;
}