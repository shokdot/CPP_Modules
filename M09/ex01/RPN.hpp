#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <climits>

class RPN
{
private:
	static std::stack<int> st;

	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

public:
	static void evaluate(const std::string &expr);
};
