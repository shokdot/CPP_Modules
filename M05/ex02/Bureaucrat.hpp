#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

public:
	Bureaucrat(const std::string &name, const int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;
	void promote();
	void demote();

	void signForm(AForm &form);
	void executeForm(AForm const &form);

private:
	Bureaucrat();
	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
