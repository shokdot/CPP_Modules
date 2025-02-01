#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int t_main()
{
	const WrongAnimal *wrng = new WrongCat();
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrng->getType() << " " << std::endl;
	wrng->makeSound();
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete wrng;
	delete j;
	delete i;
	delete meta;
	return 0;
}

int main()
{
	t_main();
	// system("leaks Animal");
}
