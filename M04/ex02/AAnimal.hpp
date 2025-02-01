#pragma once
#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &rhs);
	virtual ~AAnimal();

	void setType(const std::string &type);
	std::string getType(void) const;

	virtual void makeSound() const = 0;
};
