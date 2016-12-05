#include <iostream>
#include <string>

using namespace std;

//���������������
void getChar(char** b, string str,int i,int j)
{
	if (i == 0 && j == 0)
	{
		return;
	}
	if (b[i][j] == 's')//�����S��˵���ǹ���Ԫ��
	{
		getChar(b, str, i - 1, j - 1);
		cout << str[i-1];
	}
	else
	{
		if (b[i][j] == 'u')//���
		{
			getChar(b, str, i - 1, j);
		}
		else
		{
			getChar(b, str, i, j - 1);
		}
	}
}

void LCS(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();
	int c[100][100] = { { 0, 0 } };//����������0��1���Էֱ��Ƿ�����ַ��Ƿ��ǹ�����
	
	char **b = new char*[(m+1)*(n+1)];//��������������һ��������ﵽ��
	for (int i = 0; i < m+1; i++)
	{
		b[i] = new char[n+1];
		for (int j = 0; j < n+1; j++)
		{
			b[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (str1[i-1] == str2[j-1])//�����ȣ���һ��������־��Ϊs
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 's';
			}
			else
			{
				if (c[i - 1][j] >= c[i][j - 1])//���
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = 'u';
				}
				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = 'l';
				}
			}
		}
	}
	getChar(b, str1, m, n);
}

int main()
{
	LCS("ahkjglkjavjhbubniuk", "tdhjgjamsygjkllhfygui");
	system("pause");
	return 0;
}