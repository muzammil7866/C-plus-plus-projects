#include <iostream>
using namespace std;
class person
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
string getName()
{
	return name;
}
//
void setAge(int a)
{
	age = a;
}
//
int getAge()
{
	return age;
}
//
//
};
//
class Student : public person
{
//
int rollNo;
string courseName;
//
//	
//
public:
void input()
{
	string temp;
	cout << "Enter the student's name: ";
	cin >> temp;
//		setName(temp);
//
	int temp2;
//
	cout << "Enter the student's age: ";
	cin >> temp2;
//		setAge(temp2);
//		
	cout << "Enter the student's roll number: ";
	cin >> rollNo;
	cout << "Enter the student's course name: ";
	cin >> courseName;
//			
}
//
void display()
{
	cout << endl;
	cout << "THIS STUDENT DETAILS: " << endl;
	cout << "\tNAME: " << getName()<<endl;
	cout << "\tAGE: " << getAge() << endl;
	cout << "\tROLL NUMBER: " << rollNo << endl;
	cout << "\tCOURSE NAME: " << courseName << endl;
//
}
//
//
};
int main()
{
//	
Student obj1;
//	obj1.input();
//	obj1.display();
//
return 0;
}
