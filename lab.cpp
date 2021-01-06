#include "stdio.h"
struct num
{
    int data;
    int data2;
    int rank;
};
int main()
{
    int n, i, j, k;
    int temp = 1;
    scanf("%d", &n);
    struct num a[10000];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i].data);
        a[i].data2 = a[i].data;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i].data2 == a[j].data2)
            {
                a[j].data2 = -1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i].data > a[j].data && a[j].data2 != -1)
            {
                temp++;
            }
        }
        a[i].rank = temp;
        temp = 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i].rank);
    }
}