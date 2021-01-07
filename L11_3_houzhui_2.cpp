 #include<iostream>
    #include<cstdio>
    using namespace std;
    long long stk[1000];
    int main(){
    long long i=0,now=0;
    char op;
    while((op=getchar())!='@'){
        if(op>='0'&&op<='9') now*=10,now+=op-'0';
        else if(op=='.'){
            stk[++i]=now;
            now=0;
        }
        else if(op=='+'){
            stk[i-1]=stk[i-1]+stk[i];
            stk[i]=0;
            i--;
        }
        else if(op=='-'){
            stk[i-1]=stk[i-1]-stk[i];
            stk[i]=0;
            i--;
        }
        else if(op=='*'){
            stk[i-1]=stk[i-1]*stk[i];
            stk[i]=0;
            i--;
        }
        else if(op=='/'){
            stk[i-1]=stk[i-1]/stk[i];
            stk[i]=0;
            i--;
        }
    }
    cout<<stk[1];
    return 0;
}