#include <iostream>
using namespace std;
class Person
{
string name;
int age;
//
public:
void setName(string a)
{
	name = a;
}
//
void setAge(int b)
{
	age = b;
}
//
int getAge()
{
	return age;
}
//
string getName()
{
	return name;
}
};
//
class Student: public Person
{
int rollNo;
//
public:
//
void setRollNo(int c)
{
	rollNo = c;
}
//
int getRollNo()
{
	return rollNo;
}
};
//
class EngineeringStudent : public Student
{
string Branch;
//
void setBranch(string d)
{
	Branch = d;
}
//
string getBranch()
{
	return Branch;
}
//
public:
void input()
{
	string a;
	cout << "ENTER THE NAME OF STUDENT: " << endl;
	cin >> a;
//		setName(a);
//		
	int b;
	cout << "ENTER THE AGE OF STUDENT: " << endl;
	cin >> b;
//		setAge(b);
//
	int c;
	cout << "ENTER THE ROLL NUMBER OF STUDENT: " << endl;
	cin >> c;
//		setRollNo(c);
//
	string d;
	cout << "ENTER THE BRANCH OF STUDENT: " << endl;
	cin >> d;
//		setBranch(d);
//
}
//
void display()
				{
					cout << endl;
					cout << "THIS STUDENT DETAILS: " << endl;
					cout << "\tNAME: " << getName() << endl;
					cout << "\tAGE: " << getAge() << endl;
					cout << "\tROLL NUMBER: " << getRollNo() << endl;
					cout << "\tBRANCH: " << getBranch() << endl;
				}
};
int main()
{
//
EngineeringStudent obj1;
//	obj1.input();
//	obj1.display();
//
//
return 0;
}
