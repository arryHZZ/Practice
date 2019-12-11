#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len) {
	int i = 0;
	int j = 1;
	while (i<len && j < len)
	{
		while (i < len)
		{
			if (arr[i] % 2 == 0)
				i += 2;
			else
				break;
		}
		while (j < len )
		{
			if (arr[j] % 2 == 1)
				j += 2;
			else
				break;
		}
		if (j < len && i < len)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
}
int main()
{
	vector<int> arr;
	//int arr[] = { 1,0,1,2,1,1,1,1,1,1,1};
	arr.resize(3);
	for (auto& e : arr)
	{
		cin >> e;
	}
	oddInOddEvenInEven(arr, arr.size());
	return	0;
}