//性质 1：是偶数；
//性质 2：大于 4 且不大于 12。

#include<iostream>
int main()
{
    int n;
    std::cin>>n;
    if(   (n%2==0)  &&  (n>4&&(n<=12))  )
    {
        std::cout<<1;
    }

    if(   (n%2==0)  ||  (n>4&&(n<=12))  )
    {
        std::cout<<1;
    }

    if( ( (n%2!=0)  &&  (n>4&&(n<=12)) )||(    (n%2==0)  &&  !(n>4&&(n<=12))       )         )

}