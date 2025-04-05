#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	AAnimal **meta = new AAnimal *[100];
	for (int i = 0; i < 50; i++)
		meta[i] = new Cat();
	for (int i = 50; i < 100; i++)
		meta[i] = new Dog();
	for (int i = 0; i < 100; i++)
	{
		meta[i]->makeSound();
		delete meta[i];
	}
	delete[] meta;
}