#include <iostream>
using namespace std;
class Student {
public:
string name;
int rollNo;
//
//	Student()
{
	name = "John";
	rollNo = 2;
}
//
//	~Student()
{
	name = "\0";
	rollNo = 0;
}
//
};
int main()
{
Student person1;
cout << person1.name << endl;
cout << person1.rollNo;
//	person1.~Student();
//
//
return 0;
}
