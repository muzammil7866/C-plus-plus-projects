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
static void increase_count()
{
	count = count * 2;
}
//
static void reset_count()
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
cout << "VALUE OF COUNT: " << obj1.count << endl;
//	obj1.increase_count();
cout << "VALUE OF THE UPDATED COUNT: "<<obj1.count << endl;
//	obj1.reset_count();
//	
//	
student obj2(3154, 19);
cout << "VALUE OF COUNT: " << obj2.count << endl;
//	obj2.increase_count();
cout << "VALUE OF THE UPDATED COUNT: " << obj2.count << endl;
//	obj2.reset_count();
//	
//	
student obj3(3148, 18);
cout << "VALUE OF COUNT: "<<obj3.count << endl;
//	obj3.increase_count();
cout << "VALUE OF THE UPDATED COUNT: " << obj3.count<<endl;
//	obj3.reset_count();
//	
//	
student obj4(3114, 16);
cout << "VALUE OF COUNT: " << obj4.count << endl;
//	obj4.increase_count();
cout << "VALUE OF THE UPDATED COUNT: " << obj4.count << endl;
//	obj4.reset_count();
//	
//	
//	obj1.display();
//	obj2.display();
//	obj3.display();
//	obj4.display();
return 0;
}
//
