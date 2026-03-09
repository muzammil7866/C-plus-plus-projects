#include <iostream>
using namespace std;
class Vehicle
{
//	//member functions
float speed;
float distance;
//
//	
public:
//	//setters and getters of members
void setSpeed(float a)
{
	speed = a;
}
//
float getSpeed()
{
	return speed;
}
//
void setDistance(float a)
{
	distance = a;
}
//
float getDistance()
{
	return distance;
}
//
//	//calculates time
float computeDuration()
{
	return distance/speed;
}
};
//
////inheritance by WheelVehicle
class WheelVehicle : public Vehicle
{
//	//members
int wheels;
//
//	//setters and getters
public:
void setWheels(int a)
{
	wheels = a;
}
//
int getWheels()
{
	return wheels;
}
};
//
////inheritance by WingVehicle
class WingVehicle : public Vehicle
{
//	//members
int wings;
//
//	
public:
//	//setters and getters
void setWings(int a)
{
	wings = a;
}
//
int getWings()
{
	return wings;
}
};
//
////inheritance by Truck
class Truck : public WheelVehicle
{
//	//members
float carryingLoad;
public:
//	//setters and getters
void setLoad( float a)
{
	carryingLoad = a;
}
//
float getLoad()
{
	return carryingLoad;
}
};
//
int main()
{
//	//declaring and initialising the object
Truck obj1;
//	obj1.setLoad(5004.1);
//	obj1.setWheels(18);
//	obj1.setSpeed(231.9);
//	obj1.setDistance(3012.8);
//
//	//outputting the members
cout << "LOAD: " << obj1.getLoad()<<" kgs"<<endl;
cout << "WHEELS: " << obj1.getWheels()<<" wheels" << endl;
cout << "SPEED: " << obj1.getSpeed()<<" km/hr" << endl;
cout << "DISTANCE: " << obj1.getDistance()<<" kms" << endl;
cout << "TIME DURATION: " << obj1.computeDuration()<<" hours" << endl;
//
//
return 0;
}
