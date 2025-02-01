#include "Dog.hpp"
#include "Cat.hpp"

int t_main()
{
	Animal **meta = new Animal *[100];
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
	return (0);
}

int main()
{
	t_main();
	// system("leaks Brain");
}
