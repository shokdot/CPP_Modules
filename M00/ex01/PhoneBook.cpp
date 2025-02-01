#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->m_index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(std::string data[5])
{
	int index = this->m_index;
	this->contacts[index].setFirstName(data[0]);
	this->contacts[index].setLastName(data[1]);
	this->contacts[index].setNickName(data[2]);
	this->contacts[index].setPhoneNumber(data[3]);
	this->contacts[index].setDarkestSecret(data[4]);
	this->m_index = (m_index + 1) % 8;

	if (m_size < 8)
		m_size++;
}

std::string PhoneBook::string_rep(std::string src)
{
	std::string res = src;
	if (res.length() > 10)
		res.replace(res.begin() + 9, res.end(), ".");
	if (res.length() == 10)
		return res;
	res.append(10 - res.length(), ' ');
	return res;
}

void PhoneBook::displayPhoneBook()
{
	int i = 0;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (i < this->m_size)
	{
		std::cout << "|         " << i;
		std::cout << "|";
		std::cout << string_rep(this->contacts[i].getFirstName());
		std::cout << "|";
		std::cout << string_rep(this->contacts[i].getLastName());
		std::cout << "|";
		std::cout << string_rep(this->contacts[i].getNickName());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void PhoneBook::searchContact(int index)
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|        Contact information of index       |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;

	std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickName() << std::endl;
	std::cout << "Number: " << this->contacts[index].getPhoneNumber() << std::endl;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
}
