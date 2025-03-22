#pragma once
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *m_data;
	unsigned int m_size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array<T> &other);
	Array<T> &operator=(const Array &rhs);
	const T &operator[](const unsigned int n) const;
	T &operator[](const unsigned int);
	unsigned int size(void) const;
	~Array();
};

#include "Array.tpp"
