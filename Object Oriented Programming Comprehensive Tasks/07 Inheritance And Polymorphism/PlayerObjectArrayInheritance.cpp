#include <iostream>
using namespace std;
class shape {
//
public:
double width;
double height;
//
//	shape()
{
	width = 10;
	height = 10;
}
//
//	shape(double x, double y)
{
	width = x;
	height = y;
}
//
double area()
{
	return width * height;
}
//
};
int main()
{
shape obj1;
shape obj2(20.6, 57.4);
//
double area1 = obj1.area();
double area2 = obj2.area();
//
cout << "The area of shape 1 is: "<<area1;
cout << endl;
cout << "The area of shape 2 is: "<<area2;
//
//
return 0;
}
