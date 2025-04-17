#include <iostream>
#include <stdexcept>

int main()
{
  int i1, i2;
  std::cin >> i1 >> i2;

  try {
    if (i2 == 0) {
      throw std::runtime_error("Cannot divide by 0.");
    }
    std::cout << static_cast<double>(i1) / i2 << std::endl;;
  } catch (std::runtime_error err) {
    std::cout << err.what() << std::endl;
  }

  return 0;
}