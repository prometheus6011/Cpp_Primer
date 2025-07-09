#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int add(int a, int b)
{
  return a + b;
}

int sub(int a, int b)
{
  return a - b;
}

int mul(int a, int b)
{
  return a * b;
}

int divi(int a, int b)
{
  return a / b;
}

int main()
{
  vector<int (*)(int, int)> fvec;
  fvec.push_back(add);
  fvec.push_back(sub);
  fvec.push_back(mul);
  fvec.push_back(divi);

  for (const auto& f : fvec) {
    cout << f(1, 2) << endl;
  }

  return 0;
}