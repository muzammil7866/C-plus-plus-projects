#include <iostream>
using namespace std;
class Matrix
{
//	//members
int rows;
int cols;
int** mat; //double pointer
//
public:
//	//inputs elements in array
void setmat()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "ENTER YOUR VALUE AT INDEX [" << i << "][" << j << "]: ";
			cin >> mat[i][j];
//
		}
	}
}
//
//	//prints the 2D matrix
void getmat()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << mat[i][j]<<" ";
//
		}
		cout << endl;
	}
}
//
//	//constructor
//	Matrix()
{
	rows = 3;
	cols = 3;
//
//		//allocates memory from heap to the matrix
	mat = new int* [rows];
	{
		for (int i = 0; i < rows; i++)
		{
			mat[i] = new int[cols];
		}
	}
}
//
//	//getter of rows
int getrows()
{
	return rows;
}
//
//	//getter of columns
int getcols()
{
	return cols;
}
//
//	//+ operator overloading
//	Matrix operator +(Matrix a) //Matrix object as parameter
		{
//		
		Matrix c; //local variable declared
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					c.mat[i][j] = mat[i][j] + a.mat[i][j]; //adds the matrix element of the object through which it is called into the object which is passed
				}
				cout << endl;
			}
			return c; //returns object of matrix type
		}
//
//	//- operator overloading
//	Matrix operator -(Matrix a) //Matrix object as parameter
		{
//		
		Matrix c; //temporary object declared
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			c.mat[i][j] = mat[i][j] - a.mat[i][j]; //subtracts the matrix element of the passed object from the object through which it is called 
		}
		cout << endl;
	}
	return c;
}
//			
};
int main()
{
//	//declares, initialises and prints the elements of matrix
Matrix obj;
cout << "**********ELEMENTS OF MATRIX 1**********"<<endl;
//	obj.setmat();
//	obj.getmat();
//
//	//declares, initialises and prints the elements of matrix
Matrix obj2;
cout << "**********ELEMENTS OF MATRIX 2**********" << endl;
//	obj2.setmat();
//	obj2.getmat();
//
//	//char variable declared to perform the respective operation
char opr;
cout << "CHOOSE YOUR OPERATOR: ";
cin >> opr;
//
//	//resultant matrix object declared
Matrix c;
//
//
switch (opr)
{
case '+':
	c = obj + obj2; //+ operator function is called from here
	break;
//
case '-':
	c = obj - obj2; //- operator function is called from here
	break;
//
default:
	cout << "INVALID OPERATOR! " << endl; //incase of any other operator
}
//
cout << "**********ELEMENTS OF THE FINAL MATRIX**********" << endl;
//	c.getmat(); //prints the resultant matrix
//
return 0;
}
