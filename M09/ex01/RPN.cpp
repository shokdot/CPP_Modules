#include "RPN.hpp"

std::stack<int> RPN::st;

void RPN::evaluate(const std::string &expr)
{
	std::istringstream ss(expr);
	std::string token;
	while (ss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			st.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (st.size() < 2)
			{
				throw std::runtime_error("Error");
			}
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			if (token == "+")
				st.push(a + b);
			else if (token == "-")
				st.push(a - b);
			else if (token == "*")
				st.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error: Division by Zero.");
				st.push(a / b);
			}
		}
		else
			throw std::runtime_error("Invalid RPN expression");
	}
	std::cout << st.top() << std::endl;
}
