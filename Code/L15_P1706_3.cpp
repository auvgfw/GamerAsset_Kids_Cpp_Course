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
int n,pd[100],used[100];//pd是判断是否用过这个数
void print()//输出函数
{
    int i;
    for(i=1;i<=n;i++)
    printf("%5d",used[i]);//保留五位常宽
    cout<<endl;
}
void dfs(int k)//深搜函数，当前是第k格
{
    int i;
    if(k==n) //填满了的时候
    {
        print();//输出当前解
        return;
    }
    for(i=1;i<=n;i++)//1-n循环填数
    {
        if(!pd[i])//如果当前数没有用过
        {
            pd[i]=1;//标记一下
            used[k+1]=i;//把这个数填入数组
            dfs(k+1);//填下一个
            pd[i]=0;//回溯
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);//注意，这里是从第0格开始的！
    return 0;
}