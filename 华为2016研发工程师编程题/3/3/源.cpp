#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

bool is_right(vector<vector<int>> &matrix, int row, int col, int val)//解数独重要的是该行、列、块中目前不存在与该值重复的数，费劲去查询1~9是否有重复，是傻逼的行为！
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

	int tm = row / 3;//经典！！！！！
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
bool solve(vector<vector<int>> &matrix)//经典！
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
int main()//C++处理多组输入的方法！   //经典数独   数独没有斜着不重复的要求！！！   
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
			i = 0;//给下次的测试用例初始化
			//开始正式的操作
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