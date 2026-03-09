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
	
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout<<"Enter element at index ["<<i<<"] ["<<j<<"]: ";
			cin>>array[i][j];
		}
	}

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	
	if(rows == cols)
	{
		cout<<"\nIt is a square matrix";
	}

	else
	cout<<"It is not a square matrix";
	
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(i != j)
			{	
				array[i][j] = 0;
			}
			
			else if(i == j)
			{
				
			}
		}
	}
cout<<endl;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;	
}
