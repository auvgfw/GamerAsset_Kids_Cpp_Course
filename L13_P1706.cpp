#include <iostream>
#include <cmath>
using namespace std;
//判断是否存在重复数字
bool IdenticalandZeroJudge(int x);
int n;
int main()
{

    int min, max;
    cin >> n;
    int i;
    max = ceil(pow(10, n)) - 1;
    min = ceil(pow(10, n - 1));
    for (i = min; i <= max; i++)
    {
        if (IdenticalandZeroJudge(i))
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << "    " << (int)(i / pow(10, j)) % 10;
            }
            cout << endl;
        }
    }
    system("pause");
}

bool IdenticalandZeroJudge(int x)
{
    bool bs[10] = {0};
    do
    {
        int number = x % 10;
        if (number == 0 || number > n)
        {
            return false;
            break;
        }
        if (bs[number] == 1)
        {
            return false;
            break;
        }
        bs[number] = 1;
        x /= 10;
    }

    while (x);
    if (0 == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}