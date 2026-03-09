#include<iostream>
using namespace std;
class Room {
public: //access modifies as public (members could be accessed outside class)
double length;
double breadth;
double height;
//	
//	Room(double a, double b, double c) //constructor that initialises the object taking in parameters when it is created
{
	length = a;
	breadth = b;
	height = c;
}
//
void input(double a, double b, double c) //function that assigns values to the members of object
{
	length = a;
	breadth = b;
	height = c;
}
double calculateArea() //calculates area for the object it is called
{
	return length * breadth;
}
double calculateVolume() //calculates volume for the object it is called
{
	return length * breadth * height;
}
};
//
int main() {
Room room1(0, 0, 0); //declares object of Room class with the parameterised constructor
//	room1.input(45.3, 65.4, 45.6); //function called to assign the values into the members
//	
cout<<"AREA OF THE ROOM: "<<room1.calculateArea()<<endl; //displays area by calling function for the object
cout<<"VOLUME OF THE ROOM: "<<room1.calculateVolume(); //displays volume by calling function for the object
//
return 0;
}
