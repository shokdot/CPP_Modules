#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		const_cast<std::string &>(this->target) = rhs.target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecute(executor);
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
