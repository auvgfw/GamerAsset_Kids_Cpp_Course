#include<iostream> 
#include<cmath> 
using namespace std;  
int n;  
int a[1000][1000];  
int main()  
{       
	cin>>n; 
	for(int i=0;i<n;i++)  
	for(int j=0;j<=i;j++)  
	cin>>a[i][j];//输入

    
	for(int i=n-2;i>=0;i--)   
	{  
 		for(int j=0;j<=i;j++)
         {
		    a[i][j]+=max(a[i+1][j],a[i+1][j+1]); 
         }

    } 
    cout<<a[0][0]<<endl; 
    return 0; 
 }