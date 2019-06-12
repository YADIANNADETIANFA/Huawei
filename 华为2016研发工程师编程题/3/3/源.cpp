#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

bool is_right(vector<vector<int>> &matrix, int row, int col, int val)//��������Ҫ���Ǹ��С��С�����Ŀǰ���������ֵ�ظ��������Ѿ�ȥ��ѯ1~9�Ƿ����ظ�����ɵ�Ƶ���Ϊ��
{
	int m = 0;
	while (m<9)
	{
		if (matrix[m++][col] == val)
			return false;
	}
	int n = 0;
	while (n < 9)
	{
		if (matrix[row][n++] == val)
			return false;
	}

	int tm = row / 3;//���䣡��������
	int tn = col / 3;
	int mbegin = tm * 3;
	int nbegin = tn * 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (matrix[mbegin + i][nbegin + j] == val)
				return false;
		}
	}
	return true;
}
bool solve(vector<vector<int>> &matrix)//���䣡
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (matrix[i][j] == 0)
			{
				for (int val = 1; val <= 9; ++val)
				{
					if (is_right(matrix, i, j, val))
					{
						matrix[i][j] = val;
						if (solve(matrix))
							return true;
						else
							matrix[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}
int main()//C++�����������ķ�����   //��������   ����û��б�Ų��ظ���Ҫ�󣡣���   
{
	string line, str;
	vector<vector<int>> matrix(9, vector<int>(9, 0));
	int i = 0;
	while (getline(cin, line))
	{
		int j = 0;
		istringstream stream(line);
		while (stream >> str)
		{
			matrix[i][j] = stoi(str);
			j++;
		}
		if (i < 8)
		{
			i++;
			continue;
		}
		else
		{
			i = 0;//���´εĲ���������ʼ��
			//��ʼ��ʽ�Ĳ���
			solve(matrix);
			for (int m = 0; m < 9; ++m)
			{
				for (int n = 0; n < 9; ++n)
				{
					cout << matrix[m][n] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}