#pragma once
#include <string>
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(const std::string& type);
	std::string getType(void) const;
	void setType(std::string type);
};
