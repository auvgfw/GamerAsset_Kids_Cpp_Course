#include <iostream>
using namespace std;


bool isMarked(int room)
{
    int ge, shi, bai, qian;

    qian = room / 1000;
    bai = room / 100 % 10;
    shi = room / 10 % 10;
    ge = room % 10;
    if (qian == 0)
    {

        if ((ge == 6 && bai == 9) || (ge == 9 && bai == 6) || (ge == 8 && bai == 8) || (ge == 0 && bai == 0) || (ge == 1 && bai == 1))
        {
            if (shi == 1 || shi == 0 || shi == 8)
            {
                //cout<<room<<endl;
                return true;
            }
        }
    }
    else
    {
        if ((ge == 6 && qian == 9) || (ge == 9 && qian == 6)|| (ge == 8 && qian == 8) || (ge == 0 && qian == 0) || (ge == 1 && qian == 1))
        {
            if ((shi == 6 && bai == 9) || (shi == 9 && bai == 6) || (shi == 8 && bai == 8) || (shi == 0 && bai == 0) || (shi == 1 && bai == 1))
            {
                return true;
            }
        }
    }
    //cout<<false;
    return false;
}


int main()
{
    int f, n;
    cin >> f >> n;
    int i, j;
    int room;
    int count = 0;
    for (i = 1; i <= f; i++)
    {
        for (j = 1; j <= n; j++)
        {
            room = i * 100 + j;
            if (isMarked(room))
            {
                count++;
            }
        }
    }

    cout<<count;
    
    system("pause");
    return 0;
}
