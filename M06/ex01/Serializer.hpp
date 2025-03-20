#pragma once
#include "Data.hpp"
#include <inttypes.h>
#include <iostream>

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &rhs);
	~Serializer();
};
