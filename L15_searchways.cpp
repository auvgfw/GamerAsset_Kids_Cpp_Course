#include <iostream>
using namespace std;

int get(int x, int y) 
{
	if (x == 1) return y + 1;
	if (y == 1) return x + 1;
	return get(x - 1, y) + get(x, y - 1);
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << get(x-1, y-1) << endl;
    system("pause");
    return 0;
}