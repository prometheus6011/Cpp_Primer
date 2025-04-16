#include <iostream>

int get_value()
{
  return 5;
}

int main()
{
  int ival1, ival2;

  // (a)
  if (ival1 != ival2)
    ival1 = ival2;
  else ival1 = ival2 = 0;

  // (b)
  int occurs, minval;
  if (ival1 < minval) {
    minval = ival1;
    occurs = 1;
  }

  // (c)
  int ival;
  if (ival = get_value())
    std::cout << "ival = " << ival << std::endl;
  if (!ival)
    std::cout << "ival = 0\n";

  // (d)
  if (ival == 0)
    ival = get_value();

  return 0;
}