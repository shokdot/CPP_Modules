#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_data(NULL), m_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : m_size(n) { m_data = new T[m_size]; }

template <typename T>
Array<T>::Array(const Array<T> &other) : m_data(NULL), m_size(0) { *this = other; }

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		if (this->m_data)
			delete[] this->m_data;
		this->m_size = rhs.m_size;
		this->m_data = new T[this->m_size];
		for (unsigned int i = 0; i < this->m_size; ++i)
			this->m_data[i] = rhs.m_data[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](const unsigned int n)
{
	if (n >= m_size)
		throw std::out_of_range("Out of range");
	return this->m_data[n];
}

template <typename T>
const T &Array<T>::operator[](const unsigned int n) const
{
	if (n >= m_size)
		throw std::out_of_range("Out of range");
	return this->m_data[n];
}

template <typename T>
unsigned int Array<T>::size(void) const { return m_size; }

template <typename T>
Array<T>::~Array()
{
	if (m_data)
		delete[] m_data;
}
