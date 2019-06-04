/*写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）

输入描述 :

输入一个十六进制的数值字符串。

输出描述 :

输出该数值的十进制字符串。

输入例子1 :

0xA

输出例子1 :

	10
	*/
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int val = 0;
		int len = s.size();
		for (int i = 2; i < len; ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
				val += (s[i]-'0') * pow(16, (len - 2) - (i - 1));
			else
				val += (s[i]-'A'+10) * pow(16, (len - 2) - (i - 1));
		}
		cout << val << endl;
	}
	return 0;
}