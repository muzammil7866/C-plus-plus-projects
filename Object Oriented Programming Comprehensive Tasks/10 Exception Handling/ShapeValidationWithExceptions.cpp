#include <iostream>
using namespace std;
class Rectangle
{
public:
float length;
float width;
bool valid;
//
//	Rectangle(float a, float b)
{
	length = a;
	width = b;
	valid = true;
//
//		try
	{
		if (a <= 0)
		{
			valid = false;
//				throw(a);
		} 
	}
//
//		catch (float a)
	{
		cout << "\nTHE LENGTH COULD NOT BE ZERO OR NEGATIVE"<<endl;
	}
//
//		try
	{
		if (b <= 0)
		{
			valid = false;
//				throw(b);
		}
	}
//
//		catch (float b)
	{
		cout << "\nTHE WIDTH COULD NOT BE ZERO OR NEGATIVE"<<endl;
	}
}
//
float getArea()
{
	if (valid == true)
	{
		cout << "AREA OF THIS CIRCLE IS: " << length * width;
		return length * width;
	}
//	
}
};
//
class Circle
{
public:
float radius;
bool valid;
//
//	Circle(float a)
{
	radius = a;
	valid = true;
//		try
	{
		if (a <= 0)
		{
			valid = false;
//				throw(a);
		}
	}
//
//		catch (float a)
	{
		cout << "\nTHE RADIUS COULD NOT BE ZERO OR NEGATIVE" << endl;
	}
}
//
float getArea()
{
	if (valid == true)
	{
		cout << "AREA OF THIS CIRCLE IS: " << (22 / 7) * radius * radius;
		return (22 / 7) * radius * radius;
	}
}
//
//
};
int main()
{
//
Rectangle a(5.4,6.1);
//	a.getArea();
cout << endl;
//
Rectangle b(5.4, 0);
//	b.getArea();
cout << endl;
//
Circle c(7.3);
//	c.getArea();
cout << endl;
//
Circle d(-45.7);
//	d.getArea();
cout << endl;
//
//
return 0;	
}
