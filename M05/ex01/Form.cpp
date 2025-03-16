#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "The grade cannot be higer than 1.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "The grade cannot be lower than 150.";
}

Form::Form(const std::string &name, const int signGrade, const int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	validateGrade(signGrade);
	validateGrade(executeGrade);
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

Form &Form::operator=(const Form &rhs)
{
	if (&rhs != this)
	{
		const_cast<std::string &>(this->name) = rhs.name;
		const_cast<int &>(this->signGrade) = rhs.signGrade;
		const_cast<int &>(this->executeGrade) = rhs.executeGrade;
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

void Form::validateGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

Form::~Form() {}

const std::string &Form::getName(void) const { return this->name; }

bool Form::getSign(void) const { return this->isSigned; }

int Form::getSignGrade(void) const { return this->signGrade; }

int Form::getExecuteGrade(void) const { return this->executeGrade; }

std::ostream &operator<<(std::ostream &os, Form &form)
{
	os << "Form Named: " << form.getName() << " execute grade is: " << form.getExecuteGrade() << " sign grade is: " << form.getSignGrade() << " isSigned: " << form.getSign();
	return os;
}
