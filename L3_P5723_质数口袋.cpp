#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

long long top,a[100050],n,s;

bool prime(int x)
{
     if(x<2) return 0;
     if(x==2) return 1;
     for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return 0;
     return 1;
}

int main()
{
	cin>>n;
	for(int i=2;i<=100000;i++)
	{
		if(prime(i)==1)
		{
			a[++top]=i;
		}
	}
	int zs=0;
	for(int i=1;i<=top;i++)
	{
		if(s+a[i]>n)
		  break;
		s+=a[i];
		zs++;
	}
	for(int i=1;i<=zs;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<zs;
}