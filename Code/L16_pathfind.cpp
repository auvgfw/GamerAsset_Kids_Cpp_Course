#include<iostream>
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

string path;
vector<string>paths;
int lcounter;
int rcounter;
int pathcount;
void dfs(Node root)
{

	if (lcounter + rcounter == 8)
	{
		cout << path<<endl;
		paths.push_back(path);
		lcounter = 0;
		rcounter = 0;
		path = "";
		return;
	}
	


	if (root.left != 0)
	{
		//cout << root.left<<" ";
		//cout << 'L';
		lcounter++;
		path.push_back('L');
		dfs(tree[root.left]);
	}
	if (root.right != 0)
	{
		//cout << root.right<<" ";
		//cout << 'R';
		rcounter++;
		path.push_back('R');
		dfs(tree[root.right]);
	}

}

int main()
{


	Node node;
	int left, right, data,i;

	for (i = 1; i <1024; i++)
	{
		node.data = i;
		node.left = i * 2;
		node.right = i * 2 + 1;
		tree[i] = node;
	}

	dfs(tree[1]);

	for (auto it = paths.begin(); it != paths.end(); it++)
	{
		int l, r;
		l = count((*it).begin(), (*it).end(),'l');
		r = count((*it).begin(), (*it).end(),'r');
		if (l == 3 && r == 5)
		{
			cout << *it;
			pathcount++;

		}
	}

	cout << pathcount;

}

