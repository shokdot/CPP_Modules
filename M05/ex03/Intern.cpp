#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm *exec = NULL;
	t_form form[] = {
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"", NULL}};

	for (int i = 0; form[i].fptr; i++)
	{
		if (form[i].type == name)
			exec = form[i].fptr;
		else
			delete form[i].fptr;
	}
	if (exec)
		std::cout << "Intern creates " << name << std::endl;
	else
		std::cout << "Wrong variation" << std::endl;
	return exec;
}
