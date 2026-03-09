#include <iostream>
using namespace std;
int main()
{
	int rows, cols;

	cout<<"Enter the number of rows: ";
	cin>>rows;
	cout<<"Enter the number of columns: ";
	cin>>cols;
	
	int array[rows][cols];
	int array2[rows][cols];	
	for(int i=0; i<rows;i++)
	{
		for(int j=0; j<cols;j++)
		{
			cout<<"Enter element at index ["<<i<<"] ["<<j<<"]: ";
			cin>>array[i][j];
		}

	}

	for(int i=0; i<rows;i++)
	{
		for(int j=0; j<cols;j++)
		{
			cout<<array[i][j]<<" ";
		}
	cout<<endl;
	}

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			array2[j][i] = array[i][j];
		}
	}
	
	cout<<endl<<endl;
	for(int i=0; i<rows;i++)
	{
		for(int j=0; j<cols;j++)
		{
			cout<<array2[i][j]<<" ";
		}
	cout<<endl;
	}

	return 0;	
}


