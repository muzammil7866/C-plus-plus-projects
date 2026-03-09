#include <iostream>
using namespace std;
void multiply(int array1[][10], int array2[][10], int row1, int row2, int cols1, int cols2); 
int main()
{
//	int rows1, rows2, cols1, cols2;
cout << "Enter the rows of array 1: ";
cin >> rows1;
cout << "Enter the cols of array 1: ";
cin >> cols1;
cout << "Enter the rows of array 2: ";
cin >> rows2;
cout << "Enter the cols of array 2: ";
cin >> cols2;
//
int array1[10][10];
int array2[10][10];
if (cols1 != rows2) //checks if the columns of array1 and rows of array2 are not same
	cout << "Multiplication is not possible with these orders of matrices";
//	
else
{
//		multiply(array1, array2, rows1, rows2, cols1, cols2); //passes array to the function
//
}
return 0;
}
//
void multiply(int array1[][10], int array2[][10], int rows1, int rows2, int cols1, int cols2) //function header
{
//
//	//takes input in array 1
for (int i = 0; i < rows1; i++) //for accessing rows
{
	for (int j = 0; j < cols1;j++) //for accessing columns
	{
		cout << "Enter the element of array 1 at index [" << i << "][" << j << "]: ";
		cin >> array1[i][j];
	}
}
//
cout << endl;
//	
//	//outputs array 1 elements
for (int i = 0; i < rows1; i++) //for accessing rows
{
	for (int j = 0; j < cols1;j++) //for accessing columns
	{
		cout <<array1[i][j]<<" ";
	}
	cout << endl;
}
//
//	//takes input in array 1
for (int i = 0; i < rows2; i++) //for accessing rows
{
	for (int j = 0; j < cols2;j++) //for accessing columns
	{
		cout << "Enter the element of array 1 at index [" << i << " ][" << j << "]: ";
		cin >> array2[i][j];
	}
}
//
//	//outputs array 2 elements
for (int i = 0; i < rows2; i++) //for accessing rows
{
	for (int j = 0; j < cols2;j++) //for accessing columns
	{
		cout << array2[i][j] << " ";
	}
	cout << endl;
}
//
int array3[10][10];
//
//
for (int i = 0; i < rows1; i++) //for accessing rows
{
	for (int j = 0; j < cols2; j++) //for accessing columns
	{
		array3[i][j] = 0;
		for (int k=0; k<cols1;k++)
		{
			array3[i][j] = array3[i][j] + array1[i][k] * array2[k][j]; //main multiplication algorithm
		}
	}
//
}
//
cout << "Elements of the multiplicated array are: ";
//
//	//outputs array 3 elements
//
for (int i = 0; i < rows1; i++) //for accessing rows
{
	for (int j = 0; j < cols2; j++) //for accessing columns
	{
		cout << array3[i][j]<<" ";
	}
	cout << endl;
}
}
