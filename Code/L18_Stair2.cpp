#include <iostream>
using namespace std;
int Stairs(int n)
{
    if (n < 1)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return Stairs(n - 1) + Stairs(n - 2);
}
int main()
{
    int n;
    int x, y;

    cin >> n;
    cin >> x >> y;
    cout << Stairs(n) << endl;
    n--;
    x--;
    y--;
    
    //动归
    int f[100];
    int i;
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (i = 3; i <= n; i++)
    {
        if (i == x || i == y)
        {
            f[i] = 0;
        }
        else
        {
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    cout << f[n];
}