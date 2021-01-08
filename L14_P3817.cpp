#include<iostream>  
#include<cstring>   
using namespace std;      
int main(){
	int a,b,c[100002];
	long long d=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	cin>>c[i];
	for(int i=1;i<a;i++)
	{
		if(c[i]+c[i+1]>b)
		{
			d=d+c[i+1]-b+c[i];
			c[i+1]=b-c[i];
		}
	}
	cout<<d;
	return 0;	
}