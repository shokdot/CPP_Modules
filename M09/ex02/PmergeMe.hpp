#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>

class PmergeMe
{
private:
	PmergeMe();
	template <typename Container>
	void merge(Container &DS, int left, int mid, int right);
	template <typename Container>
	void sort(Container &DS, int left, int right);

public:
	PmergeMe(std::vector<int> &input);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

private:
	int size;
	std::vector<int> m_vec;
	std::deque<int> m_deq;
};
