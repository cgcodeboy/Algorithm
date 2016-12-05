#include <iostream>

using namespace std;

double newtonSquare(double x)
{
	double result = x;
	while (fabs(result*result - x) > exp(-10))
	{
		result = 0.5*(result + x / result);
	}
	return result;
}

int main()
{
	cout << newtonSquare(10);
	system("pause");
	return 0;
}