#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printNan(void)
{

	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	std::cout << "Float: " << "nanf" << std::endl;
	std::cout << "Double: " << "nan" << std::endl;
}

bool ScalarConverter::checkInf(const std::string &val)
{
	return (val == "inf" || val == "+inf" || val == "inff" || val == "+inff" || val == "-inf" || val == "-inff");
}

void ScalarConverter::printinf(const std::string &val)
{
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	std::cout << "Float: " << (val[0] == '-' ? "-" : "+") << "inff" << std::endl;
	std::cout << "Double: " << (val[0] == '-' ? "-" : "+") << "inf" << std::endl;
}

void ScalarConverter::printChar(const std::string &str)
{
	char res = static_cast<char>(std::atoi(str.c_str()));
	std::cout << "Char: ";
	if (res < 0)
		std::cout
			<< "impossible" << std::endl;
	else if (res < 32 || res == 127)
		std::cout
			<< "Non displayable" << std::endl;
	else
		std::cout << "\'" << res << "\'" << std::endl;
}

void ScalarConverter::printInt(const std::string &str)
{
	std::cout << "Int: " << std::atoi(str.c_str()) << std::endl;
}

bool ScalarConverter::checkNum(const std::string &str)
{
	size_t i = 0;
	if (str.empty())
		return false;

	if (str[i] == '+' || str[i] == '-')
		++i;

	size_t len = str.length();
	int dotCount = 0;

	if (!std::isdigit(str[len - 1]) && str[len - 1] != 'f')
		return false;
	if (str[len - 1] == 'f')
		--len;

	for (; i < len; ++i)
	{
		if (str[i] == '.')
		{
			++dotCount;
			if (dotCount > 1)
				return false;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void ScalarConverter::printError(void)
{
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	std::cout << "Float: " << "impossible" << std::endl;
	std::cout << "Double: " << "impossible" << std::endl;
}

void ScalarConverter::printFloat(const std::string &str)
{
	float res = std::strtof(str.c_str(), NULL);
	std::cout << "Float: " << res;
	if (res == static_cast<int>(res))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(const std::string &str)
{
	double res = std::strtod(str.c_str(), NULL);
	std::cout << "Double: " << res;
	if (res == static_cast<int>(res))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	if (str == "nan" || str == "nanf")
		printNan();
	else if (checkInf(str))
		printinf(str);
	else if (checkNum(str))
	{
		printChar(str);
		printInt(str);
		printFloat(str);
		printDouble(str);
	}
	else
		printError();
}
