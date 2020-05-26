#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

//计算每小时的营业额
void GetMoney(vector<vector <int>>& arr, vector<int>& money, vector<vector <vector <int>>>& time)
{
	auto begin = arr.begin();
	for (auto ar : arr)
	{
		//秒除以60为分钟再除以60位小时，再加上该时间的营销额
		money[ar[1] / 60 / 60] += ar[2];
		//再将该时间段内发生的交易情况保存到time容器中
		time[ar[1] / 60 / 60].push_back(ar);
	}
	//找出连续两小时营业额最大的时间段，再将其左右各增加一小时，从这四小时中找的黄金2小时
	int Max[2][12] = { 0 };
	int max = 0;
	int flog = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			// 第一行存以0开头的每2小时，第二行存取以1开头的每两小时
			Max[i][j] = money[j + i] + money[(j + i + 1) % 12]; 
			if (Max[i][j] > max)
			{
				max = Max[i][j];
				flog = j + i; // 得到那个小时开始时营业额最大
			}
		}
	}
	//从之前保存的信息中找出该高峰的前一小时，与后一小时的销售情况，算出最大销售额，与起始时间
	set <int> st;
	map <int, int> mp;
	for (int i = flog - 1; i < flog + 3; i++)
	{
		for (int j = 0; j < time[i].size(); j++)
		{
			mp.insert(make_pair(time[i][j][1], time[i][j][2]));
			st.insert(time[i][j][1]);
		}
	}
	int add = 0;
	max = 0;
	//auto mp_begin = mp.begin();
	auto begin_time = st.begin();
	auto now_time = begin_time;
	while (now_time != st.end())
	{
		if (*now_time <= *begin_time + 60 * 60 * 2)
		{
			add += mp[*now_time];
		}
		else
		{
			add -= mp[*begin_time];
			begin_time++;
			continue;
		}
		now_time++;
		if (max < add)
		{
			max = add;
		}
	}

}

int main()
{

	int n;
	while (cin >> n)
	{
		vector<vector <int>> arr; //保存每日数据
		vector<int> money; //保存每小时的营业额
		vector<vector <vector <int>>> time; //保存该小时内的的营业数据
		money.resize(24);
		time.resize(24);
		arr.resize(n);
		for (auto& ar : arr)
		{
			ar.resize(3);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> arr[i][j];
			}
		}
		GetMoney(arr, money, time);
	}


	return 0;
}



/*
64
1 8924 25
1 23860 28
2 1507 19
2 4675 12
2 16096 26
3 2098 25
3 3389 16
3 29309 18
4 27966 15
5 11983 21
5 15966 27
5 20545 22
6 30106 29
6 30345 25
7 14043 28
7 19831 24
7 26007 11
8 2867 23
8 24790 29
9 11038 14
9 12900 12
9 31312 24
10 7808 26
11 6653 27
12 1717 22
12 3224 10
13 14767 25
14 2832 19
14 7304 17
15 9505 18
15 30210 25
15 30560 12
16 1139 21
17 15881 27
18 10401 26
18 10404 26
19 16120 23
20 95 14
20 12362 18
20 29878 28
21 9647 14
21 23625 16
22 42 20
22 12736 26
22 20244 10
23 28391 24
23 29059 20
24 569 24
25 29749 17
25 31544 25
26 22051 21
26 30478 28
27 22746 10
27 28157 10
27 30513 16
28 19401 24
28 20430 18
28 26960 15
29 17300 13
29 24550 11
29 25798 17
30 19155 14
30 21469 21
31 5166 24
*/