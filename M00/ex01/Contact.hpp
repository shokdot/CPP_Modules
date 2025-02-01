#pragma once

#include <string>
#include <iostream>

class Contact
{
private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestsecret;

public:
	Contact();
	~Contact();
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickName(void);
	std::string getPhoneNumber(void);
	std::string getDarkestSecret(void);

	void setFirstName(const std::string &str);
	void setLastName(const std::string &str);
	void setNickName(const std::string &str);
	void setPhoneNumber(const std::string &str);
	void setDarkestSecret(const std::string &str);
};
