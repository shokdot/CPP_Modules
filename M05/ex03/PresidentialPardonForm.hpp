#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
	PresidentialPardonForm();

public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};
