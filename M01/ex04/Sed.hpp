#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Sed
{
private:
	std::ifstream &infile;
	std::ofstream &outfile;

public:
	Sed(std::ifstream &infile, std::ofstream &outfile);
	void replace(const std::string &to_replace, const std::string &be_replace);
	~Sed();
};
