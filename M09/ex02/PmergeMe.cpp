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
void PmergeMe::insertionSort(Container &DS)
{
	for (size_t i = 1; i < DS.size(); i++)
	{
		int tmp = DS[i];
		int j = i - 1;
		while (j >= 0 && DS[j] > tmp)
		{
			DS[j + 1] = DS[j];
			j--;
		}
		DS[j + 1] = tmp;
	}
}

template <typename Container>
void PmergeMe::sort(Container &DS)
{
	if (DS.size() <= 32)
		return insertionSort(DS);
	Container left(DS.begin(), DS.begin() + DS.size() / 2);
	Container right(DS.begin() + DS.size() / 2, DS.end());
	sort(left);
	sort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), DS.begin());
}

PmergeMe::~PmergeMe() {}
