#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set>
#include <sstream>
using namespace std;
int n;
string c;
char ch;
int a, b, q;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> c;
        a = 0, b = 0;
        if (!isalpha(c[0]))
        {
        istringstream(c) >> a;
            cin >> b;
        }
        else
        {
            ch = c[0], cin >> a >> b;
        }
        if (ch == 'a')
            cout << a << "+" << b << "=" << a + b << endl, q = a + b;
        if (ch == 'b')
            cout << a << "-" << b << "=" << a - b << endl, q = a - b;
        if (ch == 'c')
            cout << a << "*" << b << "=" << a * b << endl, q = a * b;
        int len = 0;
        if (a == 0)
            len++;
        else
            while (a)
                a /= 10, len++;
        if (b == 0)
            len++;
        else
            while (b)
                b /= 10, len++;
        if (q < 0)
            len++, q = -q;
        if (q == 0)
            len++;
        else
            while (q)
                q /= 10, len++;
        cout << len + 2 << endl;
    }
    return 0;
}