/*д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����������ͬʱ���� ��

�������� :

����һ��ʮ�����Ƶ���ֵ�ַ�����

������� :

�������ֵ��ʮ�����ַ�����

��������1 :

0xA

�������1 :

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