#include <iostream>

using namespace std;

double seriesorMultinomial_PI(int seriesor)
{
	double PI = 2,temp = 2;
	int m = 3,n=1,i = 0;
	while(i<seriesor)
	{
		temp = temp * n/m;
		PI+=temp;
		n++;
		m+=2;
		i++;
	}
	return PI;
}

int main()
{
	cout.precision(15);
	cout<<seriesorMultinomial_PI(100)<<endl;
	system("pause");
	return 0;
}