#include<iostream>
#include<stack>
using namespace std;
int main()
{
    char t;
    stack<int> s;
    while(cin>>t&&t!='@')
    {
        if(t>='0'&&t<='9')
        {
            int temp=t-'0';
            while(cin>>t&&t>='0'&&t<='9')
                temp=temp*10+t-'0';
            s.push(temp);
        }
        if(t=='+')
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b+a);
        }
        if(t=='-')
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b-a);
        }
        if(t=='/')
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b/a);
        }
        if(t=='*')
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b*a);
        }
    }
    cout<<s.top()<<endl;
    return 0;
} 