#include <iostream>
const double max_value(double arr[], double size);
using namespace std;
int main()
{
    double arr[] = {2, 4, 1, 7, 3};
    double size = 5.0;
    double max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "the max value of arrary is:" << max << endl;
    system("pause");
}
