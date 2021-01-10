#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
int n;
struct node{
	string name;//姓名
	int year,mon,day;//年月日
	int level;//记输出顺序
}nn[105];

bool cmp(node a,node b){
	if(a.year != b.year)
	return a.year < b.year;//如果出生年份不相等便直接按照年份进行排序
	else{
	if(a.mon != b.mon) return a.mon < b.mon;//年份相等月份不相等
	else if(a.day == b.day && a.mon == b.mon) return a.level > b.level;//同年同月同日生 便把后输入的排在前面
	else if(a.day != b.day && a.mon == b.mon) return a.day < b.day;//同年同月不同日
	}
}

int main(){
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin>>nn[i].name>>nn[i].year>>nn[i].mon>>nn[i].day;
		nn[i].level = i;//记录输入顺序
	}
	stable_sort(nn + 1,nn + n + 1,cmp);//注意边界
	for(int i = 1; i <= n; ++i) cout<<nn[i].name<<endl;
	return 0;
}