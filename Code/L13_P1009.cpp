#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1005;
struct bign
{
    int len, s[N];
    bign()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign(int num) { *this = num; }
    bign(char *num) { *this = num; }
    bign operator=(int num)
    {
        char c[N];
        sprintf(c, "%d", num);
        *this = c;
        return *this;
    }
    bign operator=(const char *num)
    {
        len = strlen(num);
        for (int i = 0; i < len; i++)
            s[i] = num[len - 1 - i] - '0';
        return *this;
    }
    string str()
    {
        string res = "";
        for (int i = 0; i < len; i++)
            res = (char)(s[i] + '0') + res;
        return res;
    }
    void clean()
    {
        while (len > 1 && !s[len - 1])
            len--;
    }
    bign operator+(const bign &b)
    {
        bign c;
        c.len = 0;
        for (int i = 0, g = 0; g || i < len || i < b.len; i++)
        {
            int x = g;
            if (i < len)
                x += s[i];
            if (i < b.len)
                x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bign operator-(const bign &b)
    {
        bign c;
        c.len = 0;
        int x;
        for (int i = 0, g = 0; i < len; i++)
        {
            x = s[i] - g;
            if (i < b.len)
                x -= b.s[i];
            if (x >= 0)
                g = 0;
            else
            {
                x += 10;
                g = 1;
            };
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    bign operator*(const bign &b)
    {
        bign c;
        c.len = len + b.len;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < b.len; j++)
                c.s[i + j] += s[i] * b.s[j];
        for (int i = 0; i < c.len - 1; i++)
        {
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    bool operator<(const bign &b)
    {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }
    bign operator+=(const bign &b)
    {
        *this = *this + b;
        return *this;
    }
    bign operator-=(const bign &b)
    {
        *this = *this - b;
        return *this;
    }
};
istream &operator>>(istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream &operator<<(ostream &out, bign &x)
{
    out << x.str();
    return out;
}
int main()
{
    bign n, i, j;
    cin >> n;
    bign sum = 0, factorial;

    for (j = 1; j < n ; j += 1)
    {
        factorial = 1;
        for (i = 1; (i < j + 1); i += 1)
        {
            factorial = factorial * i;
        }
        sum += factorial;
    }
    cout << sum;
}