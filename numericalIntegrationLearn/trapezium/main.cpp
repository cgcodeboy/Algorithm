#include <iostream>
#define M_PI 3.1415;

using namespace std;

float myFun(float t)
{
	return sin(t);
}

float trapeziumIntegration(float fun(float t), float left, float right, float eps)
{
	if (right - left < eps)
	{
		return (fun(left) + fun(right))*(right - left) / 2;
	}
	else
	{
		float mid = (right + left) / 2;
		return trapeziumIntegration(fun, left, mid, eps) + trapeziumIntegration(fun, mid, right, eps);
	}
}

int main()
{
	float result = trapeziumIntegration(myFun, 0, 1.57, exp(-10));
	cout << result << endl;
	system("pause");
	return 0;
}