#include<iostream>
using namespace std;
class Engine {
	//members
string fuelType;
int cylinderCount;
int horsePower;
public:
	//constuctor that initialises the members
Engine(string fuelType, int CylinderCount, int horsePower)
{
	this->cylinderCount = CylinderCount;
	this->fuelType = fuelType;
	this->horsePower = horsePower;

}

	//setters and getters

string getFuelType(Engine a)
{
	return a.fuelType;

}

int getCylinderCount(Engine a)
{
	return a.cylinderCount;
}

int getHorsePower(Engine a)
{
	return a.horsePower;
}

};
class Car {
	//members
string brand;
string model;
int year;
Engine engine;
public:
	//initialising the object of Engine (this shows composition)
Car(string brand, string model, int year, string fuelType, int cylinderCount, int horsePower)
		:engine(fuelType, cylinderCount, horsePower)
{
	this->brand = brand;
	this->model = model;
	this->year = year;
}

//setters and getters
string getBrand()
{
	return brand;
}
string getModel()
{
	return model;
}
int getYear()
{
	return year;
}

string getFuelType()
{
	return engine.getFuelType(engine);
}

int cylinderCount()
{
	return engine.getCylinderCount(engine);
}

int horsePower()
{
	return engine.getHorsePower(engine);
}
};

int main()
{
//decalring and initialising object
	Car mycar("Toyota", "Camry", 2022, "Gasoline", 4, 203);
	cout << "Brand: " << mycar.getBrand() << endl;
	cout << "Model: " << mycar.getModel() << endl;
	cout << "Year: " << mycar.getYear() << endl;
	cout << "Fueltype: " << mycar.getFuelType() << endl;
	cout << "Cylinder count: " << mycar.cylinderCount() << endl;
	cout << "Horse power: " << mycar.horsePower() << endl;

}
