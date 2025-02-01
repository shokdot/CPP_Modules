#pragma once
#include "AAnimal.hpp"

class Cat : public AAnimal
{
private:
	Brain *brain;

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);
	~Cat();

	void makeSound() const;
};
