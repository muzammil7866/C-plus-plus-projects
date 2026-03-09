#include <iostream>
using namespace std;
int main()
{
//	double* d_var, *d_array; //declares two pointer variables
d_var = new double; //dynamically memory allocated
d_array = new double[10]; //dynamically memory allocated to array
cout << "Enter your value: ";
cin >> *d_var; 
cout << "Your entered value is: " << *d_var<<endl;
for (int i = 0; i < 10; i++)
{
//		*(d_array+i) = 1.0; //initialising of array is being done using  pointer notation
}
//
for (int i = 0; i < 10; i++)
{
	cout << *(d_array+i) << " "; //prints out the elements of array
}
//	
delete d_var; //memory released to heap
//	delete[] d_array; //memory released to heap
//	
//	
return 0;
}
