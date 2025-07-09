#include <iostream>

void swap(int *ip1, int *ip2) {
  int temp = *ip1;
  *ip1 = *ip2;
  *ip2 = temp;
}

int main()
{
  int i1 = 5;
  int i2 = 7;
  std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;

  swap(&i1, &i2);

  std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;

  return 0;
}