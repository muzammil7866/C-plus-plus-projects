#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
int a = 5, b = 10;
int c;
//	int* p1, * p2;
p1 = &a;
p2 = &b;
c = *p1;  //5
cout << "*(p1++) =" <<" "<< *(p1++) << endl; //first dereferencing of p1 is done using the pointer's asterik notation. Then the address of p1 is incremented.
cout << "value of p1 " << p1 << endl; //displays the updated address of p1
cout << "*(++p1) =" << *(++p1) << endl; //first the address of the pointer is incremented by 4 in braces and then its dereferencing is done by the pointer's asterik notation
cout << "value of p1 " << p1 << endl; //displays the updated address of p1
cout << "(*p1)++ =" << (*p1)++ << endl; //first dereferencing of p1 is done and the value is displayed. Then its value is incremented
cout << "value of p1 " << p1 << endl; //displays the same address of the p1 as in the last "cout"
cout << "++(*p1) =" << ++(*p1) << endl; //increments in the value of p1 and then displays the value using dereferencing of pointer with the asterik notation
cout << "value of p1 " << p1 << endl; //displays the same address of the p1 as in the last "cout"
return 0;
}
