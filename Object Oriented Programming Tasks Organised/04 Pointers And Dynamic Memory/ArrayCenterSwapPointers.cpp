#include <iostream>
using namespace std;
void transpose(int array1[][10], int array2[][10], int rows1, int cols1);
int main()
{
	int rows1, cols1;
	cout << "Enter the rows of your matrix: ";
	cin >> rows1;
	cout << "Enter the columns of your matrix: ";
	cin >> cols1;

	int array1[10][10];
	int array2[10][10];
	//inputs into the array
	for (int i = 0; i < rows1; i++) //for rows increment
	{
		for (int j = 0; j < cols1; j++) //for columns increment
		{
			cout << "Enter the element of array at index [" << i << "][" << j << "]: ";
			cin >> array1[i][j];
		}
	}
	cout << endl << "ORIGINAL MATRIX: "<<endl;
	//displays the array elements
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols1; j++)
		{
			cout << array1[i][j]<<" ";
		}
		cout << endl;
	}

	transpose(array1, array2, rows1, cols1);

	//displays the transposed array
	cout << endl << "TRANSPOSE: " << endl;
	for (int i = 0; i < cols1; i++)
	{
		for (int j = 0; j < rows1; j++)
		{
			cout << array2[i][j] << " ";
		}
		cout << endl;
	}
}
//transposes the array 
void transpose(int array1[][10], int array2[][10], int rows1, int cols1)
{
	for (int i = 0; i < cols1; i++) //for rows increment
	{
		for (int j = 0; j < rows1; j++) //for columns increment
		{
			array2[i][j] = array1[j][i]; //the values of the rows of array 1 becomes the column of array 2 and the rows of array2 becomes the columns of array 1
		}
	}

}