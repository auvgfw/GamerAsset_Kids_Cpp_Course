
#include<iostream>
using namespace std;
int main()
{
    int n;
    int i;
    cin>>n;
    i=1;
    while(n!=1)
    {
        n=n/2;
        i++;
    }
    cout<<i;
    system("pause");
}