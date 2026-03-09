#include <iostream>
using namespace std;
class student
{
private:
int rollno;
int age;
//
public:
static int count;
//
//	student()
{
//		count++;
}
//
//	student(int a, int b)
{
	rollno = a;
	age = b;
//		count++;
}
//	
void display()
{
	cout << "THIS OBJECT DETAILS: " << endl;
	cout <<"ROLL NO: "<<rollno << endl;
	cout <<"AGE: "<< age << endl;
}
};
//int student::count = 0;
//
int main()
{
student obj1(2045, 21);
cout << "VALUE OF COUNT: " << obj1.count << endl;
student obj2(3154, 19);
cout << "VALUE OF COUNT: " << obj2.count << endl;
student obj3(3148, 18);
cout << "VALUE OF COUNT: "<<obj3.count << endl;
student obj4(3114, 16);
cout << "VALUE OF COUNT: " << obj4.count << endl;
//	obj1.display();
//	obj2.display();
//	obj3.display();
//	obj4.display();
return 0;
}
