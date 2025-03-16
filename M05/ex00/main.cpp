#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat1("Alice", 50);
		std::cout << bureaucrat1 << std::endl; // Expected: "Alice, bureaucrat grade 50"

		Bureaucrat bureaucrat2("Bob", 1);
		std::cout << bureaucrat2 << std::endl; // Expected: "Bob, bureaucrat grade 1"

		Bureaucrat bureaucrat3("Charlie", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl; // Expected: "Error: Grade too high"
	}

	try
	{
		Bureaucrat bureaucrat4("Dave", 151); // Should throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl; // Expected: "Error: Grade too low"
	}

	try
	{
		// Valid Bureaucrat creation
		Bureaucrat bureaucrat5("Eve", 50);

		// Test grade promotion and demotion
		bureaucrat5.promote();				   // Grade should be 49
		std::cout << bureaucrat5 << std::endl; // Expected: "Eve, bureaucrat grade 49"

		bureaucrat5.demote();				   // Grade should be 50
		std::cout << bureaucrat5 << std::endl; // Expected: "Eve, bureaucrat grade 50"

		// Try invalid promotion and demotion
		Bureaucrat bureaucrat6("Frank", 1);
		bureaucrat6.promote(); // Should throw GradeTooHighException
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl; // Expected: "Error: Grade too high"
	}

	try
	{
		Bureaucrat bureaucrat7("Grace", 150);
		bureaucrat7.demote(); // Should throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl; // Expected: "Error: Grade too low"
	}

	return 0;
}
