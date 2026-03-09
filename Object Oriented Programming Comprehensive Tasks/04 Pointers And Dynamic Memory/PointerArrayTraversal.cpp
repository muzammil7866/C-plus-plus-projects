#include <iostream>
using namespace std;
int main()
{
double balance[5] = { 1000.0, 2.01, 3.4, 17.0, 50.40 };
//
double* p;
p = balance; //address of first element of array is stored in p
//	
for (int i = 0; i < 5; i++)
{
	cout << *p<<" "; //displays the value of the address to which pointer is referring
//		p++; 
}
//
return 0;
}
