#include<iostream>

using namespace std;
int a[10001],b[10001],k1=1,f1=1,f2=1,r1,r2,k,i;
int main()
{
	int m,n;
	cin>>m>>n;
	for(i=1;i<=m;i++)
		a[i]=i;
	for(i=1;i<=n;i++)
		b[i]=i;
	cin>>k;
	r1=m;
	r2=n;
	while(k1<=k)
	{
		cout<<a[f1]<<" "<<b[f2]<<endl;
		a[++r1]=a[f1++];
		b[++r2]=b[f2++];
		k1++;
	}
	system("pause");
	return 0;
		
}