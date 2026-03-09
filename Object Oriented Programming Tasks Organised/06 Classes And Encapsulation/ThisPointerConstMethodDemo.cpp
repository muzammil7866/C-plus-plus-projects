#include<iostream>;
using namespace std;
class Employee{
 private:
//	  // Private attribute
  int salary;
//	  
//
public:
string designation;
int emp_code;
//
private:
  int age;
  string name;
//
public:
//
Employee()
{
	designation = '\0';
	emp_code = 0;
}
//
Employee(int a, string b)
{
	age = a;
	name = b;
}
//
int getage()
{
	return age;
}
//
string getname()
{
	return name;
}
//		// Setter
	void setSalary(int s) {
	  salary = s;
	}
//		// Getter
	int getSalary() {
	  return salary;
	}
};
int main() {
Employee myObj;
//	myObj.setSalary(50000);
cout << myObj.getSalary();
//	myObj.getSalary();
//
Employee myNewObj(38, "JOHN");
//
myNewObj.designation = "LAWYER";
myNewObj.emp_code = 1925;
//
cout << "DETAILS OF EMPLOYEE: ";
cout << "NAME: " << myNewObj.getname()<<endl;
cout << "AGE: " << myNewObj.getage()<<endl;
cout << "DESIGNATION: "<<myNewObj.designation<<endl;
cout << "EMP CODE: " << myNewObj.emp_code<<endl;
//	
//
//
return 0;
}
