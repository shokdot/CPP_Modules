#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void testFind(T &container, int value)
{
	typename T::iterator it = easyfind(container, value);
	if (it != container.end())
		std::cout << "Found: " << *it << " in container" << std::endl;
	else
		std::cout << "Value " << value << " not found in container" << std::endl;
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr1, arr1 + 5);

	int arr2[] = {10, 20, 30, 40, 50};
	std::list<int> lst(arr2, arr2 + 5);

	int arr3[] = {100, 200, 300, 400, 500};
	std::deque<int> deq(arr3, arr3 + 5);

	testFind(vec, 3);
	testFind(vec, 6); // Not found
	testFind(lst, 20);
	testFind(lst, 25); // Not found
	testFind(deq, 400);
	testFind(deq, 600); // Not found

	return 0;
}
