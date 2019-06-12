#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		int len = str.size();
		vector<int> res(53, 0);
		string s;

		for (int i = 0; i < len; ++i)
		{
			char ch = str[i];
			int index;
			if (ch >= 'A'&&ch <= 'Z')
				index = (int)ch - 64;//int强制转型
			else
				index = (int)ch - 70;

			if (res[index] == 0)
			{
				res[index] = 1;
				s.push_back(ch);//刚发现就放进s，这样可以保持原有顺序！！
			}
		}
		cout << s << endl;
	}
	return 0;
}