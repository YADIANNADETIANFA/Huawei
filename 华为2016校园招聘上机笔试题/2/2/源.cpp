/*开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理 :
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述 :

一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

文件路径为windows格式

如：E : \V1R2\product\fpgadrive.c 1325

	输出描述:

将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1

	结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

	如果超过8条记录，则只输出前8条记录.

	如果文件名的长度超过16个字符，则只输出后16个字符

	输入例子1 :

								  E:\V1R2\product\fpgadrive.c 1325

									  输出例子1:

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

int main()//有的题输入一次就要得出一个结果，然后自动连续输入输出； 有的题输入一堆未知数量内容才得出一个结果，一次main一个结果； 有的题输入一堆已知数量内容才得到一个结果，然后自动连续输入输出。。。。显然本题属于第二种情况
{
	vector<pair<string, int>> errors;//用map倒不好用，map会改顺序！
	string input;
	while (getline(cin, input))
	{
		if (input.empty())//经典！！
			break;

		string file=input.substr(input.rfind('\\')+1);//经典反斜杠，外加使用rfind
		//string file_name = file.substr(0, file.find(' '));
		//string file_row = file.substr(file.find(' ') + 1);

		pair<string, int> temp = make_pair(file, 1);
		//vector<pair<string, int>>::iterator iter;
		//iter = find(errors.begin(), errors.end(), temp);//find是全匹配，不太好弄
		errors.push_back(temp);
		for (int i = 0; i < errors.size() - 1; ++i)//所以以这个方式来进行匹配与清理工作
		{
			if (errors[i].first == errors[errors.size() - 1].first)
			{
				errors[i].second += 1;
				errors.pop_back();
				break;
			}
		}
	}

	stable_sort(errors.begin(), errors.end(), compare);//不改相等元素顺序的排序

	int idx = 0;
	while (idx < 8 && idx < errors.size())
	{
		string temp = errors[idx].first;
		int t = temp.find(' ');
		if (t > 16)
			//errors[idx].first = errors[idx].first.substr(0, 16);要裁掉中间的字符，后面的行数还要呢
			errors[idx].first.erase(0, t - 16);//string，用下标代替迭代器了  //处理的很细节
		cout << errors[idx].first << " " << errors[idx].second << endl;
		idx++;
	}

	return 0;
}
