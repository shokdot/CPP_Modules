#pragma once
#include <iostream>
#include <string>

class Brain
{
public:
	std::string ideas[100];

	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &rhs);
	~Brain();

	void setIdea(const std::string &idea, const int id);
	std::string getIdea(const int id);
};
