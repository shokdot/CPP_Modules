#pragma once
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &container, const int find)
{
	return std::find(container.cbegin(), container.cend(), find);
}
