#include<iostream>
using namespace std;
/*
int main()
{
    int n=3516;
    int a;
    int b;
    int c;
    int d;
    a=n/1000;
    b=n/100%10;
    c=n/10%10;
    d=n%10;
    cout<<a;
    cout<<",";
    cout<<b;
    cout<<",";
    cout<<c;
    cout<<",";
    cout<<d;
    cout<<endl;
    system("pause");
}
*/
int main()
{
    int n=3516;
    int a;
    while(n>0)//让学生思考，什么时候可以继续循环?
    {
        a=n%10;
        cout<<a;
        n=n/10;


    }
    system("pause");
}
