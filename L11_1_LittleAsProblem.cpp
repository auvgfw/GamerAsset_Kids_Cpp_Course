#include <iostream> //P1706
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define MAX_N 100000
#define MAX_M 5000000
vector<int> vects[MAX_N];
set<int> city;

int main()
{
    int n, m;
    cin >> n >> m;
    int i;
    int a, b;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        city.insert(a);
        city.insert(b);
        vects[a].push_back(b);
        vects[b].push_back(a);
    }
    for (auto number : city)
    {
        for (auto a : vects[number])
        {
            cout << a << " ";
        }
        cout << endl;
    }
    system("pause");
}