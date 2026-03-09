#include <iostream>
using namespace std;
int main()
{
int array[4] = {3, 9, 12, 15};
//
int* p = array; //address of first element of array is stored in p
//
for (int i = 0; i < 4; i++)
{
	cout << *p << " " << endl<< p; //displays the value of element of array and then disply its address each one by one
	cout << endl;
//		p++; //points to the next element of array
}
//
return 0;
}
