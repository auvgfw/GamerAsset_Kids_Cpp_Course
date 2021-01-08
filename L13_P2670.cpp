// luogu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int n, m;
	char puzzle[101][101];
	char answer[101][101];
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> puzzle[i][j];
		}
	}
	int mine;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			mine = 0;
			if (puzzle[i][j] == '*')
			{
				answer[i][j] = '*';
			}
			if (puzzle[i][j] == '?')
			{
				if (i - 1 >= 0 && j - 1 >= 0)
				{
					if (puzzle[i - 1][j - 1] == '*')
					{
						mine++;
					}
				}
				if (j - 1 >= 0)
				{
					if (puzzle[i][j - 1] == '*')
					{
						mine++;
					}
				}
				if (j - 1 >= 0)
				{
					if (puzzle[i + 1][j - 1] == '*')
					{
						mine++;
					}
				}
				if (i - 1 >= 0)
				{
					if (puzzle[i - 1][j] == '*')
					{
						mine++;
					}
				}
				if (puzzle[i + 1][j] == '*')
				{
					mine++;
				}
				if (i - 1 >= 0)
				{
					if (puzzle[i - 1][j + 1] == '*')
					{
						mine++;
					}
				}
				if (puzzle[i][j + 1] == '*')
				{
					mine++;
				}

				if (puzzle[i + 1][j + 1] == '*')
				{
					mine++;
				}
				answer[i][j] = mine + 48;


			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << answer[i][j];
		}
		cout << endl;
	}




}


