#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Form validForm("Tax Return", 10, 20);
	std::cout << "Created form: " << validForm << std::endl;

	try
	{
		Form invalidForm1("Invalid1", 0, 10);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form invalidForm2("Invalid2", 151, 10);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	Form contract("Employment Contract", 30, 40);
	std::cout << "Before signing: " << contract << std::endl;

	Bureaucrat manager("Manager", 25);
	contract.beSigned(manager);
	std::cout << "After signing: " << contract << std::endl;

	contract.beSigned(manager);

	Bureaucrat intern("Intern", 100);
	Form topSecret("Top Secret File", 50, 10);
	try
	{
		topSecret.beSigned(intern);
	}
	catch (const std::exception &e)
	{
		std::cerr << intern.getName() << " couldn't sign " << topSecret.getName() << " because " << e.what() << std::endl;
	}

	std::cout << topSecret << std::endl;

	return 0;
}
