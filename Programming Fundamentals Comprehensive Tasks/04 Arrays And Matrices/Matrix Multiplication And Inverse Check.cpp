#include <iostream>
using namespace std;
int main()
{
const int rows = 2, cols = 2;
bool inverse = false;
int A[rows][cols];
int B[rows][cols];
int C[rows][cols] = { {1,0}, {0,1} };
int D[rows][cols] = {0};
for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < cols; j++)
	{
		cout << "Enter the element of matrix A at index [" << i << "][" << j << "]: ";
		cin >> A[i][j];
	}
}
//
for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < cols; j++)
	{
		cout << "Enter the element of matrix B at index [" << i << "][" << j << "]: ";
		cin >> B[i][j];
	}
}
//
cout << "Elements of Matrix A: " << endl;
//	
for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < cols; j++)
	{
		cout << A[i][j] << " ";
	}
	cout << endl;
//
//
}
//
cout <<endl<< "Elements of Matrix B: " << endl;
for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < cols; j++)
	{
		cout << B[i][j]<< " ";
	}
	cout << endl;
}
//
cout << endl;
for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < cols; j++)
	{
		cout << C[i][j] << " ";
	}
	cout << endl;
//
//
}
//
cout << endl;
//
for (int i = 0; i < rows; ++i)
{
	for (int j = 0; j < cols; ++j)
	{
		for (int k = 0; k < cols; ++k)
		{
			D[i][j] += A[i][k] * B[k][j];
		}
//
	}
}
//	
cout << "Elements after Multicplication of A and B Matrix: " << endl;
//
for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < cols; j++)
	{
		cout << D[i][j] << " ";
	}
	cout << endl;
//
//
}
for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < cols; j++)
	{
		if (D[i][j] == C[i][j])
		{
			inverse = true;
		}
//
		else
		{
			inverse = false;
		}
	}
//
}
//
if (inverse == true)
{
	cout <<endl<< "Matrix B is an inverse of the matrix A";
}
//
else
{
	cout <<endl<< "Matrix B is not an inverse of the matrix A";
}
return 0;
}
