#include <iostream>
#include <vector>

using std::vector;

int foo(int a, int b)
{
  return a + b;
}

int bar(int a, int b)
{
  return a * b;
}

int main()
{
  vector<int (*)(int, int)> fvec;
  fvec.push_back(foo);
  fvec.push_back(bar);

  return 0;
}