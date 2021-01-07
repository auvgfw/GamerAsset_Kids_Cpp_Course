#include<iostream>
#include<queue>
using namespace std;
queue<int> poker;
int N,x;
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        poker.push(x);
    }
    for(int i=1;!poker.empty();i++)
    {
        if(i%2==1)
        {
            cout<<poker.front()<<" ";//front()方法获取队首元素的值,奇数次，把牌直接翻开
        }
        else
        {
            x=poker.front();//偶数次，把牌放后面
            poker.push(x);
        }
        poker.pop();//无论翻开还是放后面，都删除第一张牌。
    }
    system("pause");
    return 0;
}