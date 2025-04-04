#pragma once
#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double> data;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void parseCSV(const std::string &fname);
	std::string trimLine(const std::string &line);
	bool isValidDate(const std::string &date);
	bool isValidValue(const std::string &value);
	bool isLeapYear(int year);

public:
	BitcoinExchange(const std::string &fname);
	void exchange(const std::string &fname);
	~BitcoinExchange();
};
