#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}
Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain;
	*(this->brain) = *(other.brain);
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}
Dog &Dog::operator=(const Dog &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain;
	*(this->brain) = *(rhs.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark Bark!" << std::endl;
}
