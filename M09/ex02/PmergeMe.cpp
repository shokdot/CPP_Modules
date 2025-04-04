#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> &input) : size(input.size()), m_vec(input), m_deq(input.begin(), input.end())
{
	std::clock_t start = std::clock();
	this->sort(this->m_vec, 0, this->m_vec.size() - 1);
	std::clock_t end = std::clock();
	double vec_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	start = std::clock();
	this->sort(this->m_deq, 0, this->m_deq.size() - 1);
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
void PmergeMe::merge(Container &DS, int left, int mid, int right)
{
	Container temp(DS.size());
	std::merge(DS.begin() + left, DS.begin() + mid + 1, DS.begin() + mid + 1, DS.begin() + right + 1, temp.begin());
	std::copy(temp.begin(), temp.begin() + (right - left + 1), DS.begin() + left);
}

template <typename Container>
void PmergeMe::sort(Container &DS, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		sort(DS, left, mid);
		sort(DS, mid + 1, right);
		merge(DS, left, mid, right);
	}
}

PmergeMe::~PmergeMe() {}
