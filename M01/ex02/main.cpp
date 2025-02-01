#include <string>
#include <iostream>

int main()
{
	std::string a = "HI THIS IS BRAIN";
	std::string *stringPTR = &a;
	std::string& stringREF = a;

	std::cout << "-----------------------------\n";

	std::cout << "address of the string variable " << &a << "\n";
	std::cout << "address held by stringPTR " << stringPTR << "\n";
	std::cout << "address held by stringREF " << &stringREF << "\n";

	std::cout << "-----------------------------\n";

	std::cout << "value of the string variable " << a << "\n";
	std::cout << "value pointed to by stringPTR " << *stringPTR << "\n";
	std::cout << "value pointed to by stringREF " << &stringREF << "\n";

}
