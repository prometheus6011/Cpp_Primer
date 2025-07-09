#include <iostream>

using std::cout; using std::cin; using std::endl;

int fact(int i) 
{
  int res = 1;
  while (i >= 1) {
    res *= i--;
  }
  return res;
}

int main() 
{
  int inp;
  cin >> inp;

  cout << fact(inp) << endl;

  return 0;
}
