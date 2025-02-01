#include "Sed.hpp"

Sed::Sed(std::ifstream &infile, std::ofstream &outfile) : infile(infile), outfile(outfile)
{
}

void Sed::replace(const std::string &to_replace, const std::string &be_replace)
{
	while (!infile.eof())
	{
		std::string tmp;
		std::getline(infile, tmp);
		std::string::size_type f = 0;
		std::string::size_type s = tmp.find(to_replace, f);
		std::string res;
		if (!to_replace.empty())
		{
			while (s != std::string::npos)
			{
				res += std::string(tmp, f, s - f);
				res += be_replace;
				f = s + to_replace.length();
				s = tmp.find(to_replace, f);
				if (s == std::string::npos)
					res += std::string(tmp, f);
			}
		}
		if (res.empty())
			res = tmp;
		outfile << res << ((infile.eof()) ? "" : "\n");
	}
}
Sed::~Sed()
{
}
