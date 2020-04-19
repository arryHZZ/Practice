#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SetName(string str, vector<string>& namelist)
{
	auto begin = str.begin();
	int flog = -1;
	string tmp;
	while (begin != str.end())
	{
		if (*begin == '"')
		{
			begin++;
			flog *= -1;
			continue;
		}

		if (*begin == ',' && flog == -1)
		{
			namelist.push_back(tmp);
			begin++;
			tmp.clear();
			continue;
		}
		tmp += *begin++;
	}
	namelist.push_back(tmp);
}

void Send(vector<string> namelist, string name)
{
	for (auto na : namelist)
	{
		if (na == name)
		{
			cout << "Ignore" << endl;
			return;
		}
	}
	cout << "Important!" << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		string name;
		//getchar();
		getline(cin, name);
		vector<string> namelist;
		SetName(str, namelist);
		Send(namelist, name);
	}
	return 0;
}