#include<iostream>
using namespace std;
int a[101] = {0};
bool b[101]={0};
int main(){
    // int i, j;
    // for(i = 1; i <= 100; ++i){
    //     for(j = 1; j <= 100; ++j){
    //         if(j % i == 0){
    //             if(a[j] == 0){
    //                 a[j] = 1;
    //             } else {
    //                 a[j] = 0;
    //             }               
    //         }
    //     }
    // }
    // for(i = 1; i <= 100; ++i){
    //     if(a[i] == 1){
    //         cout<<i<<" ";
    //     } 
    // }
    // system("pause");
    // return 0;

    int i,j;
    for(i=1;i<=100;i++)
    {
        for(j=1;j*i<=100;j++)
        {
            b[j*i]=!b[j*i];
        }

    }
    for(i=1;i<=100;i++)
    {
        if(b[i])
        {
            cout<<i<<" ";
        }
    }
    system("pause");
}