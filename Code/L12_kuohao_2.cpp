#include<iostream>
#include<stack>//必须包含这个才能使用stack容器
#include<string>
using namespace std;
int main()
{
    stack<char> st;//定义一个存放int类型数据的栈
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(s[i]);//入栈操作
        else if (s[i] == '{') st.push(s[i]);
        else if (s[i] == '[') st.push(s[i]);
        // 第三种情况 是遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
        // 第二种情况 遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
        else if (st.empty())
        {
            break;
        }
        else if (st.top() == '(')
        {
            cout << st.top();
      
            if (s[i] != ')')
            {
                cout << s[i];
                break;
            }
        }
      
        else if (st.top() == '[')
        {
            if (s[i] != ']')
            {
                break;
            }
        }
        else if (st.top() == '{')
        {
            if (s[i] != '}')
            {
                break;
            }
        }
        st.pop(); //出栈操作
        
    }
    // 第一种情况 此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
    cout << boolalpha << st.empty();
    system("pause");
}