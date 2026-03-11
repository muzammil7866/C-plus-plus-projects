#include <iostream>
using namespace std;
int main()
{
	int rows, cols=0;

	cout << "\t\tENTER THE NUMBER OF ROWS TO DYNAMICALLY ALLOCATE A PATTERENED MATRIX: ";
	cout << endl << endl;
	cout << "Enter your number of rows of array: ";
	cin >> rows;
	int** array = new int* [rows]; //dynamically allocates the rows of 2D array
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols+1]; //dynamically allocates columns of the respective rows index
	}

	//takes input into the array
	for (int i = 0; i < rows; i++) //deals with rows
	{
		for (int j = 0; j < i+1; j++) //deals with columns
		{
			cout << "Enter the element of array at index [" << i << "][" << j << "]: ";
			cin >> array[i][j];
		}
		cout << endl;
	}

	//prints the array
	for (int i = 0; i < rows; i++) //deals with rows
	{
		for (int j = 0; j < i+1; j++) //deals with columns
		{
			cout <<array[i][j]<<" ";
		}
		cout << endl;
	}


	return 0;
}
