#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int n, m;
	int inout[100000];
	string name[100000];
	int leftright[100000];
	int number[100000];
	cin >> n >> m;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> inout[i];
		cin >> name[i];
	}
	for (i = 0; i < m; i++)
	{
		cin >> leftright[i];
		cin >> number[i];
	}
	long count;
	count = 0;
	for (i = 0; i < m; i++)
	{
		if (inout[count] == leftright[i])
		{
			//顺时针数
			count = count+n - number[i];
			count = count % n;

		}
		else
		{
			//逆时针数
			count = count + number[i];
			count = count % n;
		}
	}
	cout << name[count];



}