#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cmath>
int sel[30];//sel[i]=0,选择第i+1位，x[i]=1,不选择第i+1位。一开始全为0，都选择
int x[30];

using namespace std;

bool isprime(int n){//判断是否质数
    int s=sqrt(double(n));
    for(int i=2;i<=s;i++){
        if(n%i==0)return false;
    }
    return true;
}


int main(){
    int n,k;
    int sum;
    vector<int> sums;
    int result=0;
    cin>>n>>k;

    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }

    for(int i=k;i<n;++i)
        sel[i]=1; //例如r=3，n=5，就是一开始让123都选中，3-5的数都设为1，不选中
    do{
        sum=0;
        for(int i=0;i<n;++i)
            if(sel[i]==0) sum=sum+x[i];
        sums.push_back(sum);
    }while(next_permutation(sel,sel+n));

    for(auto sum:sums)
    {
        if(isprime(sum))
        {
            result++;
        }
    }
    cout<<result;

    system("pause");
    return 0;
}