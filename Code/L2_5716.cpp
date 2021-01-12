using namespace std;

#include "iostream"

int main()

{
    int year, month;
    cin >> year >> month;
    int runnian;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)

    {
        runnian = 1;
    }
    else

    {
        runnian = 0;
    }

    if (month == 1 || month == 3 || month == 5 || month == 7||month == 8 || month == 10 || month == 12)
    {
        cout << 31;
    }
    else if(month!=2)
    {
        cout<<30;
    }
    else
    {
        if(runnian==1)
        {
            cout<<29;
        }
        else
        {
            cout<<28;
        }
        
    }
    
system("pause");

return 0;
}