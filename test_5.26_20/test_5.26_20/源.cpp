#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int once(vector<int> arr)
{
	int u1 = arr[0];
	int u2 = arr[1];
	int h = arr[2];
	int tmp = h;
	int count = 0;
	while (u1 > 0 || u2 > 0)
	{
		tmp = h;
		while (u2 > 0 && tmp >= 2)
		{
			u2--;
			tmp -= 2;
		}
		while (u1 > 0 && tmp >= 1)
		{
			u1--;
			tmp -= 1;
		}
		count++;
	}
	return count;
}

int main()
{
	vector<vector <int>> arr;
	int n;
	while (cin >> n)
	{
		arr.resize(n);
		for (auto& ar : arr)
		{
			ar.resize(3);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <3; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (auto& e : arr)
		{
			cout << once(e) << endl;
		}
	}
	return 0;
}