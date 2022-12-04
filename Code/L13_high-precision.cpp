﻿#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

//compare比较函数：相等返回0，大于返回1，小于返回-1
int compare(string str1, string str2)
{
	if (str1.length() > str2.length()) return 1;
	else if (str1.length() < str2.length())  return -1;
	else return str1.compare(str2);
}
//高精度加法
//只能是两个正数相加
string add(string str1, string str2)//高精度加法
{
	string str;
	int len1 = str1.length();
	int len2 = str2.length();
	//前面补0，弄成长度相同
	if (len1 < len2)
	{
		for (int i = 1; i <= len2 - len1; i++)
			str1 = "0" + str1;
	}
	else
	{
		for (int i = 1; i <= len1 - len2; i++)
			str2 = "0" + str2;
	}
	len1 = str1.length();
	int cf = 0;
	int temp;
	for (int i = len1 - 1; i >= 0; i--)
	{
		temp = str1[i] - '0' + str2[i] - '0' + cf;
		cf = temp / 10;
		temp %= 10;
		str = char(temp + '0') + str;
	}
	if (cf != 0)  str = char(cf + '0') + str;
	return str;
}
//高精度减法
//只能是两个正数相减，而且要大减小
string sub(string str1, string str2)//高精度减法
{
	string str;
	if (compare(str1, str2) == -1)
	{
		return "ERROR";
	}
	int tmp = str1.length() - str2.length();
	int cf = 0;
	for (int i = str2.length() - 1; i >= 0; i--)
	{
		if (str1[tmp + i] < str2[i] + cf)
		{
			str = char(str1[tmp + i] - str2[i] - cf + '0' + 10) + str;
			cf = 1;
		}
		else
		{
			str = char(str1[tmp + i] - str2[i] - cf + '0') + str;
			cf = 0;
		}
	}
	for (int i = tmp - 1; i >= 0; i--)
	{
		if (str1[i] - cf >= '0')
		{
			str = char(str1[i] - cf) + str;
			cf = 0;
		}
		else
		{
			str = char(str1[i] - cf + 10) + str;
			cf = 1;
		}
	}
	str.erase(0, str.find_first_not_of('0'));//去除结果中多余的前导0
	if (str.empty())
		str = "0";
	return str;
}
//高精度乘法
//只能是两个正数相乘
string mul(string str1, string str2)
{
	string str;
	int len1 = str1.length();
	int len2 = str2.length();
	string tempstr;
	for (int i = len2 - 1; i >= 0; i--)
	{
		tempstr = "";
		int temp = str2[i] - '0';
		int t = 0;
		int cf = 0;
		if (temp != 0)
		{
			for (int j = 1; j <= len2 - 1 - i; j++)
				tempstr += "0";
			for (int j = len1 - 1; j >= 0; j--)
			{
				t = (temp * (str1[j] - '0') + cf) % 10;
				cf = (temp * (str1[j] - '0') + cf) / 10;
				tempstr = char(t + '0') + tempstr;
			}
			if (cf != 0) tempstr = char(cf + '0') + tempstr;
		}
		str = add(str, tempstr);
	}
	str.erase(0, str.find_first_not_of('0'));
	if (str.empty())
		str = "0";
	return str;
}

//高精度除法
//两个正数相除，商为quotient,余数为residue
//需要高精度减法和乘法
void div(string str1, string str2, string& quotient, string& residue)
{
	quotient = residue = "";//清空
	if (str2 == "0")//判断除数是否为0
	{
		quotient = residue = "ERROR";
		return;
	}
	if (str1 == "0")//判断被除数是否为0
	{
		quotient = residue = "0";
		return;
	}
	int res = compare(str1, str2);
	if (res < 0)
	{
		quotient = "0";
		residue = str1;
		return;
	}
	else if (res == 0)
	{
		quotient = "1";
		residue = "0";
		return;
	}
	else
	{
		int len1 = str1.length();
		int len2 = str2.length();
		string tempstr;
		tempstr.append(str1, 0, len2 - 1);
		for (int i = len2 - 1; i < len1; i++)
		{
			tempstr = tempstr + str1[i];
			tempstr.erase(0, tempstr.find_first_not_of('0'));
			if (tempstr.empty())
				tempstr = "0";
			for (char ch = '9'; ch >= '0'; ch--)//试商
			{
				string str, tmp;
				str = str + ch;
				tmp = mul(str2, str);
				if (compare(tmp, tempstr) <= 0)//试商成功
				{
					quotient = quotient + ch;
					tempstr = sub(tempstr, tmp);
					break;
				}
			}
		}
		residue = tempstr;
	}
	quotient.erase(0, quotient.find_first_not_of('0'));
	if (quotient.empty()) quotient = "0";
}

int main()
{
	string str1, str2;
	string str3, str4;
	while (cin >> str1 >> str2)
	{
		cout << add(str1, str2) << endl;
		cout << sub(str1, str2) << endl;
		cout << mul(str1, str2) << endl;
		div(str1, str2, str3, str4);
		cout << str3 << "  " << str4 << endl;
	}
	return 0;
}