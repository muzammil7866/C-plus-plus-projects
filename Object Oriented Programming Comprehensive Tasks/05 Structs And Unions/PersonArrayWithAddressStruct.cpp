#include <iostream>
using namespace std;
int main()
{
int rows, cols;
cout << "Enter your number of rows of array: ";
cin >> rows;
cout<< "Enter your number of columns of array: ";
cin >> cols;
int** array = new int* [rows]; //dynamically allocates the rows of 2D array
for (int i = 0; i < rows; i++)
{
	array[i] = new int[cols]; //dynamically allocates columns of the respective rows index
}
//
//	//prints out the array
for (int i = 0; i < rows; i++) //deals with rows
{
	for (int j = 0; j < cols; j++) //deals with columns
	{
		cout << "Enter the element of array at index [" << i << "][" << j << "]: ";
		cin >> array[i][j];
	}
	cout << endl;
}
//
int sum = 0; //declares and initialises the sum variable
//
for (int i = 0; i < rows; i++) //deals with rows
{
	for (int j = 0; j < cols; j++) //deals with columns
	{
//			sum += array[i][j]; //sums each element in the loop one after another
	}
}
//
cout << "The sum of array is: " << sum; //displays the sum
//
return 0;
}
