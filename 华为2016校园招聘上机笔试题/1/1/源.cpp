/*
��ʦ��֪����ĳĳͬѧ���У�������ߵ��Ƕ��٣�����������ģ����ʦ��ѯ�ʡ���Ȼ����ʦ��ʱ����Ҫ����ĳλͬѧ�ĳɼ�.

��������:

�����������������ݡ�
ÿ�������һ��������������N��M��0 < N <= 30000,0 < M < 5000��,�ֱ����ѧ������Ŀ�Ͳ�������Ŀ��
ѧ��ID��Ŵ�1�ൽN��
�ڶ��а���N��������������N��ѧ���ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ�
��������M�У�ÿһ����һ���ַ�C��ֻȡ��Q����U������������������A,B,��CΪ'Q'��ʱ��, ��ʾ����һ��ѯ�ʲ�������ѯ��ID��A��B������A,B����ѧ�����У��ɼ���ߵ��Ƕ���
��CΪ��U����ʱ�򣬱�ʾ����һ�����²�����Ҫ���IDΪA��ѧ���ĳɼ�����ΪB��

�������:

����ÿһ��ѯ�ʲ�������һ�����������߳ɼ�.

��������1:

5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

�������1:

5
6
5
9
*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int max_index(vector<int> num,int Start, int End)
{
	int Max = Start;
	for (int i = Start + 1; i <= End; ++i)
	{
		if (num[i] > num[Max])
			Max = i;
	}
	return Max;
}

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<int> num(N+1,0);
		for (int i = 1; i <= N; ++i)
			cin >> num[i];

		//int last_max_index = 1;
		//int now_max_max_index = max_index(num, 1, N);
		char str;
		for (int j = 1; j <= M; ++j)
		{
			cin >> str;
			if (str == 'Q')
			{
				int a, b;
				cin >> a >> b;
				if (a > b)////Start��End��Ȼ����һ��˭�󣿣���
					cout << num[max_index(num, b, a)] << endl;
				else
					cout << num[max_index(num, a, b)] << endl;
			}
			else
			{
				int index, new_value;
				cin >> index >> new_value;
				num[index] = new_value;
			}
		}
	}
	return 0;
}