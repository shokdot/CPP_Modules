#include "Data.hpp"

Data::Data() : x(0) {}

Data::Data(const int x) : x(x) {}

Data::Data(const Data &other) { *this = other; }

Data &Data::operator=(const Data &rhs)
{
	this->x = rhs.x;
	return *this;
}

Data::~Data() {}
