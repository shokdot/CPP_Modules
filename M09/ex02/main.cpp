#include <iostream>
#include "PmergeMe.hpp"

void validate(int ac, char **av, std::vector<int> &input)
{
	int nb;

	if (ac < 3)
		throw std::invalid_argument("Too Few arguments!");
	for (size_t i = 0; av[i] != NULL; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
			if (!isdigit(av[i][j]))
				throw std::invalid_argument("Not a digit value.");
		nb = std::atoi(av[i]);
		if (nb < 0)
			throw std::invalid_argument("Numbers must be positive.");
		input.push_back(nb);
	}
}

int main(int ac, char **av)
{
	try
	{
		std::vector<int> numbers;
		validate(ac, av + 1, numbers);
		std::vector<int>::const_iterator it = numbers.begin();
		std::vector<int>::const_iterator ite = numbers.end();
		std::cout << "Before: ";
		for (; it != ite; it++)
			std::cout << " " << *it;
		std::cout << std::endl;
		PmergeMe obj(numbers);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
