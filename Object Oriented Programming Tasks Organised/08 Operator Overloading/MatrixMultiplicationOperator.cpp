#include <iostream>
using namespace std;
//
bool dontMultiply = false;
//
const int MAXROWS = 10;
const int MAXCOLS = 10;
//
class MATRIX
{
//
public:
	int matrix[MAXROWS][MAXCOLS];
	int rows;
	int cols;
//
void setMatrix(int a, int b)
{
	rows = a;
	cols = b;
//
	cout << "ENTER ELEMENTS OF MATRIX: \n";
//
	for (int i = 0;i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}
//
}
//
//	MATRIX operator * (MATRIX second)
{
	dontMultiply = false;
//
	if (cols != second.rows)
	{
		cout << "MATRIX CANNOT BE MULTIPLIED AS ROWS <> COLS! ";
		dontMultiply = true;
	}
//
	else
	{
		MATRIX temp;
		temp.rows = 3;
		temp.cols = 3;
//
//
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < second.cols;j++)
			{
				temp.matrix[i][j] = 0;
				for (int k = 0;k < second.rows;k++)
				{
//						temp.matrix[i][j] += matrix[i][k] * second.matrix[k][j];
				}
			}
		}
//
		return temp;
	}
	}
//
void displayMat()
{
//
	cout << "MATRIX: \t\n\n";
	for (int i = 0;i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout<< matrix[i][j]<<" ";
		}
//
		cout << endl;
	}
//
	cout << endl;
}
};
//
int main()
{
//	MATRIX obj, obj2, obj3, obj4;
//
//	obj.setMatrix(3,2);
//	obj.displayMat();
//
//	obj2.setMatrix(2, 3);
//	obj2.displayMat();
//
obj3 = obj * obj2;
//
if (dontMultiply == false)
{
	cout << "MULTIPLICATED ";
//		obj3.displayMat();
}
//
//	obj4.setMatrix(3, 1);
//
obj3 = obj * obj4;
//
//
if (dontMultiply == false)
{
	cout << "MULTIPLICATED ";
//		obj3.displayMat();
}
//
return 0;
}
