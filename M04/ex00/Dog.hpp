#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	~Dog();

	void makeSound() const;
};
