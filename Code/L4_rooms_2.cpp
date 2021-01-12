#include <iostream>
using namespace std;
int a[101] = {0};
int main()
{
    int i, j, k, n;
    n = 0;
    int a[101];
    for (i = 1; i <= 100; i++)
    {
        a[i] = 1;
    }
    for (j = 2; j <= 100; j++)
    {
        for (i = 1; i <= 100; i++)
        {
            if (i % j == 0)
            {
                if (a[i] == 1)
                {
                    a[i] = 0;
                }
                else
                {
                    a[i] = 1;
                }
            }
        }
    }
    for (i = 1; i <= 100; i++)
    {
        if (a[i] == 1)
        {
            n++;
        }
    }
    cout<<n;
    system("pause");
}