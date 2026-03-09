#include <iostream>
using namespace std;
int main()
{
	const int row1=2, row2=2, col1=2, col2=2;
	int A[row1][col1], B[row2][col2], C[row1][col2]={{0,0},{0,0}}, sum = 0;

	if (col1 == row2)
	{
		for (int i = 0;i < row1;i++)
		{
			for (int j = 0; j < col1; j++)
			{
				cout << "Enter the element of Array A at index[" << i << "][" << j << "]: ";
				cin >> A[i][j];
			}
		}

		for (int i = 0;i < row2; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				cout << "Enter the element of Array B at index[" << i << "][" << j << "]: ";
				cin >> B[i][j];
			}
		}

		for (int i = 0;i < row1; i++)
		{	
			for (int j = 0; j < col1; j++)
			{
				sum = 0;
				for (int k = 0; k < col1; k++)
				{
					

					C[i][j] += (A[i][k] * B[k][j]);
					
				}
				
			}

			
		}

		for (int i = 0;i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				cout << C[i][j]<< " ";
			}
			cout << endl;
		}

	}


	else
	{
		cout << "multiplication is not possible";
	}




	system("pause");
	return 0;
}