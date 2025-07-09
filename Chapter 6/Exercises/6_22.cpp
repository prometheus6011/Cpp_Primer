#include <iostream>

void swapPtr(int **ip1, int **ip2)
{
  int *temp = *ip1;
  *ip1 = *ip2;
  *ip2 = temp;
}

int main()
{
  int i1 = 5, i2 = 7;
  int *ip1 = &i1;
  int *ip2 = &i2;
  swapPtr(&ip1, &ip2);

  return 0;
}