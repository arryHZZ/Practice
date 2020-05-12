#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define MIN(W,H) min(W/H, H/W)

using namespace std;

void sort(vector<vector <int>>& box, int flog)
{
	for (int i = 0; i < box.size() - 1; i++)
	{
		for (int j = i + 1; j < box.size() - i; j++)
		{
			if (box[j - 1][flog] < box[j][flog])
			{
				swap(box[j - 1], box[j]);
			}
		}
	}
}

void sort1(vector<vector <int>>& box, int flog)
{
	for (int i = 0; i < box.size() - 1; i++)
	{
		for (int j = i + 1; j < box.size() - i; j++)
		{
			if (box[j - 1][flog] > box[j][flog])
			{
				swap(box[j - 1], box[j]);
			}
		}
	}
}

void Print(vector<vector <int>>& box)
{
	for (int i = 0; i < box.size(); i++)
	{
		cout << box[i][0] << " " << box[i][1] << " ";
	}
	cout << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<vector <int>> box;
		box.resize(n);
		for (auto& e : box)
		{
			e.resize(4);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> box[i][j];
			}
			box[i][2] = box[i][0] * box[i][1];
			box[i][3] = MIN(box[i][0], box[i][1]);
		}
		sort1(box, 1);
		sort(box, 3);
		sort1(box, 2);
		Print(box);
	}
	return 0;
}