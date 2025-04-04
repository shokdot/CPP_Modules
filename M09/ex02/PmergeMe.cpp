#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> &input) : size(input.size()), m_vec(input), m_deq(input.begin(), input.end())
{
	std::clock_t start = std::clock();
	this->sort(this->m_vec);
	std::clock_t end = std::clock();
	double vec_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	start = std::clock();
	this->sort(this->m_deq);
	end = std::clock();
	double deq_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	for (size_t i = 0; i < m_vec.size(); i++)
		std::cout << " " << m_vec[i];
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->size << " elements with std::vector<int> : " << vec_time * 1000000 << " us" << std::endl;
	std::cout << "Time to process a range of " << this->size << " elements with std::deque<int> : " << deq_time * 1000000 << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (&rhs != this)
	{
		this->m_deq = rhs.m_deq;
		this->m_vec = rhs.m_vec;
		this->size = rhs.size;
	}
	return *this;
}

template <typename Container>
void PmergeMe::sort(Container &DS)
{
	if (DS.size() <= 1)
		return;
	Container winners, losers;

	for (size_t i = 0; i + 1 < DS.size(); i += 2)
	{
		if (DS[i] < DS[i + 1])
		{
			winners.push_back(DS[i + 1]);
			losers.push_back(DS[i]);
		}
		else
		{
			winners.push_back(DS[i]);
			losers.push_back(DS[i + 1]);
		}
	}
	bool hasOdd = DS.size() % 2 != 0;
	int oddElem;
	if (hasOdd)
		oddElem = DS.back();

	sort(winners);

	for (size_t i = 0; i < losers.size(); i++)
	{
		typename Container::iterator pos = std::lower_bound(winners.begin(), winners.end(), DS[i]);
		winners.insert(pos, DS[i]);
	}
	if (hasOdd)
	{
		typename Container::iterator pos = std::lower_bound(winners.begin(), winners.end(), oddElem);
		winners.insert(pos, oddElem);
	}

	DS = winners;
}

PmergeMe::~PmergeMe() {}
