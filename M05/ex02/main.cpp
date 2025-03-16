#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm form("Tree");
			Bureaucrat Bot("Bot", 35);

			form.beSigned(Bot);
			form.execute(Bot);
			std::cout << "Form executed successfully" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm form("Robo");
			Bureaucrat Bot("Bot", 35);

			form.beSigned(Bot);
			form.execute(Bot);
			std::cout << "Form executed successfully" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm form("Robo");
			Bureaucrat Bot("Bot", 34);

			form.beSigned(Bot);
			form.execute(Bot);
			std::cout << "Form executed successfully" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm form("Franck");
			Bureaucrat Bot("Bot", 4);

			form.beSigned(Bot);
			std::cout << form << std::endl;
			form.execute(Bot);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
