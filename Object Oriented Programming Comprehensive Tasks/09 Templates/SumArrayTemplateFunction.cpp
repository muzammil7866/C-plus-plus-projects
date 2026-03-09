#include <iostream>
using namespace std;
template <typename T>
T sumArray(T array[], int size)
{
float temp = 0;
for (int i = 0; i < size; i++)
{
//		
	temp = temp + array[i];
}
//
return temp;
//
}
int main()
{
int size = 0;
float array[5] = { 1,2,3,4,5 };
//
cout<< "SUM IS: "<<sumArray(array, 5);
//
//
//
//
return 0;	
}
