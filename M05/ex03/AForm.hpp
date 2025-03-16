#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
	struct NotSigned : public std::exception
	{
		const char *what() const throw();
	};

private:
	AForm();

public:
	AForm(const std::string &name, const int signGrade, const int executeGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm();

	void beSigned(const Bureaucrat &bur);
	virtual void execute(Bureaucrat const &executor) const = 0;

	const std::string &getName(void) const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void validateGrade(int grade);

protected:
	void checkExecute(const Bureaucrat &executor) const;

	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
};

std::ostream &operator<<(std::ostream &os, AForm &form);
