#include <iostream>
using namespace std;
class shape {
//
public:
//
float area(float radius)
{
	return 3.142 * radius * radius;
}
float area(int length, int width)
{
	return length * width;
}
//	
//	
float area(float base, float height)
{
	return (base * height)*.5;
}
};
int main()
{
bool repeat = true;
//	
float radius;
float length;
float width;
//
//
while (repeat != false)
{
	int option;
cout<<endl;
cout << "ENTER THE CORRESPONDING VALUES TO CALCULATE THE AREA: "<<endl;
cout << "\tENTER 1 FOR CIRCLE : " << endl;
cout << "\tENTER 2 FOR RECTANGLE: " << endl;
cout << "\tENTER 3 FOR TRIANGLE: " << endl;
cout << "ENTER YOUR VALUE: ";
cin >> option;
//
shape obj1;
if (option == 1)
{
	repeat = false;
	cout << "ENTER THE VALUE OF RADIUS: ";
	cin >> radius;
	cout<<"AREA OF THE CIRCLE IS: "<<obj1.area(radius);
//
}
else if (option == 2)
{
	repeat = false;
	cout << "ENTER THE LENGTH OF RECTANGLE (IN INTEGER): ";
	cin >> length;
	cout << "ENTER THE WIDTH OF RECTANGLE (IN INTEGER): ";
	cin >> width;
	cout << "AREA OF THE RECTANGLE IS: " << obj1.area(length, width);
}
else if (option == 3)
{
	repeat = false;
	cout << "ENTER THE BASE OF TRIANGLE : ";
	cin >> length;
	cout << "ENTER THE HEIGHT OF TRIANGLE : ";
	cin >> width;
	cout << "AREA OF THE TRIANGLE IS: " << obj1.area(length, width);
}
//
else
{
	cout << "INVALID INPUT! "<<endl;
	cout << "ENTER OPTION AGAIN!"<<endl;
	repeat = true;
}
}
return 0;
}
