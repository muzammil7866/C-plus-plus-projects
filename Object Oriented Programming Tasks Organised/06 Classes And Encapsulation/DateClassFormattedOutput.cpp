#include <iostream>
using namespace std;
int* copyFun(int arr[], int SIZE); //prototype of the function that copies the 
int main()
{
int size = 11;
int array[11] = { 100,200,300, 400, 500, 10,20,30,40,50,60 }; //declares and initialises the array as given in the lab sample
//
cout << "ORIGINAL ARRAY CONTENETS: " << endl;
for (int i = 0; i < size; i++)
	cout << array[i] << " "; //prints out the original array contents in loop
//
cout << endl;
int* ptr2 = copyFun(array, size); //argument list is passed in the function with array and its size
//
return 0;
}
int* copyFun(int arr[], int SIZE) //formal parameters are shown with array and size
{
int* ptrArray2; //declares a pointer
ptrArray2 = new int[SIZE]; //dynamically allocates the array with size passed from main
//
//	//this loop copies the array
for (int i = 0; i < SIZE; i++)
{
	ptrArray2[i] = arr[i];
}
cout << endl << "DUPLICATE ARRAY: " << endl;
for (int i = 0; i < SIZE; i++) //outputs the contents of the duplicated array
	cout << ptrArray2[i] << " ";
//
cout << endl;
//
return ptrArray2; //returns the pointer referring to the base index of duplicated array
//
}
