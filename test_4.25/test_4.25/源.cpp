#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

void once(string& number, string::iterator Begin)
{
	string tmp(number);
	auto begin = Begin;
	auto slow = tmp.begin()+ (begin - number.begin());
	while (begin != number.end())
	{
		if ((*begin - '0') % 2 == 0)
		{
			*begin = *slow;
			slow = tmp.begin() + (begin - number.begin());
		}
		begin++;
	}
	if (slow != tmp.end())
		*Begin = *slow;
}

string change(string number) {
	auto begin = number.begin();
	while (begin != number.end())
	{
		if ((*begin - '0') % 2 == 0)
		{
			once(number, begin);
		}
		begin++;
	}
	return number;
}

int main()
{
	string str = "1675283134";
	//once(str, ++str.begin());
	//cout << str << endl;
	cout << change(str) << endl;
	return 0;
}