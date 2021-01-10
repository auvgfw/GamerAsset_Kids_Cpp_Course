#include<iostream>
#include<stack>
using namespace std;
stack<int> n;
char ch;
int s,x,y;
int main()
{
    while(ch!='@')
    {
        ch=getchar();
        switch(ch)
        {
            case '+':x=n.top();n.pop();y=n.top();n.pop();n.push(x+y);break;
            case '-':x=n.top();n.pop();y=n.top();n.pop();n.push(y-x);break;
            case '*':x=n.top();n.pop();y=n.top();n.pop();n.push(x*y);break;
            case '/':x=n.top();n.pop();y=n.top();n.pop();n.push(y/x);break;
            case '.':n.push(s);s=0;break;
            default :s=s*10+ch-'0';break;
        }
    }
    printf("%d\n",n.top());
    system("pause");
    return 0;
}