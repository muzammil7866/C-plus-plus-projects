#include <iostream>
using namespace std;
void foo(); //function prototype
int main()
{
//	foo(); //calls the function foo
return 0;
}
void foo()
{
int* array = new int[100]; //dynamically allocates memory to the array
for (int i = 0; i < 100; i++)
{
//
//		*(array + i) = 0; //initialises each element of the array as 0
//
}
//	 
for (int i = 0; i < 100; i++)
{
//
	cout<<*(array + i)<<" "; //outputs each element of the array
//
}
}
