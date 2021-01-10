#include<iostream>
using namespace std;

bool isrunyear(int n){
	if(n%4!=0)return 0;
	else{
		if(n%100==0){
			if(n%400==0){
				return 1;
			}
			return 0;
		}
		return 1;
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
		cout<<31;
		return 0;
	}else if(m!=2){
		cout<<30;
		return 0;
	}else{
		if(isrunyear(n))cout<<29;
		else cout<<28;
	}
	return 0;
}