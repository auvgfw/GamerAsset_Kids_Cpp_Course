#include<iostream>
using namespace std;
int Stairs(int n)
{
    if(n<1)
    return 0;
    if(n==1)
    return 1;
    if(n==2)
    return 2;
    return Stairs(n-1)+Stairs(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<Stairs(n)<<endl;

    //动归
    int f[100];
    int i;
    f[0]=0;
    f[1]=1;
    f[2]=2;
    for(i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cout<<f[n];
}