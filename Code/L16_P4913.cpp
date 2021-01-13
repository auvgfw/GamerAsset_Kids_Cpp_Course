#include <iostream>
using namespace std;

const int MAXN = 1e6 + 10;

struct node
{
    int left, right;
};
node tree[MAXN]; //存储结构定义

int n, ans;

void dfs(int id, int deep)
{
    if (id == 0)
        return;                    //到达叶子节点时返回
    ans = max(ans, deep);          //更新答案
    dfs(tree[id].left, deep + 1);  //向左遍历
    dfs(tree[id].right, deep + 1); //向右遍历
}

int main()
{
    cin >> n;
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> tree[i].left >> tree[i].right;
    } //读入+建树
    dfs(1, 1);
    cout << ans << endl;

    system("pause");
    return 0;
}
