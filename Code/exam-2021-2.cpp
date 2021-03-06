#include <iostream> 
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <bitset>
using namespace std;

int main()
{
    int n,i,j;
    vector<int> numbers;//存储数字用的向量
    vector<int> operators={0,0,0,1,1,1};//存储运算符用的向量,1表示加号0表示减号
    int sum_temp;//存储算式的值
    vector<int>sums;//存储所有运算结果，由于有多少个结果是不确定的，因此必须使用vector而不是数组来存储，因为vector可以动态的扩充容量
    int min;//运算结果种的最小值
    int counter[100000]={0};
    long long expressioncounter=0;//辅助，统计一共有多少个式子
    for (i = 0; i < 7; i++)//读入所有等待计算的数字
    {
        int x;
        cin>>x;
        numbers.push_back(x);
    } 
    sort(numbers.begin(),numbers.end());//对所有数字进行排序，这样使用next_permutation时才能得到他们所有的字典排序

    do
    {

        do
        {
            expressioncounter++;//统计到底有多少个式子，依题意，应有7！*c（6，3）个式子
            sum_temp=numbers[0];//暂存其中一个式子的运算结果，首先让其等于numbers里的第一个数
            //cout<<numbers[0];
            for(i=0;i<6;i++)//检查每一个运算符和数字
            {
                if(operators[i]==1)//运算符为1，做加法
                {
                    sum_temp=sum_temp+numbers[i+1];
                    //cout<<"+"<<numbers[i+1];
                }
                else
                {
                    sum_temp=sum_temp-numbers[i+1];//运算符为0，做减法
                    //cout<<"-"<<numbers[i+1];
                }
                
            }
            sums.push_back(sum_temp);//将一个式子的运算结果加入到sums向量种的最后一个位置。
            //cout<<"="<<sum_temp<<endl;
            //将38，44，49，54行的注释取消掉打开，可以查看每一个被穷举出来的式子

        } while (next_permutation(numbers.begin(),numbers.end()));//对number做字典排序
        
    } while (next_permutation(operators.begin(),operators.end()));//对operator做字典排序
    
    cout<<"total result:"<<expressioncounter<<endl;//输出一共共有多少种结果（确认是否等于数学计算）

    min=*min_element(sums.begin(),sums.end());//取出结果的最小值，请查阅文档，解释minelement的作用，返回值类型，解释为什么让min=*minelement。
    
    cout<<"min:******"<<min<<endl;
    
    if(min>0)
    {
        min=0;
    }

    for (auto it=sums.begin();it!=sums.end();it++)//统计sums里的各个结果，各有多少个。其中*it为遍历时每一次的结果的数值。
    {
        //cout<<*it<<endl;
        counter[(*it)-min]++;
        //将counter[结果数字]+1，例如发现sums里有一个5，就把counter[5]+1，遍历全部sums后，即可得到每个结果出现了几次。由于结果中有可能负数，不能让counter[]中有负数，所以如果min是负数，则统一减去min。
    }

    for(i=0;i<10000;i++)
    {
       if(counter[i]!=0)
       {
           cout<<i+min<<" "<<counter[i]<<endl;   //输出每种结果有多少个，统一加上min
       }
    }
    system("pause");
    return 0;
}