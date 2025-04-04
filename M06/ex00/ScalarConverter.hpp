#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
public:
	static void convert(const std::string &str);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();
	static void printNan(void);
	static void printinf(const std::string &val);
	static void printChar(const std::string &val);
	static void printInt(const std::string &str);
	static void printFloat(const std::string &str);
	static void printDouble(const std::string &str);
	static void printError(void);
	static bool checkInf(const std::string &val);
	static bool checkNum(const std::string &val);
};
