#include <iostream>
using namespace std;
class shape {

	double width;
	double height;

public:

	shape(double x, double y)
	{
		width = x;
		height = y;
	}

	double area()
	{
		return width * height;
	}

	~shape()
	{
		height = 0;
		width = 0;
	}

};
int main()
{
	bool area=false;

	while (area != true)
	{
		
		double height, width;
		cout << "Enter the height of your object: ";
		cin >> height;
		cout << "Enter the width of your object: ";
		cin >> width;
		shape obj1(width, height);

		double area2 = obj1.area();
		if (area2 > 250)
		{
			area = false;
			obj1.~shape();
			cout << "Your area exceeds 250" << endl << "Enter your values again! ";
		}
		else
		{
			cout << "Area is under 250 :)";
			area = true;
		}
	}
	return 0;
}
