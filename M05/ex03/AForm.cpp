#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "The grade cannot be higer than 1.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "The grade cannot be lower than 150.";
}

const char *AForm::NotSigned::what() const throw()
{
	return "AForm not signed!";
}

AForm::AForm(const std::string &name, const int signGrade, const int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	validateGrade(signGrade);
	validateGrade(executeGrade);
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

AForm &AForm::operator=(const AForm &rhs)
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

void AForm::validateGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

AForm::~AForm() {}

const std::string &AForm::getName(void) const { return this->name; }

bool AForm::getSign(void) const { return this->isSigned; }

int AForm::getSignGrade(void) const { return this->signGrade; }

int AForm::getExecuteGrade(void) const { return this->executeGrade; }

void AForm::checkExecute(const Bureaucrat &executor) const
{
	if (!this->getSign())
		throw AForm::NotSigned();
	else if (executor.getGrade() > this->executeGrade)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, AForm &form)
{
	os << "Form Named: " << form.getName() << " execute grade is: " << form.getExecuteGrade() << " sign grade is: " << form.getSignGrade() << " isSigned: " << form.getSign();
	return os;
}
