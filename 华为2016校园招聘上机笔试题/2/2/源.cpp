/*����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
���� :
1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)ֻ��¼һ��������������ӣ�(�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���(����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��

�������� :

һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������

�ļ�·��Ϊwindows��ʽ

�磺E : \V1R2\product\fpgadrive.c 1325

	�������:

�����еļ�¼ͳ�Ʋ�������������ʽ���ļ�������������Ŀ��һ���ո��������: fpgadrive.c 1325 1

	���������Ŀ�Ӷൽ��������Ŀ��ͬ������£����������һ�γ���˳������

	�������8����¼����ֻ���ǰ8����¼.

	����ļ����ĳ��ȳ���16���ַ�����ֻ�����16���ַ�

	��������1 :

								  E:\V1R2\product\fpgadrive.c 1325

									  �������1:

									fpgadrive.c 1325 1
									*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

int main()//�е�������һ�ξ�Ҫ�ó�һ�������Ȼ���Զ�������������� �е�������һ��δ֪�������ݲŵó�һ�������һ��mainһ������� �е�������һ����֪�������ݲŵõ�һ�������Ȼ���Զ����������������������Ȼ�������ڵڶ������
{
	vector<pair<string, int>> errors;//��map�������ã�map���˳��
	string input;
	while (getline(cin, input))
	{
		if (input.empty())//���䣡��
			break;

		string file=input.substr(input.rfind('\\')+1);//���䷴б�ܣ����ʹ��rfind
		//string file_name = file.substr(0, file.find(' '));
		//string file_row = file.substr(file.find(' ') + 1);

		pair<string, int> temp = make_pair(file, 1);
		//vector<pair<string, int>>::iterator iter;
		//iter = find(errors.begin(), errors.end(), temp);//find��ȫƥ�䣬��̫��Ū
		errors.push_back(temp);
		for (int i = 0; i < errors.size() - 1; ++i)//�����������ʽ������ƥ����������
		{
			if (errors[i].first == errors[errors.size() - 1].first)
			{
				errors[i].second += 1;
				errors.pop_back();
				break;
			}
		}
	}

	stable_sort(errors.begin(), errors.end(), compare);//�������Ԫ��˳�������

	int idx = 0;
	while (idx < 8 && idx < errors.size())
	{
		string temp = errors[idx].first;
		int t = temp.find(' ');
		if (t > 16)
			//errors[idx].first = errors[idx].first.substr(0, 16);Ҫ�õ��м���ַ��������������Ҫ��
			errors[idx].first.erase(0, t - 16);//string�����±�����������  //����ĺ�ϸ��
		cout << errors[idx].first << " " << errors[idx].second << endl;
		idx++;
	}

	return 0;
}
