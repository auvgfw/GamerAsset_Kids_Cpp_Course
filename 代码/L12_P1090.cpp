#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x,q.push(x);
	while(q.size()>=2){
		int a=q.top(); q.pop();
		int b=q.top(); q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	cout<<ans<<endl;
	return 0;
}