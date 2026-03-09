#include <iostream>
using namespace std;
int main()
{
//	int rows, cols;
cout << "Enter your number of rows of array: ";
cin >> rows;
cout << "Enter your number of columns of array: ";
cin >> cols;
int** array = new int* [rows]; //dynamically allocates the rows of 2D array
for (int i = 0; i < rows; i++)
{
	array[i] = new int[cols+1]; //dynamically allocates columns of the respective rows index
}
//
//	//takes input into the array
for (int i = 0; i < rows; i++) //deals with rows
{
	for (int j = 0; j < i; j++) //deals with columns
	{
		cout << "Enter the element of array at index [" << i << "][" << j << "]: ";
		cin >> array[i][j];
	}
	cout << endl;
}
//
//	//prints the array
for (int i = 0; i < rows; i++) //deals with rows
{
	for (int j = 0; j < i; j++) //deals with columns
	{
		cout <<array[i][j]<<" ";
	}
	cout << endl;
}
//
//
return 0;
}
