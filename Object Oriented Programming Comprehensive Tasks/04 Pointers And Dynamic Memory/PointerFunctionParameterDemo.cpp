#include <iostream>
using namespace std;
int main()
{
int a(1); //initialises a as 1
int b(2); //initialises b as 2
//	int* p1, * p2; //decalres two pointers of integer data type
p1 = &a; //p1 stores the address of a
p2 = &b; //p2 stores the address of b
//	*p1 = *p2; //value of a become 2
//	*p2 = 10; //value of b is updated as 10
cout << *p1 << ' ' << b << ' ' << a << endl; //prints the respective values		
//
return 0;
}
