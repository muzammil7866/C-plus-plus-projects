#include <iostream>
using namespace std;
class shape {
//
//
double width;
double height;
//
public:
//
//	shape()
{
	width = 10;
	height = 10;
}
//
void printArea()
{
	cout << "Area: " << width * height;
}
//
double getterwidth()
{
	return width;
}
//
double getterheight()
{
	return height;
}
};
int main()
{
shape obj3;
cout <<"Height: "<<obj3.getterwidth()<<endl;
cout <<"Width: "<< obj3.getterheight()<<endl;
//	obj3.printArea();
//
return 0;
}
