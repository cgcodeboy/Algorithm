#include <iostream>

using namespace std;

double myFunc(double t)
{
	return 2*t*t*t+4*t*t+3*t;
}

double binaryFun(double a,double b,double err)
{
	double c = (a+b)/2.0;
	while(abs(myFunc(c))>err)
	{
		if(myFunc(c)*myFunc(b)<0)
		{
			a = c;
		}
		if(myFunc(a)*myFunc(c)<0)
		{
			b = c;
		}
		c = (a+b)/2;
	}
	return c;
}

int main()
{
	cout.precision(10);
	cout<<binaryFun(-0.5,0.3,1e-5);
	system("pause");
	return 0;
}