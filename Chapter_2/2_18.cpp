#include <iostream>

int main()
{
	int ival = 42;
	int ival2 = 10;

	int *pval = &ival;
	*pval = 12;

	pval = &ival2;

	std::cout << ival << "\t" << ival2 << "\t" << *pval << std::endl;

	return 0;
}
