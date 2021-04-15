#include<iostream>
using namespace std;
int main()
{
    int m,n;
    int i,j;
    int f[100][100];
    cin>>m>>n;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                f[i][j]=1;
            }
            else
            {
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
    }
    cout<<f[m][n];
}