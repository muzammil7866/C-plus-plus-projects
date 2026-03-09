#include <iostream>
using namespace std;
int main()
{
	/*int m, n; 
cout << "Enter the no. of rows of your array: ";
cin >> m;
cout << "Enter the no. of cols of your array";
cin >> n;*/
const int m=3, n=3;
	int A[m][n], sum=0, totalsum=0;

for (int i = 0;i < m;i++)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Enter the element at index[" << i << "][" << j<<"]: ";
		cin >> A[i][j];
	}
}
cout << "\t\tORIGINAL MATRIX: " << endl;
for (int i = 0;i < m;i++)
{
	for (int j = 0; j < n; j++)
	{
		cout << A[i][j]<<" ";
	}
	cout << endl;
}

cout << endl;

for (int i = 0;i < m;i++)
{	
	sum = 0;
	for (int j = 0; j < n; j++)
	{
		sum = sum + A[i][j];
	}
	cout << "Sum of row " << i + 1 << " is: " << sum<<endl<<endl;
}

for (int i = 0;i < m;i++)
{
	sum = 0;

	for (int j = 0; j < n; j++)
	{
			
		sum = sum + A[j][i];
	}
	cout << "Sum of col " << i + 1 << " is: " << sum << endl << endl;
}

sum = 0;

for (int i = 0;i < m;i++)
{


	for (int j = 0; j < n; j++)
	{

		sum = sum + A[i][j];
	}
	
}

cout << "Total sum is: " << sum << endl << endl;

cout << "\t\tTRANSPOSED MATRIX: "<<endl;
for (int i = 0;i < m;i++)
{


	for (int j = 0; j < n; j++)
	{

		cout<< A[j][i]<<" ";
	}
	cout << endl;
}

return 0;
}
