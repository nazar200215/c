#include <stdio.h>
#include <math.h>

double S_toch(double x)
{
	return pow((1 + x), -0.5);
}
double S_NeToch(double x, double S_toch,double eps1, double eps2);
int main()
{
	double x = 0.4;
	double eps1 = 0.01, eps2 = 0.0001;
	double e;
	double S1 = S_toch(x);
	double S2 = 1, temp = 0, a = 1, b = 2, k=1;
	int n = 1;
	int sign = -1;
	printf("S1=%f\n", S1);
	while (true)
	
		k *= a / b;
		temp = sign*(k * pow(x, n));
		S2 += temp;

		e = fabs(S2 - S1);
		if (e < eps1) 
		{
			printf("S2=%f eps1=%f e=%f n=%d\n", S2, eps1, e, n);
			eps1 = 0;
		}
		if (e < eps2)
		{
			printf("S2=%f eps2=%f e=%f n=%d\n", S2, eps2, e, n);
			eps2 = 0;
			
		}
		a += 2;
		b += 2;
		sign *= -1;
		n += 1;
	}
return 0;
}