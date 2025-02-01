#pragma once
#include "AAnimal.hpp"

class Dog : public AAnimal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	~Dog();

	void makeSound() const;
};
