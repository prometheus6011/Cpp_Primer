#include "Chapter6.h"

int fact(int i)
{
  int res = 1;
  while (i >= 1) {
    res *= i--;
  }
  return res;
}