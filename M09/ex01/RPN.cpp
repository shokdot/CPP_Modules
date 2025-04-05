#include "RPN.hpp"

std::stack<int> RPN::st;

void RPN::evaluate(const std::string &expr)
{
	while (!st.empty())
		st.pop();

	std::istringstream ss(expr);
	std::string token;
	while (ss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			st.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (st.size() < 2)
				throw std::runtime_error("Error: Not enough operands");

			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();

			long long result = 0;

			if (token == "+")
			{
				result = static_cast<long long>(a) + b;
				if (result > INT_MAX || result < INT_MIN)
					throw std::out_of_range("Out of INT range");
			}
			else if (token == "-")
			{
				result = static_cast<long long>(a) - b;
				if (result > INT_MAX || result < INT_MIN)
					throw std::out_of_range("Out of INT range");
			}
			else if (token == "*")
			{
				result = static_cast<long long>(a) * b;
				if (result > INT_MAX || result < INT_MIN)
					throw std::out_of_range("Out of INT range");
			}
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error: Division by zero");
				if (a == INT_MIN && b == -1)
					throw std::out_of_range("Out of INT range");
				result = a / b;
			}

			st.push(static_cast<int>(result));
		}
		else
			throw std::runtime_error("Invalid token in RPN expression");
	}
	if (st.size() != 1)
		throw std::runtime_error("Invalide RPN expression");

	std::cout << st.top() << std::endl;
}

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN &RPN::operator=(const RPN &) { return *this;}

RPN::~RPN() {}