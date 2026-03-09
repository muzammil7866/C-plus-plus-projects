#include<iostream>
using namespace std;
int main()
{
int age = 10;
int age2 = 100;
int* ptr = &age; //address of age assigned to ptr 1
cout << age << endl;
cout << *ptr << endl;
//	*ptr = 14; //updates vaue of age to 14 thorugh pointer
cout << age<<endl;
cout << *ptr<<endl;
int* ptr2 = &age2; //assigns address of age 2 to ptr2
//	*ptr2 = 3 * *ptr; //triples the value of age and assgins to ptr2
cout << age2<<endl;
cout << *ptr2<<endl;
ptr2 = ptr; //copies the address of age to ptr2
cout << *ptr2<<endl; 
cout << age<<endl;
cout << *ptr<<endl;
cout << *ptr2 << endl;
//	(*ptr2)--; //decrements in the value of age through ptr2
cout << age << endl;
cout << *ptr << endl;
cout << *ptr2 << endl;
//
//
//
return 0;
}
