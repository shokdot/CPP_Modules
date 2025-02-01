#include "Contact.hpp"

Contact::Contact()
{
	setFirstName("");
	setLastName("");
	setNickName("");
	setPhoneNumber("");
	setDarkestSecret("");
}

Contact::~Contact()
{
}

std::string Contact::getFirstName(void)
{
	return (_firstname);
}

std::string Contact::getLastName(void)
{
	return (_lastname);
}
std::string Contact::getNickName(void)
{
	return (_nickname);
}
std::string Contact::getPhoneNumber(void)
{
	return (_phonenumber);
}
std::string Contact::getDarkestSecret(void)
{
	return (_darkestsecret);
}

void Contact::setFirstName(const std::string &str)
{
	this->_firstname = str;
}
void Contact::setLastName(const std::string &str)
{
	this->_lastname = str;
}
void Contact::setNickName(const std::string &str)
{
	this->_nickname = str;
}
void Contact::setPhoneNumber(const std::string &str)
{
	this->_phonenumber = str;
}
void Contact::setDarkestSecret(const std::string &str)
{
	this->_darkestsecret = str;
}
