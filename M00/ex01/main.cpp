#include "PhoneBook.hpp"

bool isValidNumber(std::string &str)
{
	int i = 0;
	if (str.empty())
		return (false);
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void add_contact(PhoneBook &p)
{
	std::string data[5];
	std::cout << "Adding Contact to Phonebook" << std::endl;
	std::cout << "Enter Fist Name :";
	std::getline(std::cin, data[0]);
	std::cout << "Enter Last Name :";
	std::getline(std::cin, data[1]);
	std::cout << "Enter Nick Name :";
	std::getline(std::cin, data[2]);
	do
	{
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, data[3]);
		if (isValidNumber(data[3]))
			break;
		std::cout << "Please input a valid number" << std::endl;
	} while (!isValidNumber(data[3]));
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, data[4]);
	p.addContact(data);
	std::cout << "Contact Added " << std::endl;
}

void search(PhoneBook &p)
{
	int index;
	p.displayPhoneBook();
	std::cout << "Enter Index of Contact :";
	std::cin >> index;
	if (index < 0 || index > 7)
		return;
	p.searchContact(index);
}

int main()
{
	PhoneBook p1;
	std::string input;
	while (true)
	{
		std::cout << "Enter command please\n";
		input.clear();
		getline(std::cin, input, '\n');
		if (input == "ADD")
		{
			add_contact(p1);
			input.clear();
		}
		else if (input == "SEARCH")
		{
			search(p1);
			std::cin.clear();
			std::getline(std::cin, input);
			continue;
		}
		else if (input == "EXIT")
			break;
		else
		{
			input.clear();
			std::cout << "Bad input, your options are ADD, SEARCH or EXIT!" << std::endl;
			continue;
		}
	}
}
