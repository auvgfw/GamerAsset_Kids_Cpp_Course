# STL

在国内的OI历史上曾经因为STL库的功能强大而被禁止使用，以维护对Pascal选手的公平。后来随着C++的普及和国际上OI、ACM比赛中选手越来越多使用STL，中国OI终于放开了STL的使用权。

与此同时OI类比赛的难度也水涨船高，因此，让学生学习STL已经不只是一个要不要追求最新技术的问题，而成了一个基本问题。

## 什么是STL

STL 是“Standard Template Library”的缩写，中文译为“标准模板库”。STL 是 C++ 标准库的一部分。

C++ 对模板（Template）支持得很好，STL 就是借助模板把常用的数据结构及其算法都实现了一遍，并且做到了数据结构和算法的分离。例如，vector 的底层为顺序表（数组），list 的底层为双向链表，deque 的底层为循环队列，set 的底层为红黑树，hash_set 的底层为哈希表。

从根本上说，STL 是一些**容器**、**算法**和其他一些组件的集合，所有容器和算法都是总结了几十年来算法和数据结构的研究成果，汇集了许多计算机专家学者经验的基础上实现的，因此可以说，STL 基本上达到了各种存储方法和相关算法的高度优化。

我们之前使用的sort,就是STL提供的算法之一，通过在常规情况下，时间复杂度最优的快速排序算法进行排序。


**查询网站**

https://www.cplusplus.com/reference/

**算法可视化**

https://visualgo.net/zh

## 容器

容器可以看作是数组的扩展，STL提供了向量vector（即顺序表），栈stack，队列queue，优先队列priority_queue,链表list，集合set，映射map等容器。

按照之前的讲述，顺序表、链表，应该可以执行insert，delete，find等操作

queue需要执行push，pop，front，rear操作

stack需要执行pop，top，push操作

有了STL，我们不需要每次写程序的时候都将上述操作自行实现一遍，而是可以简单的调用STL的容器。

## 向量Vector

Vector相当于数组。
### 定义方式

```cpp
vector<int> a;//定义用来存储int数据的向量a，注意其他容器的定义方法类似

vector<int> b(20);定义向量b，让其里面有20个空元素。
```
### 插入
vector可以看作一个容量无限的数组，可以一直进行插入操作。这个特性和链表有点像。及时vector在初始化时规定了一共有20个空元素，也依然可以插入。
虽然容量无限，但如果直接访问未经赋值的下标，也依然会出现越界问题。

```cpp
a.push_back(4);//在最后一个位置插入4,此时a[0]=4;
b.push_back(5);//b[20]=5
cout<<b[30];//越界
```

### 范例

参见L11——1——LittleAsProblem.cpp



## 栈Stack

**括号匹配**

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true

示例 2:

输入: "()[]{}"
输出: true

示例 3:

输入: "(]"
输出: false

示例 4:

输入: "([)]"
输出: false

示例 5:

输入: "{[]}"
输出: true

```cpp
#include<iostream>
#include<stack>
#include<string>
int main()
{
    stack<int> st;
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(')');
        else if (s[i] == '{') st.push('}');
        else if (s[i] == '[') st.push(']');
        // 第三种情况 是遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
        // 第二种情况 遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
        else if (st.empty() || st.top() != s[i]) cout<<"false";
        else st.pop(); 
    }
    // 第一种情况 此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
    cout<<st.empty();
}
```

## 队列Queue

**取扑克牌**

题目描述：

一副从1到n的牌，每次从牌堆顶取一张放桌子上，再取一张放牌堆底，直到手里没牌，设计程序，输入n，输出桌子上的牌堆的顺序数组。

输入N，例如N=4，则手上的牌为1，2，3，4；桌上的牌为1，3，2，4。



解题思路：

使用一个队列表示这堆牌，模拟取牌过程。

