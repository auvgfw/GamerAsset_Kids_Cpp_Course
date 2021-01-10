#include <stdio.h>
#include <iostream>
#define line 8
using namespace std;
int sum = 0;             //计算总的放法
int Map[8][8];             //方格位置
void Search(int x, int y); //寻找方案函数
int Check(int x, int y);   //检查函数检查该位置是否能放
void printResult();

int main()
{
    int i = 0, j = 0;
    for (i = 0; i <= 8; i++)
        for (j = 0; j <= 8; j++)
            Map[i][j] = 0;
    Search(0, 0);
    cout<<sum;
    system("pause");
    return 0;
}

void Search(int row, int col)
{
    
    if (col >= line)
        return;
    if (Check(row, col))
    {
        Map[row][col] = 1;
        if (row == line - 1) //如果是最后一行
        {
            sum++;
            printResult();
        }
        else //不是最后一行时，继续往下一行进行递归判定
            Search(row + 1, 0);
    }
    Map[row][col] = 0;    //该位置不符合要求存在，赋值为零
    Search(row, col + 1); //讨论旁边位置
}

int Check(int row, int col)
{
    int i = 0, m = 0, n = 0, prerow = row, precol = col;
    for (i = 0; i <= line - 1; i++) //横向检查
        if (Map[i][col] == 1)
            return 0;
    for (i = 0; i <= line - 1; i++) //纵向检查
        if (Map[row][i] == 1)
            return 0;

    m = row >= col ? col : row;
    row = row - m, col = col - m;
    while (row <= line - 1 && col <= line - 1) //由左上到右下的对角线判断
    {
        if (Map[row][col] == 1 && row != prerow && col != precol)
            return 0;
        row++, col++;
    }

    row = prerow, col = precol;
    n = row >= (line - 1 - col) ? (line - 1 - col) : row;
    row = row - n, col = col + n;
    while (row <= line - 1 && col >= 0) //由右上到左下的对角线判断
    {
        if (Map[row][col] == 1 && row != prerow && col != precol)
            return 0;
        row++, col--;
    }
    return 1;
}
void printResult()
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            cout << Map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}