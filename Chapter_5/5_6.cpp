#include <iostream>
#include <vector>
#include <string>

int main()
{
  const std::vector<std::string> grades = {"F", "D", "C", "B", "A", "A++"};
  int grade = 0;
  std::cin >> grade;

  std::cout << (grade < 60 ? grades[0] : grades[(grade - 50) / 10]) << std::endl;

  return 0;
}