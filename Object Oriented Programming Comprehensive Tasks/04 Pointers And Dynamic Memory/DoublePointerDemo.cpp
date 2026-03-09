#include <iostream>
using namespace std;
void swapAcrossCenter(int* p , int size);
int main()
{
int size = 0;
cout << "Enter the size of your array: ";
cin >> size;
//
if (size % 2 == 0) //check if the size of array is an odd number
	cout << "Size of the array needs to be an odd number";
//
else
{
	int array[50];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the element of array at index [" << i << "]: ";
		cin >> array[i];
	}
//	
//		swapAcrossCenter(array, size);
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
//
}
//		
return 0;
}
//
void swapAcrossCenter(int arr[50], int size)
{
int moduluss = (size % 2)+1;
int* s = arr; //gives the address of the zero index to s
int* e = &arr[size - 1];
int temp = 0;
	for (int i = 0; i < moduluss; i++) //swaps the values subsequently of the array across the center index
	{
		temp = *s;
//			*s = *e;
//			*e = temp;
//			s++;
//			e--;
	}
}
