#include <iostream>
#include <math.h>
int main()
{
	int n = 1;
	double a_k, a_prev = 0.01;
	for (int k = 2; k <= 64; k*=2)
	{
		a_k = sin(k+a_prev);
		if (a_k < 0.75)
		{
			n++;
		}
		a_prev = a_k;
	}
	std::cout << "n=" << n;
}

