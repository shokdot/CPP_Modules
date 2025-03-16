#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade cannot be higer than 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade cannot be lower than 150.";
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name) = rhs.name;
		this->grade = rhs.grade;
	}
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::promote()
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	--this->grade;
}

void Bureaucrat::demote()
{
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	++this->grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " Bureaucrat signed" << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->name << " Bureaucrat couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
