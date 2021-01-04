#include <iostream>
#include <iomanip>
#include <cstring>
#define maxn 20
using namespace std;

int a[maxn][maxn];

int main()
{
    int n, x, y, tot = 0;
    cin >> n;
    memset(a, 0, sizeof(a)); //二维矩阵也可以这样初始化
    tot = a[x = 0][y = n - 1] = 1;
    while (tot < n * n)
    {
        while (x + 1 < n && !a[x + 1][y])
        {
            a[++x][y] = ++tot;
        }
        while (y - 1 >= 0 && !a[x][y - 1])
        {
            a[x][--y] = ++tot;
        }
        while (x - 1 >= 0 && !a[x - 1][y])
        {
            a[--x][y] = ++tot;
        }
        while (y + 1 < n && !a[x][y + 1])
        {
            a[x][++y] = ++tot;
        }
    }

    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            cout << setw(3) << a[x][y];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}