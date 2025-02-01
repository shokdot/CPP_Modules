#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal();

	void setType(const std::string &type);
	std::string getType(void) const;

	virtual void makeSound() const;
};
