#include<iostream>
#include<algorithm>
#include<iomanip>
int x[30];//x[i]=0,选择第i+1位，x[i]=1,不选择第i+1位。一开始全为0，都选择
using namespace std;
int main(){
    int n,r;
    cin>>n>>r;
    for(int i=r;i<n;++i)
        x[i]=1; //例如r=3，n=5，就是一开始让123都选中，3-5的数都设为1，不选中
    do{
        for(int i=0;i<n;++i)
            if(x[i]==0) cout<<setw(3)<<i+1;
        cout<<endl;
    }while(next_permutation(x,x+n));

    system("pause");
    return 0;
}