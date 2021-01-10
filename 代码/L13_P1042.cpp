#include<iostream>
#include<cmath>
using namespace std;

char str[100010];
int cnt=0;

void show(int n){

    int a=0,b=0;
    for(int i=0;i<cnt;i++){
        if(str[i]=='W') a++;
        if(str[i]=='L') b++;

        if((a>=n||b>=n)&&abs(a-b)>=2){
            cout<<a<<":"<<b<<endl;
            a=b=0;
        }
    }

    //新的一轮刚开始，或上一局没有打完
    cout<<a<<":"<<b<<endl;
}

int main(){
    char ch;

    while(cin>>ch&&ch!='E'){
        if(ch=='W'||ch=='L'){
          str[cnt++]=ch;
        }
    }

    show(11);
    cout<<endl;
    show(21);
}