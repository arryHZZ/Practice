#define _CRT_SECURE_NO_WARNINGS
// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> team;
		vector<int> flog;
		team.resize(n);
		flog.resize(n);
		for (auto &e : team)
		{
			cin >> e;
		}
		flog[0] = 1;
		int max = 1;
		for (int i = 1; i < n; i++)
		{
			int j;
			int tall = 1;
			for (j = i - 1; j >= 0; --j)
			{
				if (team[i] > team[j])
				{
					if (tall < flog[j])
					{
						tall = flog[j];
					}
				}
			}
			flog[i] = tall + 1;
			if (flog[i] > max)
			{
				max = flog[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}