#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	struct GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

private:
	Form();

public:
	Form(const std::string &name, const int signGrade, const int executeGrade);
	Form(const Form &other);
	Form &operator=(const Form &rhs);
	~Form();

	void beSigned(const Bureaucrat &bur);

	const std::string &getName(void) const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void validateGrade(int grade);

private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
};

std::ostream &operator<<(std::ostream &os, Form &form);
