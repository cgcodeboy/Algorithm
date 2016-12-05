#include <iostream>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

void greedySelector(int n, int start[], int finish[], int accept[])
{
	accept[0] = 1;//先选择当前第一个作为最优的选择
	long j = 0;
	for (int i = 1; i < n; i++)
	{
		if (start[i] >= finish[j])//但凡是开始时间在上一个结束时间之后的都作为当前最优选择
		{
			accept[i] = 1;
			j = i;
		}
		else
		{
			accept[i] = 0;
		}
	}
}

int main()
{
	std::ofstream file("out.txt");
	
	srand(unsigned(time(0)));

	int *start = new int[100000];	
	
	int *finish = new int[100000];
	for (int i = 0; i < 100000; i++)
	{
		finish[i] = 1000+rand() % 10000;
	}
	
	sort(finish, finish + 100000);//将finish数组排序

	for (int i = 0; i < 100000; i++)
	{
		start[i] = finish[i] - rand() % 1000;
	}
		
	int *accept = new int[100000];
	greedySelector(100000, start, finish, accept);
	for (int i = 0; i < 100000; i++)
	{
		file << accept[i] << " ";
	}
		
	
	system("pause");
	return 0;
}