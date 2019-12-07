#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>


void main()
{
	using namespace std;

	const int ROWS = 4;
	const int COLS = 4;
	int arr[ROWS][COLS];

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = i*10+j;
		}
	}
	cout << "Star matrix:\n";

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}

		cout << endl;
	}

	cout << "End matrix:\n";

	bool left_to_right = false;
	for (int i = ROWS-1; i >= 0; i--)
	{
		if (left_to_right)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << arr[i][j] << "\t";
			}
		}
		else
		{
			for (int j = COLS-1; j >=0; j--)
			{
				cout << arr[i][j] << "\t";
			}
		}

		cout << endl;
		left_to_right = !left_to_right;
	}

	//for (int i = 3; i >=0; i--)
	//{
	//	for (int j = 3; j >= 0; j--)
	//	{
	//		cout << arr[i][j] << "\t";
	//	}

	//	cout << endl;
	//}
	
	//cout << arr[3][3] << "\t" << arr[3][2] << "\t" << arr[3][1] << "\t" << arr[3][0] << "\n"
	//	 << arr[2][0] << "\t" << arr[2][1] << "\t" << arr[2][2] << "\t" << arr[2][3] << "\n"
	//	 << arr[1][3] << "\t" << arr[1][2] << "\t" << arr[1][1] << "\t" << arr[1][0] << "\n"
	//	 << arr[0][0] << "\t" << arr[0][1] << "\t" << arr[0][2] << "\t" << arr[0][3] << "\n";
		
}
