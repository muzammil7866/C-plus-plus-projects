#include<iostream>
using namespace std;

class Sample 
{
	int id;
	int age;
	int salary;
	int employee_no;

public:
	void init(int x, int y, int z, int a) //assigns values to the members of object
	{
		id = x;
		age = y;
		salary = z;
		employee_no = a;

	}
	Sample() //default constructor to initialises the members of object
	{
		id = 0;
		age = 0;
		salary = 0;
		employee_no = 0;
	}

	Sample(Sample &t) //constructor that copies the contents of object to another
	{
		id = t.id;
		age = t.age;
		salary = t.salary;
		employee_no = t.employee_no;
	}
	void display() //displays the members of the object
	{
		cout << endl << "ID=" << id;
		cout << endl << "AGE" << age;
		cout << endl << "SALARY=" << salary;
		cout << endl << "EMPLOYEE NUMBER=" << employee_no;
	}
};
int main()
{
	Sample obj1;
	obj1.init(10, 40, 75000, 50); //function called to assign values for the object
	cout << "EMPLOYEE 1: "<<endl;
	obj1.display(); //function called to diplay members of the object
	cout << endl;

	Sample obj2(obj1); //constructor that copies the content of the parameter into the object being declared
	cout << endl<<"EMPLOYEE 2: " << endl;
	obj2.display(); // function called to diplay members of the object
	cout << endl;
	Sample obj3(obj1); // constructor that copies the content of the parameter into the object being declared
	cout << endl<<"EMPLOYEE 3: " << endl;
	obj3.display(); // function called to diplay members of the object

	return 0;
}