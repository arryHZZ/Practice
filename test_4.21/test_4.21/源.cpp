#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void move(int x, int y, int& count, vector<string> house, vector<vector<int>> flog )
{
	if (x >= house.size() ||  y >= house[0].size() || x < 0 ||y < 0)
		return;
	if (flog[x][y] == 0 && (house[x][y] == '@' || house[x][y] == '.'))
	{
		count++;
		flog[x][y] = 1;
		move(x - 1, y, count, house, flog);
		move(x + 1, y, count, house, flog);
		move(x, y - 1, count, house, flog);
		move(x, y + 1, count, house, flog);
	}
	else
	{
		return;
	}
}

int main()
{
	int m, n;
	while (cin >> m >>n)
	{
		int x, y;
		vector<vector<int>> flog;
		flog.resize(m);
		for (auto& f : flog)
		{
			f.resize(n);
		}
		vector<string> house;
		house.resize(m);
		for (auto& ho : house)
		{
			cin >> ho;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (house[i][j] == '@')
				{
					x = i;
					y = j;
					break;
				}
			}
		}
		int count = 0;
		move(x, y, count, house, flog);
		cout << count << endl;
	}

	return 0;
}