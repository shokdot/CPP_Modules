#include <iostream>
#include <fstream>
#include "RPN.hpp"

void validate(int ac)
{
	if (ac != 2)
		throw std::invalid_argument("Too Few arguments!");
}

int main(int ac, char **av)
{
	try
	{
		validate(ac);
		RPN::evaluate(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
