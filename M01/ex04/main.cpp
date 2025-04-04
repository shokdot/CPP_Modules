#include "Sed.hpp"

void validation(int ac, char **av, std::ifstream &infile)
{
	if (ac != 4)
		throw std::invalid_argument("Too few arguments!");
	infile.open(av[1]);
	if (!infile.is_open())
		throw std::invalid_argument(std::string("Can't open file ") + av[1]);
}

int main(int ac, char **av)
{
	std::ifstream infile;
	try
	{
		validation(ac, av, infile);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
	std::string new_file = std::string(av[1]) + ".replace";
	std::ofstream outfile(new_file.c_str());

	Sed replacer = Sed(infile, outfile);
	replacer.replace(av[2], av[3]);
	infile.close();
	outfile.close();
}
