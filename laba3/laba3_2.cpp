#include <stdio.h>
#include <math.h>
#include <windows.h>


float S_toch(float x)
{
	return pow((1 + x), -0.5);
}

float S_NeToch(float x, float s_toch, float eps)
{
	float e;
	float res = 1;
	float temp = 0, a = 1, b = 2, k = 1;
	int n = 1;
	int sign = -1;
	while (true)
	{
		k *= a / b;
		temp = sign * (k * pow(x, n));
		res += temp;

		e = fabs(res - s_toch);
		if (e < eps)
		{
			printf("S2=%.8lf eps=%.10lf e=%.10lf n=%d\n", res, eps, e, n);
			break;
		}
		a += 2;
		b += 2;
		sign *= -1;
		n += 1;
	}
	return res;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	double X, E1, E2, S1, S2, S3; 
	printf("¬вед≥ть x: ");
	scanf_s("%lf", &X);
	printf("¬вед≥ть E1: ");
	scanf_s("%lf", &E1);
	printf("¬вед≥ть E2: ");
	scanf_s("%lf", &E2);
	S1 = S_toch(X);
	printf("S1=%.10lf\n", S1);
	S2 = S_NeToch(X, S1, E1);
	S3 = S_NeToch(X, S1, E2);
}
