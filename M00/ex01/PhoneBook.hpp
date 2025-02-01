#pragma once

#include "Contact.hpp"
#define Contact_size 8

class PhoneBook
{
private:
	int m_index;
	int m_size;
	Contact contacts[Contact_size];
	std::string string_rep(std::string src);

public:
	PhoneBook();
	~PhoneBook();
	void addContact(std::string data[5]);
	void searchContact(int index);
	void displayPhoneBook();
};
