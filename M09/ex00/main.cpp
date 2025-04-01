#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

void validate(int ac)
{
	if (ac != 2)
		throw std::invalid_argument("Usage: input.txt");
}

int main(int ac, char **av)
{
	try
	{
		validate(ac);
		BitcoinExchange instance("data.csv");
		instance.exchange(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
