#include <iostream>
#include<string>
#include<cmath>
using namespace std;

struct stundent
{
    string name;
    int chinese;
    int math;
    int english;
    int total;

    void gettotal()
    {
        total = chinese + math + english;
    }
};

int main()
{
    int n;
    stundent stu[1001];
    cin >> n;
    int i;
    int j;
    
    for (i = 0; i < n; i++)
    {
        cin >> stu[i].name >> stu[i].chinese >> stu[i].math >> stu[i].english;
        stu[i].gettotal();
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int a1,b1,c1;
            int d;
            a1 = abs(stu[i].chinese - stu[j].chinese);
            b1 = abs(stu[i].math - stu[j].math);
            c1 = abs(stu[i].english - stu[j].english);
            d = abs(stu[i].total - stu[j].total);
            if ( a1 <= 5  &&b1 <= 5&& c1 <= 5 && d <= 10)
            {
                cout << stu[i].name << " " << stu[j].name<<endl;
            }
        }
    }
}