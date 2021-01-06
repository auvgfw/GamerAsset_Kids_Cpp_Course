#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include <algorithm>
#include<cmath>
#include<vector>
#include<set>
using namespace std;
const int MAXN=1000+10;
struct Stu{
	string name;//人的名字
	int c,m,e;//C代表语文，M代表数学，E代表英语
}a[MAXN];//定义结构体
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].c>>a[i].m>>a[i].e;//输入
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=abs(a[i].c-a[j].c);//每一门分数相减
			int ans1=abs(a[i].m-a[j].m);
			int ans2=abs(a[i].e-a[j].e);
			int ans3=abs(a[i].e+a[i].c+a[i].m-a[j].c -a[j].m-a[j].e);//总分相减
			if(ans<=5&&ans1<=5&&ans2<=5&&ans3<=10){//判断是否符合旗鼓相当的对手
				if(a[i].name>a[j].name)//判断字典序
				cout<<a[j].name<<" "<<a[i].name<<"\n";
				else cout<<a[i].name<<" "<<a[j].name<<"\n";
			}
		}
	}
	return 0;//结束
}
