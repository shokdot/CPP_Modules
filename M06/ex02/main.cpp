#include "Base.hpp"

Base *generate(void)
{
	int variant = (rand() % 3) + 1;
	switch (variant)
	{
	case (1):
		return new A();
		break;
	case (2):
		return new B();
		break;
	case (3):
		return new B();
		break;
	default:
		break;
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "It's A ptr" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "It's B ptr" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "It's C ptr" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "It's A referance." << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "It's B referance." << std::endl;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "It's C referance." << std::endl;
	}
	catch (...)
	{
	}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base *ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
}
