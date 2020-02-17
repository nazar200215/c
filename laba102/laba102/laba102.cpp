#include <iostream>
#include <ctime>
using namespace std;

//створюємо перший масив
void FillArray1(float arr1[], float size1)
{
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = rand() % 100 -50;
	}
}
//виводимо перший масив
void PrintArray1(float arr1[], float size1)
{
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}
}
//створюємо другий масив
void FillArray2(float arr2[], float size2)
{
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = rand() % 100 - 50;
	}
}
//виводимо другий масив
void PrintArray2(float arr2[], float size2)
{
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i] << " ";
	}
}
//пошук максимуму в першому масиві та мінімуму в другому
void MinMaxFinder(float arr1[], float size1, float arr2[], float size2, float *pmax, float *pmin)
{
	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] > *pmax)
		{
			*pmax = arr1[i];
		}
	}
	cout << endl << "Max element of Array 1: " << *pmax;

	for (int i = 0; i < size2; i++)
	{
		if (arr2[i] < *pmin)
		{
			*pmin = arr2[i];
		}
	}
	cout << endl << "Min element of Array 2: " << *pmin;
}

//обчислення суми
float SumZ(float max, float min)
{
	return (max - min) / 2;
}

float main()
{
	srand(time(NULL));
	const int SIZE1 = 10;
	float ARR1[SIZE1];
	cout << "Array 1: ";
	FillArray1(ARR1, SIZE1);
	PrintArray1(ARR1, SIZE1);

	const int SIZE2 = 12;
	float ARR2[SIZE2];
	cout << endl << "Array 2: ";
	FillArray2(ARR2, SIZE2);
	PrintArray2(ARR2, SIZE2);

	float MAX = -1e10; float MIN = 1e10;
	MinMaxFinder(ARR1, SIZE1, ARR2, SIZE2, &MAX, &MIN);
	

	cout << endl <<"Z = "<< SumZ(MAX, MIN);

}
