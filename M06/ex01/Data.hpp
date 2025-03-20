#pragma once
class Data
{
public:
	Data();
	Data(const int x);
	Data(const Data &other);
	Data &operator=(const Data &rhs);
	~Data();

	int x;
};
