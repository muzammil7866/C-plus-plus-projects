#include <iostream>
using namespace std;
void print(int array[], int size);
int main()
{
int array[5] = {0}; //declares an array 5 size having all null elements
int* a=array; //declares a pointer that has the address of the base index of array
int size = 5;
a = new int[size]; //dynamically allocates the array with the size 5
int count = 3;
//	
//	//assigns the values in loop by incrementing each time by 4
for (int i = 0; i < 5; i++)
{
	a[i] = count;
//		count += 4;
}
//
//	print(a, 5); //function call with the argument list containing array and size
return 0;
}
//
void print(int array[], int size)
{
//	//prints the new values of array
for (int i = 0; i < 5; i++)
{
	cout << array[i] << " ";
}
//
}
