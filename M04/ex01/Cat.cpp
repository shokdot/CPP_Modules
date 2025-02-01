#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
	this->type = other.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain;
	*(this->brain) = *(other.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Operator Assignment Cat called." << std::endl;
	if (this == &rhs)
		return (*this);
	if (this->brain)
		delete this->brain;
	this->brain = new Brain;
	*(this->brain) = *(rhs.brain);
	this->type = rhs.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Mow Mow Mow!" << std::endl;
}
