#include <iostream>
using namespace std;
class Employee
{
string name;
int age;
int salary;
string department;
//
public:
void setEmployee(string a, int b, int c)
{
	name = a;
	age = b;
	salary = c;
	cout << endl;
//		getEmployee();
//
}
//
void setEmployee(string a, int b, int c, string d)
{
	name = a;
	age = b;
	salary = c;
	department = d;
	cout << endl;
//		getEmployee2();
}
//
void getEmployee()
{
	cout << "\tNAME: " << name<<"\n";
	cout << "\tAGE: " << age << "\n";
	cout << "\tSALARY: " << salary << "\n";
//
}
//
void getEmployee2()
{
	cout << "\tNAME: " << name << "\n";
	cout << "\tAGE: " << age << "\n";
	cout << "\tSALARY: " << salary << "\n";
	cout << "\tDEPARTMENT: " << department << "\n";
}
//	
};
int main()
{
Employee obj;
string name; int age; int salary; string department;
bool option;
cout << "\tDO YOU HAVE THE DEPARTMENT OF THE EMPLOYEE: \n\n(ENTER 1 FOR YES AND ENTER 0 FOR NO): ";
cin >> option;
if (option == 0)
{
	cout << "ENTER THE NAME OF THE EMPLOYEE: ";
	cin >> name;
	cout << "ENTER THE AGE OF THE EMPLOYEE: ";
	cin >> age;
	cout << "ENTER THE SALARY OF THE EMPLOYEE: ";
	cin >> salary;
//		obj.setEmployee(name, age, salary);
}
//
else
{
	cout << "ENTER THE NAME OF THE EMPLOYEE: ";
	cin >> name;
	cout << "ENTER THE AGE OF THE EMPLOYEE: ";
	cin >> age;
	cout << "ENTER THE SALARY OF THE EMPLOYEE: ";
	cin >> salary;
	cout << "ENTER THE DEPARTMENT OF THE EMPLOYEE: ";
	cin >> department;
//		obj.setEmployee(name, age, salary, department);
}
//
return 0;
}
