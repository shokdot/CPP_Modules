#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();

	void setType(const std::string &type);
	std::string getType(void) const;

	void makeSound() const;
};
