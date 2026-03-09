#include <iostream>
using namespace std;
void function(double array[], int);
int main()
{
double array[50]={0}; //array is declared of type double
//
//	function(array, 50); //array passed to function
}
//
void function(double array[], int size) 
{
//
for (int i = 0;i < 25; i++)
{
	array[i] = i*i; //for first 25 values the square of i is assigned
}
//
for (int i = 25;i < 50; i++)
{
	array[i] = i * i * i; //for next 25 values the cube of i is assigned
}
//
for (int i = 0;i < 50; i++) //array is outputted (10 items per line)
{
	cout << array[i]<<" ";
	if ((i + 1) % 10 == 0)
	{
		cout << endl;
	}
}
}
