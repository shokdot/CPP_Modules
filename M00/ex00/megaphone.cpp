#include <iostream>

void megaphone(char *line)
{
	int i = 0;
	while (line[i])
	{
		if (line[i] >= 'a' && line[i] <= 'z')
			line[i] -= 32;
		++i;
	}
	std::cout << line;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	}
	else
	{
		int i = 1;
		while (argv[i])
		{
			megaphone(argv[i]);
			++i;
		}
		std::cout << "\n";
	}
	return (0);
}
