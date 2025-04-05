#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>
#include <cstdlib>

class Span
{
private:
	unsigned int N;
	std::vector<int> arr;

public:
	Span();
	Span(const unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &rhs);
	~Span();

	void addNumber(int number);
	int shortestSpan(void) const;
	int longestSpan(void) const;
};
