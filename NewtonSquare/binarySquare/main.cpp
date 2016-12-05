#include <iostream>

using namespace std;

double binarySquare(double x,double n)
{
	double t = x / 2,right = x,left = 0;
	int i = 0;
	while (i < n)
	{
		if (t*t < x)
		{
			left = t;
			t = (t + right) / 2;			
			i++;
		}
		else
		{
			right = t;
			t = (left + t) / 2;		
			i++;
		}
	}
	return t;
}

int main()
{
	for (long i = 0; i < 100000000; i++)
	{
		binarySquare(i,20);
	}
	cout << "out";
	system("pause");
	return 0;
}