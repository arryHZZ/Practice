#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//int main()
//{
//	string num ;
//	while (cin>>num)
//	{
//		int left = 0;
//		int right = num.size() - 1;
//		while (left < right)
//		{
//			if (num[left] == '2')
//				break;
//			left++;
//		}
//		while (left < right)
//		{
//			if (num[right] == '5')
//				break;
//			right--;
//		}
//		if (right > left)
//			cout << (right - left + 1) << endl;
//		else
//			cout << 0 << endl;
//	}
//	return 0;
//}


//void GetXYZ(string n, vector<vector <float>>& Point)
//{
//	vector<float> point;
//	for (int i = 1; i < n.size(); i++)
//	{
//		string tmp;
//
//		for (i; i < n.size(); i++)
//		{
//			if (n[i] == ',' || n[i] == ')')
//			{
//				i++;
//				break;
//			}
//			tmp += n[i];
//		}
//		point.push_back(stof(tmp));
//		tmp.clear();
//	}
//	Point.push_back(point);
//}
//
//void GetABC(string str, vector<string>& StrPront)
//{
//	auto begin = str.begin();
//	while (begin != str.end())
//	{
//		string tmp;
//		if (*begin == '(')
//		{
//			while (*begin != ')')
//			{
//				tmp += *begin;
//				begin++;
//			}
//			tmp += ')';
//		}
//		StrPront.push_back(tmp);
//		tmp.clear();
//		begin++;
//	}
//}
//
//
//
//bool IsTrue(vector<vector <float>> Pront)
//{
//	int F[3][3] = { 0 };
//	F[0][0] = abs(Pront[0][0] - Pront[1][0]);
//	F[0][1] = abs(Pront[0][1] - Pront[1][1]);
//	F[0][2] = abs(Pront[0][2] - Pront[1][2]);
//	F[1][0] = abs(Pront[1][0] - Pront[2][0]);
//	F[1][1] = abs(Pront[1][1] - Pront[2][1]);
//	F[1][2] = abs(Pront[1][2] - Pront[2][2]);
//	F[2][0] = abs(Pront[2][0] - Pront[0][0]);
//	F[2][1] = abs(Pront[2][1] - Pront[0][1]);
//	F[2][2] = abs(Pront[2][2] - Pront[0][2]);
//	int cout1 = 0;
//	int cout2 = 0;
//	if (F[0][0] / F[1][0] == F[0][1] / F[1][1] && F[0][1] / F[1][1] == F[0][2] / F[1][2] &&
//		F[1][0] / F[2][0] == F[1][1] / F[2][1] && F[1][1] / F[2][1] == F[1][2] / F[2][2] &&
//		F[0][0] / F[2][0] == F[0][1] / F[2][1] && F[0][1] / F[2][1] == F[0][2] / F[2][2])
//		return false;
//	else
//		return true;
//}
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		vector<vector <float>> Pront;
//		vector<string> StrPront;
//		GetABC(str, StrPront);
//		GetXYZ(StrPront[0], Pront);
//		GetXYZ(StrPront[2], Pront);
//		GetXYZ(StrPront[4], Pront);
//		if (IsTrue(Pront))
//		{
//			cout << "true" << endl;
//		}
//		else
//		{
//			cout << "false" << endl;
//		}
//	}
//	return 0;
//}



void GetXYZ(string n, vector<vector <float>>& Point)
{
	vector<float> point;
	for (size_t i = 1; i < n.size(); i++)
	{
		string tmp;

		for (; i < n.size(); i++)
		{
			if (n[i] == ',' || n[i] == ')')
			{
				i++;
				break;
			}
			tmp += n[i];
		}
		point.push_back(stof(tmp));
		tmp.clear();
	}
	Point.push_back(point);
}

void GetABC(string str, vector<string>& StrPront)
{
	auto begin = str.begin();
	while (begin != str.end())
	{
		string tmp;
		if (*begin == '(')
		{
			while (*begin != ')')
			{
				tmp += *begin;
				begin++;
			}
			tmp += ')';
		}
		StrPront.push_back(tmp);
		tmp.clear();
		begin++;
	}
}



bool IsTrue(vector<vector <float>> Pront)
{
	float F[3][3] = { 0 };
	F[0][0] = abs(Pront[0][0] - Pront[1][0]);
	F[0][1] = abs(Pront[0][1] - Pront[1][1]);
	F[0][2] = abs(Pront[0][2] - Pront[1][2]);
	F[1][0] = abs(Pront[1][0] - Pront[2][0]);
	F[1][1] = abs(Pront[1][1] - Pront[2][1]);
	F[1][2] = abs(Pront[1][2] - Pront[2][2]);
	F[2][0] = abs(Pront[2][0] - Pront[0][0]);
	F[2][1] = abs(Pront[2][1] - Pront[0][1]);
	F[2][2] = abs(Pront[2][2] - Pront[0][2]);
	int cout1 = 0;
	int cout2 = 0;
	if (F[0][0] / F[1][0] == F[0][1] / F[1][1] && F[0][1] / F[1][1] == F[0][2] / F[1][2] &&
		F[1][0] / F[2][0] == F[1][1] / F[2][1] && F[1][1] / F[2][1] == F[1][2] / F[2][2] &&
		F[0][0] / F[2][0] == F[0][1] / F[2][1] && F[0][1] / F[2][1] == F[0][2] / F[2][2])
		return false;
	else
		return true;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<vector <float>> Pront;
		vector<string> StrPront;
		GetABC(str, StrPront);
		GetXYZ(StrPront[0], Pront);
		GetXYZ(StrPront[2], Pront);
		GetXYZ(StrPront[4], Pront);
		if (IsTrue(Pront))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	return 0;
}