#include <iostream> //P1706
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
int a[10];
int b[500000][10];    
string op[1000];       
int sum[300][500000]; 
int counter[1000];
int main()
{
    int n, i, j = 1, k, w;
    cin >> n;
    for (i = 0; i <= pow(2, n - 1) - 1; i++)
    {
        op[i + 1] = std::bitset<8>(i).to_string();
        op[i + 1].erase(op[i + 1].begin(), op[i + 1].end() - n + 1);
    }

    j = 1;
    for (i = 1; i <= n; i++)

    {
        a[i] = n - i + 1;
        j *= i;
    } //按从小到达生成1-n的序列
    for (i = 1; i <= j; i++)
    {
        next_permutation(a + 1, a + n + 1);
        copy(begin(a), begin(a) + n + 1, begin(b[i]));
        for (k = 1; k <= n; k++)
        {
            //cout << b[i][k];
        }
    }

    //op[i],i=1~pow(2,n-1),存放了所有运算符
    //b[w],w=1~j(j=n!),存放了所有数列组合
    //b[w][k],k=1~n-1,存放了一个数列中的所有数
    //sum[i][w],存放所有结果
    for (w = 1; w <= j; w++)
    {
        for (i = 1; i <= pow(2, n - 1); i++)
        {
            k = 1;
            sum[i][w] = b[w][k];
            cout << b[w][k];
            for (k = 2; k <= n; k++)
            {
                if (op[i][k - 2] == '0')
                {
                    sum[i][w] -= b[w][k];
                    cout << "-" << b[w][k];
                }
                else
                {
                    sum[i][w] += b[w][k];
                    cout << "+" << b[w][k];
                }
            }
            cout << "=" << sum[i][w]<<" ";

        }
                    cout << endl<<endl;
    }

    for (w = 1; w <= j; w++)
    {
        for (i = 1; i <= pow(2, n - 1); i++)
        {
            int temp=sum[i][w];
            counter[temp+n*n]++;
        }
    }

    for(k=0;k<n*n*2;k++)
    {
       if(counter[k]!=0)
       {
           cout<<k-n*n<<" "<<counter[k]<<endl;   
       }
    }
    system("pause");
    return 0;
}