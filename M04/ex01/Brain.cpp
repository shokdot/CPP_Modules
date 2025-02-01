#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
	return *this;
}

void Brain::setIdea(const std::string &idea, const int id)
{
	this->ideas[id] = idea;
}

std::string Brain::getIdea(const int id)
{
	return this->ideas[id];
}
