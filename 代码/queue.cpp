#include <iostream>
using namespace std;
const int MAX = 10;
int a[MAX];
int qstart;
int qend;

void push(int x);
void pop();
int n;
int qsize;

int main()
{
	qstart = 0;
	qend = 0;
	qsize = 0;

	string b;
	while (1)
	{
		cin >> b;

		if (b == "push")
		{
			int number;
			cin >> number;
			push(number);
		}
		if (b == "pop")
		{
			pop();
			//cout << n << endl;
		}
	}

}

void push(int x)
{
	a[qend] = x;
	qend++;
	qsize++;
	if (qend==MAX)
	{
		qend = 0;
	}
}

void pop()
{
	if (qsize>0)
	{
		n = a[qstart];
		qstart++;
		qsize--;
		cout << n<<endl;
		if (qstart == MAX)
		{
			qstart = 0;
		}
	}
	else
	{
		cout << "error" << endl;
	}
}
