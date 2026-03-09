#include <iostream>
using namespace std;
void print(int** p2array);
int main()
{
int array[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} }; //declares and initialises the array
int* parray = array[0]; //base address of array is assigned to pointer of parray
int** p2array;
for (int i = 1; i <= 9; i++) //as it is a 3x3 marix so loop would run 9 times
{
	p2array = &parray; //double pointer stores the address of single pointer which points to the base address of array
//		print(p2array); //passes the double pointer to the function
	if (i % 3 == 0) //when one row is displayed then a line is ended
		cout << endl;
//		parray++; //base address is incremented which points to the next element in the array
}
//
//
//
return 0;
}
void print(int** p2array)
{
cout << **p2array << " "; //displays the original element of arrat to which double poiner refers to
}
