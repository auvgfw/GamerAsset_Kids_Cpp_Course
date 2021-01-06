#include <iostream>
using namespace std;
int DrawSquare(char x, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        cout << x;
    }
    cout << endl;
    for (i = 1; i <= n - 2; i++)
    {
        cout << x;
        for (int j = 1; j <= n - 2; j++)
        {
            cout << " ";
        }
        cout << x;
        cout << endl;
    }

    for (i = 1; i <= n; i++)
    {
        cout << x;
    }
    return 0;
}
int main()
{
    DrawSquare('c', 5);
}
