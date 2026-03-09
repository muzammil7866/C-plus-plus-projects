#include<iostream>
using namespace std;
int main()
{
struct address
{
	char house[15];
	char street[25];
	char city[25];
	char province[25];
};
struct emp
{
	char name[25];
	int age;
	double gpa;
	address a;
};
//
//	emp person,person2, person3;
person = { "Muzammil", 21, 3.71, {"113","Hunza Block", "Lahore", "Punjab"}};
person2 = { "Fahad", 19, 3.46, {"116","Rizwan Block", "Quetta", "Punjab"} };
person3 = { "Harris", 27, 2.93, {"123","Ahad Block", "Faisalabad", "Punjab"} };
cout << "***************DETAILS*****************" << endl;
cout << "PERSON 1: " << endl << endl;
cout <<"Name: "<< person.name << endl;
cout << "Age: " << person.age<<endl;
cout << "GPA: " << person.gpa<<endl;
cout << "House: "<<person.a.house << endl;
cout << "Street:"<<person.a.street << endl;
cout << "City: "<<person.a.city<< endl;
cout << "Province: " << person.a.province << endl<<endl;
//
cout << "PERSON 2: " << endl << endl;
cout << "Name: " << person2.name << endl;
cout << "Age: " << person2.age << endl;
cout << "GPA: " << person2.gpa << endl;
cout << "House: " << person2.a.house << endl;
cout << "Street:" << person2.a.street << endl;
cout << "City: " << person2.a.city << endl;
cout << "Province: " << person2.a.province << endl<<endl;
//
cout << "PERSON 3: " << endl << endl;
cout << "Name: " << person3.name << endl;
cout << "Age: " << person3.age << endl;
cout << "GPA: " << person3.gpa << endl;
cout << "House: " << person3.a.house << endl;
cout << "Street:" << person3.a.street << endl;
cout << "City: " << person3.a.city << endl;
cout << "Province: " << person3.a.province << endl;
//
return 0;
}
