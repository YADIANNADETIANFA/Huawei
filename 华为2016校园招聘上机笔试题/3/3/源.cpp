/*
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������

����ʾ��
��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
��3�������˳���Ѿ�������С����������˲�����������.

��������:

���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո���4 4 4 4-joker JOKER��

�������:

����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��

��������1:

4 4 4 4-joker JOKER

�������1:

joker JOKER
*/

#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()//����ϸ�ں���Ҫ
{
	string s;
	while (getline(cin, s))
	{
		if (s.find("joker JOKER") != s.npos)
			cout << "joker JOKER" << endl;
		else if (s.find("JOKER joker") != s.npos)
			cout << "JOKER joker" << endl;
		else
		{
			int index = s.find('-');
			string str1 = s.substr(0, index);
			string str2 = s.substr(index + 1);
			int len_1 = count(str1.begin(), str1.end(), ' ');
			int len_2 = count(str2.begin(), str2.end(), ' ');
			string str = "345678910JQKA2jokerJOKER";
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));
			if (len_1 == len_2)
			{
				if (str.find(first1) > str.find(first2))
					cout << str1 << endl;
				else
					cout << str2 << endl;
			}
			else
			{
				if (len_1 == 3)
					cout << str1 << endl;
				else if (len_2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}
/*
1���ж��Ƿ������ը
2��������ը���鿴����������Ŀ
3��������������Ŀ��ȣ�������
4��������ȣ��Ƿ���ը
5������ը��error
*/