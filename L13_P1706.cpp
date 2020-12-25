#include<iostream>
#include<cmath>
using namespace std;
//判断是否存在重复数字
bool IdenticalJudge(int x);

int main()
{
    int n;
    int min,max;
    cin>>n;
    max=ceil(pow(10,n))-1;
    min=ceil(pow(10,n-1));
    for(int i=min;i<=max;i++)
    {
        if(IdenticalJudge(i))
        {
            cout<<i<<endl;
        }
    }
    system("pause");

}

bool IdenticalJudge(int x)
{
    bool bs[10]={0};
    do 
    {
        int n=x%10;
        if ( bs[n] ==1 ) 
        {
            return false;
            break; 
        }
        bs[n] = 1;
        x/=10;
    
    } 

    while (x);
    if ( 0==x ) 
    {
        return true;
    }
    else
    {
        return false;
    }
    
}