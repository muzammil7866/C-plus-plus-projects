#include<iostream>
using namespace std;
int main()
{
struct address
{
	char phone[15];
	char city[25];
	int pin; 
};
struct emp
{
	char name[25];
	address a;
};
//
emp person;
person = { "Muzammil", {"03004848190","Lahore", 1234} };
cout << "***************DETAILS*****************" << endl;
cout <<"Name: "<< person.name << endl;
cout << "Phone: "<<person.a.phone << endl;
cout << "City:"<<person.a.city << endl;
cout << "Pin: "<<person.a.pin << endl;
//
//
//
return 0;
}
