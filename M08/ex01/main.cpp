#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		Span sp = Span(100000);
		for (int i = 0; i < 100000; ++ i)
			sp.addNumber(rand());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
