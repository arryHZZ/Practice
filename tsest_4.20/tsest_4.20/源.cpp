#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int free = 0;
		string active;
		string a;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			cin >> active;
			if (active == "connect")
			{
				if (free == 0)
				{
					count++;
				}
				else
				{
					free--;
				}
			}
			else if (active == "disconnect")
			{
				free++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
