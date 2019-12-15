#include <iostream>
using namespace std;

void push(int x);
void pop();

int a[10000]; int number; int popnumber;

int main()
{
	int aa[100];
	int i;
//产生100个随机数，存入到aa数组里，并显示
	for (i = 0; i < 100; i++)
	{
		aa[i] = rand() % 1000;
		cout << aa[i] << " ";
	}
	cout << endl << endl;
//进行入栈操作，将aa里的数，从头到尾，入栈
	for (i = 0; i < 100; i++)
	{
		push(aa[i]);
	}
进行出栈操作，并显示每一次出栈结果
	for (i = 0; i < 100; i++)
	{
		pop();
		cout << popnumber<<" ";
	}
}
//入栈函数的实现方法
void push(int x)
{
	a[number] = x;
	number++;
}
//出栈函数的实现方法
void pop()
{
	number--;
	popnumber = a[number];
}
