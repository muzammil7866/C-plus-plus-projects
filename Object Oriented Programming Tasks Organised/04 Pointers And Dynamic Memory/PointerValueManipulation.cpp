#include <iostream>
using namespace std;
int main()
{
	int firstvalue = 15, secondvalue = 25; 
	int* p1, * p2, ** p3, ** p4; //declares pointers

	p1 = &firstvalue;// p1 = address of firstvalue
	p2 = &secondvalue;// p2 = address of secondvalue
	p3 = &p1; // p3 = address of firstpointrer
	p4 = &p2; // p4 = address of secondpointer
	*p1 = 100; // value pointed by p1 = 100
	*p2 = *p1; // value pointed by p2 = value pointed by p1
	p1 = p2; // p1 = p2 (address of pointer is copied or not)
	p3 = p4; // p3 =p4 (check address of pointer is copied or not)
	*p1 = 200; // value pointed by p1 = 200
	cout << firstvalue << endl << secondvalue; // print firstvalue, secondvalue


	return 0;
}
