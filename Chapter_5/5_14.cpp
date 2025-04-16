#include <iostream>
#include <string>

int main()
{
  std::string prev;
  std::cin >> prev;
  std::string curr;

  int cnt = 1;
  int max_cnt = 0;
  while (std::cin >> curr) {
    if (curr == prev) {
      ++cnt;
    } else {
      prev = curr;
      cnt = 1;
    }
    max_cnt = std::max(cnt, max_cnt);
  }

  std::cout << max_cnt << std::endl;

  return 0;
}