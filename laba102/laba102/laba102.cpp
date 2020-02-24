#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
using namespace std;

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

//створюємо перший масив
void FillArray1(int arr1[], int size1)
{	
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = rand() % 100 -50;
	}
}
//виводимо перший масив
void PrintArray1(int arr1[], int size1)
{
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}
}
//створюємо другий масив
void FillArray2(int arr2[], int size2)
{
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = rand() % 100 - 50;
	}
}
//виводимо другий масив
void PrintArray2(int arr2[], int size2)
{
	for (int i = 0; i < size2; i++)
	{
		cout << arr2[i] << " ";
	}
}
//пошук максимуму в першому масиві та мінімуму в другому
void MinMaxFinder(int arr1[], int size1, int arr2[], int size2, int *pmax, int *pmin)
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
	cout << endl << "Min element of Array 2: " << *pmin << endl;
}

//обчислення суми
float SumZ(float max, float min)
{
	return (max - min) / 2;
}

int main()
{
	srand(time(NULL));
	int SIZE1 = 0;
	cout << "SIZE OF ARR1: " << endl;
	cin >> SIZE1;
	int* ARR1 = new int[SIZE1];
	cout << "Array 1: ";
	FillArray1(ARR1, SIZE1);
	PrintArray1(ARR1, SIZE1);
	cout << endl;

	int SIZE2 = 0;
	cout << endl << "SIZE OF ARR2: " << endl;
	cin >> SIZE2;
	int* ARR2 = new int[SIZE2];
	cout << "Array 2: ";
	FillArray2(ARR2, SIZE2);
	PrintArray2(ARR2, SIZE2);
	cout << "\n ~~~~~~~~~~~~~~~~~~~~ \n ~~~~~~~~~~~~~~~~~~~~";
	int MAX = -1e10; int MIN = 1e10;
	MinMaxFinder(ARR1, SIZE1, ARR2, SIZE2, &MAX, &MIN);
	
	SetColor(5, 0);
	cout << endl <<"RESULT = "<< SumZ(MAX, MIN) << endl;
	delete[] ARR1;
	delete[] ARR2;
	SetColor(0, 0);
	system("pause");
}