```cpp
#include<iostream>
#include<queue>
using namespace std;
queue<int> poker;
int N,x;
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        poker.push(x);
    }
    for(int i=1;!poker.empty();i++)
    {
        if(i%2==1)
        {
            cout<<poker.front()<<" ";//front()方法获取队首元素的值,奇数次，把牌直接翻开
        }
        else
        {
            x=poker.front();//偶数次，把牌放后面
            poker.push(x);
        }
        poker.pop();//无论翻开还是放后面，都删除第一张牌。
    }
    system("pause");
    return 0;
}
```
## 集合SET

集合能够调用的方法有insert,find等。集合没有顺序，加入到集合中的元素，自动升序排列。且集合中不能有重复的元素，加入到集合中的元素，如果是重复的，则自动忽略。

```cpp
#include<string>
#include<set>
#include<iostream>
int main()
{

    string name = "Includehelp";

    // Method 1, by passing string into the set constructor;
    set <char> set_name(begin(name), end(name));//将string转为set

    cout << "Converted by passing string into constructor" << endl;

    // Range-based for loop OR For-each loop
    for (auto i : set_name)//遍历各种容器的方法之一，可以遍历string，vector，set
        cout << i << " ";
    cout << endl;
}
```

输出结果将自动去掉原string中所有重复的字母，并按照ascii顺序牌列。


    Converted by passing string into constructor
    I c d e h l n p u


## 迭代器

要访问顺序容器和关联容器中的元素，需要通过“迭代器（iterator）”进行。迭代器是一个变量，相当于容器和操纵容器的算法之间的中介。迭代器可以指向容器中的某个元素，通过迭代器就可以读写它指向的元素。从这一点上看，迭代器和指针类似。

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;  //v是存放int类型变量的可变长数组，开始时没有元素
    for (int n = 0; n<5; ++n)
        v.push_back(n);  //push_back成员函数在vector容器尾部添加一个元素
    vector<int>::iterator i;  //定义正向迭代器,我们可以把i理解成指向vector<int>中的元素的指针，i可以视作vector中的位置。
    for (i = v.begin(); i != v.end(); ++i) {  //用迭代器遍历容器，v.begin(),v.end()返回的都是迭代器类型的值，也就是说，都表示v这个vector类中的位置。
        cout << *i << " ";  //与指针类似，i如果是指针的话，*i就是这个地址中存储的值，或者说，i这个迭代器指向的元素的值。
        *i *= 2;  //每个元素变为原来的2倍
    }
    cout << endl;
    //用反向迭代器遍历容器
    for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)
        cout << *j << " ";
    return 0;
}
```
遍历vector有以下方法

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(100); //v被初始化成有100个元素
    for(int i = 0;i < v.size() ; ++i) //size返回元素个数
        cout << v[i]; //像普通数组一样使用vector容器
    vector<int>::iterator i;
    for(i = v.begin(); i != v.end (); ++i) //用 != 比较两个迭代器
        cout << * i;
    for(i = v.begin(); i < v.end ();++i) //用 < 比较两个迭代器
        cout << * i;
    i = v.begin();
    while(i < v.end()) { //间隔一个输出
        cout << * i;
        i += 2; // 随机访问迭代器支持 "+= 整数"  的操作
    }
}
```

在vector中查找元素，并获取所在位置，也是通过vector实现的。
注意
```cpp
vector <int>::iterator iElement = find(vecIntegerArray.begin(),
	                       vecIntegerArray.end(),3);
	 if( iElement != vecIntegerArray.end() )
	 {
	      int nPosition = distance(vecIntegerArray.begin(),iElement);
		  cout << "Value  "<< *iElement;
		  cout <<"  find in the vector at position: " <<nPosition + 1 <<endl;
	 }
```

注意上述程序中，迭代器iElement是一个指针，表示的是一个地址，而不是下标。元素在vector中的位置应当用iElement-vector.begin计算。

除了vector以外，集合set中的元素，也可以通过类似的方法，用迭代器遍历、查找，大家可以自己尝试。

## 算法

STL提供了一系列的，在通常情况下实现了最优化的算法。
竞赛常用算法一般在algorithm头文件中。


### sort

用于排序的sort函数采用了快速排序算法来实现，时间复杂度是nlogn。
普通的sort用法如下

