#include "Serializer.hpp"

int main()
{
	Data *ptr = new Data;
	try
	{
		uintptr_t num = Serializer::serialize(ptr);

		Data *new_ptr = Serializer::deserialize(num);

		std::cout << "Ptr == " << ptr << std::endl;
		std::cout << "New Ptr == " << new_ptr << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		delete ptr;
		return 1;
	}
	delete ptr;
	return 0;
}
