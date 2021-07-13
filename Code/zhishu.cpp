#include <iostream>
using namespace std;
 
int main ()
{
   // 一个带有 5 行 2 列的数组
   int a[3][4];
 
   // 输出数组中每个元素的值                      
   for ( int i = 0; i < 3; i++ )//外面循环行
   {
      for ( int j = 0; j < 4; j++ )//里面循环列
      {
         cin >> a[i][j];
      }
   }

   for ( int i = 0; i < 4; i++ )//外面循环行
   {
      for ( int j = 0; j <3; j++ )//里面循环列
      {
         cout << a[j][i]<<" ";
      }
      cout<<endl;
   }
   return 0;
}