```cpp
#include<algorithm>
using namespace std;
int main()
{
  int a[4]={1,5,3,4};
  vector<int> b(a);//把数组a里面的所有的数字赋值给向量b
  sort(a,a+4);//数组sort，从头到尾。我们可以将4理解成一共给4个数排序。实际上是给位于[0，4）区间内的下标排序
  sort(b.begin(),b.end());//向量sort，从头到尾
  for(int i=0;i<4;i++)
    cout<<a[i]<<" ";//输出为 1 3 4 5
    cout<<b[i]<<" ";
}
```
我们也可以自定义排序规则
下面的程序根据数字中7的数量排序

```cpp
#include<iostream>
#include<algorithm>
bool cmp_count7(int a,int b)
{
    int SevenInA=0;
    int SevenInB=0;
    int r;
    while(a!=0)
    {
        r=a%10;
        if(r==7)
        {
            SevenInA++;
        }
        a/=10;b
    }

    while(b!=0)
    {
        r=b%10;
        if(r==7)
        {
            SevenInB++;
        }
        b/=10;
    }
    return SevenInA>SevenInB;
}
int main()
{
    int count7array[]={34567,2775,7773,986543,7777};
    size_t size = sizeof(array) / sizeof(array[0]); 
    sort(count7array,count7array+size)；
}
```

### fill
fill与memset的作用类似。

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int a[4]={1,2,3,4};
  fill(a,a+4,1);
  for(int i=0;i<4;i++)
    cout<<a[i]<<" "; //输出为 1 1 1 1
}
```

### min,max,minmax

```cpp
// minmax example
#include <iostream>     // std::cout
#include <algorithm>    // std::minmax

int main () {
  auto result = std::minmax({1,2,3,4,5});

  std::cout << "minmax({1,2,3,4,5}): ";
  std::cout << result.first << ' ' << result.second << '\n';
  return 0;
}
```

```cpp
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
 
int main()
{
	int x =1, y =-2;
	cout <<max(x,y)<< " "<< min(x,y)<<endl;
    return 0;
} 
```


### swap
swap(x,y)用来交换x和y的值

```cpp
#include<iostream> 
#include<algorithm>
using namespace std;
int main()
{
	int x=1, y=2, z;
	swap(x, y);
	cout<< x << " "<< y<<endl;
	swap(x, z); 
	cout<<x<< z <<endl;
	swap(y, z); 
	cout<<y<< z <<endl; 
	return 0;
}
```
### reverse
reverse(it, it2)可以将数组指针在[it, it2)之间的元素或容器的迭代器在[it, it2)范围内的元素。

可以对整形数组进行反转。

 ```cpp
#include<algorithm>
#include<iostream>
using namespace std; 
int main()
{
	int a[10]= {10, 11, 12, 13, 14, 15}; 
	reverse(a, a+4);//a[0]~a[3]反转
	for(int i=0; i<6; i++){
		cout<<a[i]<<" ";
	} 
	return 0;
}
```

也可以对字符串进行反转

```cpp
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str = "abcdefghi";
	reverse(str.begin()+2, str.begin()+6);//对a[2]~a[5]逆转*左闭右开* 
	for( int i=0; i < str.length(); i++){
		cout<<str[i]<<" ";
	} 	
	return 0;
}
```
### next_permutation
next_permutation将一个数组或向量变为下一个字典序列，当变换完毕后返回false

```cpp
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int a[10] = {3, 2, 1};
	do{
		cout<<a[0]<< " "<<a[1]<<" "<<a[2]<<endl;	
	}while(next_permutation(a, a+3)); 	
	return 0;
}
```

## cmath中的计算工具

cmath提供了一系列的数学工具，例如sqrt，pow，abs，取整，三角函数等都在里面。

[cmath参考](http://www.cplusplus.com/reference/cmath/?kw=cmath)

## 范例

[P1104 生日](https://www.luogu.com.cn/problem/P1104)

[P1090 合并果子](https://www.luogu.com.cn/problem/P1090)