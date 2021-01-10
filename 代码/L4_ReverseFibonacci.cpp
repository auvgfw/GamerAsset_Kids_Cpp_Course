#include<iostream>
using namespace std;
int main()
{
    int a[20];
    int i;
    a[0]=0;
    a[1]=1;
    for(i=2;i<20;i++)
    {
        a[i]=a[i-2]+a[i-1];
    }
    for(i=19;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
    system("pause");
    return 0;
}