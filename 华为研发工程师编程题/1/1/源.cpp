/*������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�

�������� :

�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1 <= n <= 100������ʾС�����ϵĿ���ˮƿ����n = 0��ʾ�����������ĳ���Ӧ��������һ�С�

������� :

����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��

��������1 :

3
10
81
0

�������1 :

	1
	5
	40
	*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int Drink_num(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	int drinked = n/3;

	int each_drink = n / 3;
	int each_last = each_drink + n % 3;
	while (each_last > 2)
	{
		int new_drink = each_last / 3;
		drinked += new_drink;
		each_last = new_drink + each_last%3;
	}

	if (each_last == 1)
		return drinked;
	else
		return drinked + 1;

	return 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		int res = Drink_num(n);
		cout << res << endl;
	}
	return 0;
}