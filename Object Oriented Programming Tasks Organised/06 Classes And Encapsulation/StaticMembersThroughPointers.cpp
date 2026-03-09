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
void increase_count()
{
	count = count * 2;
}
//
void reset_count()
{
	count = count / 2;
}
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
student* ptr1 = &obj1;
cout << "VALUE OF COUNT: " << (*ptr1).count << endl;
//	(*ptr1).increase_count();
cout << "VALUE OF THE UPDATED COUNT: "<< (*ptr1).count << endl;
//	(*ptr1).reset_count();
//	
//	
student obj2(3154, 19);
student* ptr2 = &obj2;
cout << "VALUE OF COUNT: " << (*ptr2).count << endl;
//	(*ptr2).increase_count();
cout << "VALUE OF THE UPDATED COUNT: " << (*ptr2).count << endl;
//	(*ptr2).reset_count();
//	
//	
student obj3(3148, 18);
student* ptr3 = &obj3;
cout << "VALUE OF COUNT: "<< (*ptr3).count << endl;
//	(*ptr3).increase_count();
cout << "VALUE OF THE UPDATED COUNT: " << (*ptr3).count <<endl;
//	(*ptr3).reset_count();
//	
//	
student obj4(3114, 16);
student* ptr4 = &obj4;
cout << "VALUE OF COUNT: " << (*ptr4).count << endl;
//	(*ptr4).increase_count();
cout << "VALUE OF THE UPDATED COUNT: " << (*ptr4).count << endl;
//	(*ptr4).reset_count();
//	
//	
//	(*ptr1).display();
//	(*ptr2).display();
//	(*ptr3).display();
//	(*ptr4).display();
return 0;
}
//
