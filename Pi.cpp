#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    float s;
    int b, x, n, c, i, j, d, l, a[5000];
    cout << endl
         << "input number" << endl;
    cin >> x;
    clock_t start, finish;
    start = clock();

    for (s = 0, n = 1; n <= 5000; n++) //累加确定项数.
    {
        s = s + log10((2 * n + 1) / n);
        if (s > x + 1)
            break;
    }
    for (i = 0; i <= x + 5; i++)
        a[i] = 0;
    for (c = 1, j = n; j >= 1; j--) //按公式分布计算。
    {
        d = 2 * j + 1;
        for (i = 0; i <= x + 4; i++) //各位实施除2j+1.
        {
            a[i] = c / d;
            c = (c % d) * 10 + a[i + 1];
        }
        a[x + 5] = c / d;
        for (b = 0, i = x + 5; i >= 0; i--) //各位实施乘j
        {
            a[i] = a[i] * j + b;
            b = a[i] / 10;
            a[i] = a[i] % 10;
        }
        a[0] = a[0] + 1;
        c = a[0]; //整数加1.
    }
    for (b = 0, i = x + 5; i >= 0; i--) //按公式各位乘2
    {
        a[i] = a[i] * 2 + b;
        b = a[i] / 10;
        a[i] = a[i] % 10;
    }
    finish = clock();
    cout << endl
         << "PI=" << a[0] << "."; //诸位输出计算结果。
    for (l = 10, i = 1; i <= x; i++)
    {
        cout << a[i];
        l++;
        if (l % 10 == 0)
            cout << "   ";
        if (l % 50 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "time:" << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
    system("pause");
    return 0;
}