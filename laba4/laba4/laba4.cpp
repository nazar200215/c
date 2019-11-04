#include <stdio.h>
#include <math.h>

int arr[] = { 1, -2, 3, -4, 5, -6, 7, -8, 9 ,-10, 11, -12, 13, -14, 15, -16, 17, -18, 19, -20 };//чередующийся
//int arr[] = { -1, 1, -2, 3, -4, 5, -6, 7, -8, 9 ,-10, 11, -12, 13, -14, 15, -16, 17, -18, 19, -20 };//чередующийся
//int arr[] = { -1, 1, -2, 3, -4, 5, -6, 7, -8, 9 ,-10, 11, -12, 13, -14, 15, -16, 17, -18, 19, 20 };//нечередующийся
//int arr[] = { -1, -2, 3, -4, 5, -6, -7, -8, 9 ,-10, 11, -12, 13, -14, 15, -16, 17, -18, 19, -20 };// нечередующийчя

int length = sizeof(arr) / sizeof(int);

void print_all() {
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}

void print_minus() {
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0)
			printf("%d ", arr[i]);
	}
}

int main()
{
	bool chereduyuschiysia = true;
	int prev_sign;
	for (int i = 1; i < length; i++)
	{
		prev_sign = arr[i-1] > 0 ? 1 : -1;
		int curent_sign = arr[i] > 0 ? 1 : -1;
		if (prev_sign == curent_sign)
		{
			chereduyuschiysia = false;
			break;
		}
		else
			prev_sign = curent_sign;
	}

	if (chereduyuschiysia)
		print_all();
	else
		print_minus();
	
}