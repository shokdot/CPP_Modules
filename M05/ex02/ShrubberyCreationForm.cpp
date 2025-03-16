#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		const_cast<std::string &>(this->target) = rhs.target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->checkExecute(executor);
	std::ofstream file(this->target + "_shrubbery");
	if (file.is_open())
	{
		file << apricot_tree;
		file.close();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
