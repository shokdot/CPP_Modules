#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &fname)
{
	this->parseCSV(fname);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseCSV(const std::string &fname)
{
	std::ifstream dict(fname);
	if (!dict.is_open() || dict.eof())
		throw std::runtime_error("Couldn't open CSV file.");
	std::string line;
	std::getline(dict, line);
	while (std::getline(dict, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw std::runtime_error("Invalid CSV file.");
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1);
		this->data.insert(std::make_pair(date, std::atof(value.c_str())));
	}
}

std::string BitcoinExchange::trimLine(const std::string &line)
{
	size_t start = line.find_first_not_of(" \r\t");
	size_t end = line.find_last_not_of(" \r\t");
	if (start == std::string::npos || end == std::string::npos)
		return line;
	return line.substr(start, end - start + 1);
}

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	int year, month, day;
	char dash1, dash2;

	if (date.size() != 10)
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;
		}
		else if (!std::isdigit(date[i]))
			return false;
	}
	std::istringstream ss(date);
	ss >> year >> dash1 >> month >> dash2 >> day;
	if (ss.fail() || !ss.eof())
		return false;
	else if (month < 1 || month > 12 || day < 1 || year == 0)
		return false;
	switch (month)
	{
	case 2:
		return (day <= (isLeapYear(year) ? 29 : 28));
	case 4:
	case 6:
	case 9:
	case 11:
		return (day <= 30);
	default:
		return (day <= 31);
	}
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
	double num;
	std::stringstream ss(value);
	ss >> num;
	if (ss.fail() || !ss.eof())
	{
		std::cout << "Error: bad input" << std::endl;
		return false;
	}
	else if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (num > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::exchange(const std::string &fname)
{
	std::ifstream infile(fname);
	if (!infile.is_open() || infile.eof())
		throw std::runtime_error("Couldn't open input file.");
	std::string header;
	std::getline(infile, header);
	if (header != "date | value")
		throw std::runtime_error("Invalid input file.");
	std::string line;
	while (std::getline(infile, line))
	{
		if (line.empty())
			continue;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trimLine(line.substr(0, pos));
		std::string value = trimLine(line.substr(pos + 1));
		if (!isValidDate(date))
		{
			std::cout << "Error: invalid date format => " << date << std::endl;
			continue;
		}
		else if (!isValidValue(value))
			continue;
		else
		{
			double price = std::atof(value.c_str());
			std::map<std::string, double>::const_iterator it = this->data.lower_bound(date);
			if (it == this->data.end())
				--it;
			else if (it != this->data.begin() && it->first != date)
			{
				std::map<std::string, double>::const_iterator prevIt = it;
				--prevIt;
				--it;
				if ((date.compare(it->first) - date.compare(prevIt->first)) > 0)
					it = prevIt;
			}
			std::cout << date << " => " << price << " = " << price * it->second << std::endl;
		}
	}
}
