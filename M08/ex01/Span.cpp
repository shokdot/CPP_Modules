#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(const unsigned int N) : N(N) {}

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->arr = rhs.arr;
		this->N = rhs.N;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (this->arr.size() == this->N)
		throw std::out_of_range("Out of range");
	arr.push_back(number);
}

int Span::shortestSpan(void) const
{
	std::vector<int> tmp;

	if (arr.size() < 2)
		throw std::out_of_range("Can't be get span");
	std::vector<int> sortedNumbers = arr;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = std::numeric_limits<int>::max();

	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
		{
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan(void) const
{
	if (arr.size() < 2)
		throw std::logic_error("Can't be get span");
	return *std::max_element(arr.begin(), arr.end()) - *std::min_element(arr.begin(), arr.end());
}
