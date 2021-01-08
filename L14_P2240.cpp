#include<cstdio>
#include<algorithm>//用到sort
using namespace std;
struct Node{//金币结构体
	int w,v;//w表示重量，v表示价值
}a[110];
int read(){//普通的快读，不解释
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
bool cmp(Node aa,Node bb){//定义排序方法
	return aa.v*bb.w>aa.w*bb.v;//按性价比从高到低排序，为防止精度问题直接交叉相乘
}
int main(){//主函数
	int n=read(),m=read();
	double ans=0;//记录答案
	for(int i=1;i<=n;i++) a[i].w=read(),a[i].v=read();
	sort(a+1,a+n+1,cmp);//排序
	for(int i=1;i<=n;i++){//一次遍历
		if(a[i].w<=m) ans+=a[i].v,m-=a[i].w;//够就全拿
		else{//不够
			ans+=a[i].v*m*1.0/(a[i].w*1.0);//拿上能拿的部分，注意强转double
			break;//直接退出循环
		}
	}
	printf("%.2lf",ans);//保留2位小数
	return 0;
}