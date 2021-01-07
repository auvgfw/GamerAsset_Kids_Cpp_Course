# STL

在国内的OI历史上曾经因为STL库的功能强大而被禁止使用，以维护对Pascal选手的公平。后来随着C++的普及和国际上OI、ACM比赛中选手越来越多使用STL，中国OI终于放开了STL的使用权。

与此同时OI类比赛的难度也水涨船高，因此，让学生学习STL已经不只是一个要不要追求最新技术的问题，而成了一个基本问题。

## 什么是STL

STL 是“Standard Template Library”的缩写，中文译为“标准模板库”。STL 是 C++ 标准库的一部分。

C++ 对模板（Template）支持得很好，STL 就是借助模板把常用的数据结构及其算法都实现了一遍，并且做到了数据结构和算法的分离。例如，vector 的底层为顺序表（数组），list 的底层为双向链表，deque 的底层为循环队列，set 的底层为红黑树，hash_set 的底层为哈希表。

从根本上说，STL 是一些**容器**、**算法**和其他一些组件的集合，所有容器和算法都是总结了几十年来算法和数据结构的研究成果，汇集了许多计算机专家学者经验的基础上实现的，因此可以说，STL 基本上达到了各种存储方法和相关算法的高度优化。

我们之前使用的sort,就是STL提供的算法之一，通过在常规情况下，时间复杂度最优的快速排序算法进行排序。

## 容器

容器可以看作是数组的扩展，STL提供了向量vector（即顺序表），栈stack，队列queue，优先队列priority_queue,链表list，集合set，映射map等容器。

按照之前的讲述，顺序表、链表，应该可以执行insert，delete，find等操作

queue需要执行push，pop，front，rear操作

stack需要执行pop，top，push操作

有了STL，我们不需要每次写程序的时候都将上述操作自行实现一遍，而是可以简单的调用STL的容器。

## 向量Vector

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
