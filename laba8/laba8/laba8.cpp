#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

int main()
{
	using namespace std;

	const int ROWS = 4;
	const int COLS = 5;
	int arr[ROWS][COLS];
	srand(time(0));
	//initialization
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 15;
		}
	}

	// show init matrix
	cout << "Star matrix:\n";
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}

		cout << endl;
	}

	// find max
	int max_col, max_row;
	int m = -10000;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > m)
			{
				m = arr[i][j];
				max_col = j;
				max_row = i;
			}
		}
	}
	cout << "max = " << m << "; row = " << max_row << "; col = " << max_col;
	cout << "\n";


	// change rows
	for (int j = 0; j < COLS; j++)
	{
		int temp;
		temp = arr[max_row][j];
		arr[max_row][j] = arr[0][j];
		arr[0][j] = temp;
	}

	// change cols
	for (int i = 0; i < ROWS; i++)
	{
		int temp;
		temp = arr[i][max_col];
		arr[i][max_col] = arr[i][0];
		arr[i][0] = temp;
	}

	// show result matrix
	cout << "Result matrix:\n";
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}

		cout << endl;
	}

}	

