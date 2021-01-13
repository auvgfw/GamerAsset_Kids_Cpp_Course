#include<iostream>//测试用例采用4715
#include<string>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//n个红球m个白球，有多少种排列方式。

struct Node
{
	int data;
	int left;
	int right;
};

vector<Node> tree(10000);


void build(int left,int right)
{
	cout << left << " " << right << endl;
	if (tree[left].data == 0)
	{

		 build(tree[left].left, tree[left].right);
	}
	
	else if (tree[right].data == 0)
	{
		 build(tree[right].left, tree[right].right);
	}
	else
	{
		cout << tree[left].data << "+" << tree[right].data<<endl;
		tree[left/2].data=tree[left].data + tree[right].data;
		
	}
}

int main()
{


	Node node;
	int left, right, data, i;
	int n;
	cin >> n;


	for (i = 1; i < pow(2,n+1); i++)
	{
		node.data = 0;
		node.left = i * 2;
		node.right = i * 2 + 1;
		tree[i] = node;
	}

	for (i = pow(2,n); i < pow(2,n+1); i++)
	{
		cin >> node.data;
		node.left = 0;
		node.right = 0;
		tree[i] = node;
	}
	while(tree[1].data==0)
	{
		build(2, 3);
	}
	cout << tree[1].data;
	





}

