#include<iostream>
using namespace std;
int main()
{
    double n;
    int a;
    cin>>n;//123.4
    a=n*10;//1234
    cout<<a%10;
    cout<<".";
    cout<<a/10%10;
    cout<<a/100%10;
    cout<<a/1000;

    system("pause");
}