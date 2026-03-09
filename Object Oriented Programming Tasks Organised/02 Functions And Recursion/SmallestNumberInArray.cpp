#include <iostream>
using namespace std;
double smallest(double array[], int);
int main()
{
double array[20];
//	
for (int i = 0; i < 20; i++) //takes in input into the array
{
	cout << "Enter your number " << i+1 << " : ";
	cin >> array[i];
}
//
cout<< "Smallest number is: "<<smallest(array, 20); //array is passed to the function which returns the smallest value. It is then outputted.
//
//
//
//
return 0;
}
//
double smallest(double array[], int size) //takes in array and then compares with the minimum value of array
{
double min=array[0];
for (int i = 0; i < size; i++)
{
	if (array[i] < min)
		min = array[i];
}
//
return min;
//
}
