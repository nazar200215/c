#include <iostream>

int main()
{
	double x_k, x_prev = 1;
	while (true)
	{
		x_k = (2 - pow(x_prev, 3)) / 5;
		if (abs(x_k-x_prev)<1e-5)
		{
			break;
		}
		x_prev = x_k;
	}
	std::cout << "x_prev=" << x_prev << " x_k="<< x_k << " x_k-x_prev = " << x_k-x_prev;
}

