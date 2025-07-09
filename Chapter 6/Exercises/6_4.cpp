#include <iostream>

using std::cout; using std::cin; using std::endl;

void fact()
{
  int inp = 0;
  cin >> inp;

  int res = 1;
  while (inp > 0) {
    res *= inp--;
  }

  cout << res << endl;
}

int main()
{
  fact();

  return 0;
}