#include <iostream>
#define M_PI 3.1415;

using namespace std;

float myFun(float t)
{
	return sin(t);
}

float rectangleIntegration(float fun(float t), float left, float right, float eps)
{
	if (right - left < eps)
	{
		//return fun(right) *(right - left);
		//return (fun(right)+fun(left)) *(right - left)/2;
		return fun(left) *(right - left);
	}
	else
	{
		float mid = (right + left) / 2;
		return rectangleIntegration(fun, left, mid, eps) + rectangleIntegration(fun, mid, right, eps);
	}
}

int main()
{
	float result = rectangleIntegration(myFun, 0, 1.57,exp(-10));
	cout << result << endl;
	system("pause");
	return 0;
}