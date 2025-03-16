#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm *f;

	f = intern.makeForm("shrubbery creation", "28C");
	std::cout << *f << std::endl;
	std::cout << std::endl;

	f = intern.makeForm("robotomy request", "28B");
	std::cout << *f << std::endl;
	std::cout << std::endl;

	f = intern.makeForm("presidential pardon", "28A");
	std::cout << *f << std::endl;
	std::cout << std::endl;

	f = intern.makeForm("undefined", "0U");
	delete f;
	return 0;
}
