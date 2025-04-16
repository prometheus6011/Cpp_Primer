#include <iostream>
#include <vector>
#include <string>

int main()
{
  const std::vector<std::string> grades = {"F", "D", "C", "B", "A", "A++"};
  int grade = 0;
  std::cin >> grade;

  if (grade < 60) {
    std::cout << grades[0] << std::endl;
  } else {
    std::cout << grades[(grade - 50) / 10] << std::endl;
  }

  return 0;
}