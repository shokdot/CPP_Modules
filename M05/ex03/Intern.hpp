#pragma once
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	typedef struct s_form
	{
		std::string type;
		AForm *fptr;
	} t_form;

public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &rhs);
	~Intern();

	AForm *makeForm(const std::string &name, const std::string &target);
};
