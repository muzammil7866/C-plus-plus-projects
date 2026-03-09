#include<iostream>
#include"Matrix.h"
using namespace std;

void Matrix:: setRandC(int a, int b)
{
	rows = a;
	cols = b;
}

void Matrix::setMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "ENTER ELEMENT: ";
			cin >> matrix[i][j];
		}
	}
}

void Matrix::operator -()
{
	Matrix temp;


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp.matrix[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = temp.matrix[j][i];
		}
	}

}

void Matrix::displayMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}