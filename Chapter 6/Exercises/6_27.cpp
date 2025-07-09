#include <initializer_list>
#include <iostream>

int sum(std::initializer_list<int> il)
{
  int res = 0;
  for (auto beg = il.begin(); beg != il.end(); ++beg) {
    res += *beg;
  }
  return res;
}

int main()
{
  std::cout << sum({1, 2, 3, 4, 5}) << std::endl;

  return 0;
}