#include <iostream>
using namespace std;
const int n = 6;
int a[7][7];
int main()
{
    for (int i = 1; i <= 6; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 6; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            if ((i == j) || (i + j == 7)) //对角线判定条件
            {
                a[i][j] += 10;
            }
        }
    }
    for (int i = 1; i <= 6; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}