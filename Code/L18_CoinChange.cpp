#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> coins;
    int n;
    int i,j;
    cin>>n;
    int coin_temp;
    i=0;
    for(i=0;i<3;i++)
    {

        cin>>coin_temp;
        coins.push_back(coin_temp);
    }

    vector<int>::iterator iter;

    int f[100];
    f[0]=0;
    for(i=1;i<=n;i++)
    {
        f[i]=6666666;
        for(iter=coins.begin();iter!=coins.end();iter++)
        {
            if(i>=*iter && f[i-*iter]!=6666666)
            {
                f[i]=min(f[i-*iter]+1,f[i]);
    
            }
        }
        cout<<i<<":"<<f[i]<<endl;


    }



    cout<<endl;
    if(f[n]==6666666)
    {
        cout<<-1;
    }
    else
    {
        cout<<f[n];
    }
    
}