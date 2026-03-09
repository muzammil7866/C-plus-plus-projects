#include<iostream>
#include<string>
#include <sec_api/string_s.h>
using namespace std;
struct Car //structure named 'Car' is defined
{
char carName[20]; //character array of 20 size used to input the name of car
char carModel[20]; //character array of 20 size used to input the model of car
int yearModel; //declares the model of car of integer type
double cost; //declares the cost of car of double data type
};
int main()
{
Car	car1; //object 'car1' is declared, of data type 'Car',which is a structure.
	strcpy_s(car1.carName, "Toyota"); //builtin function is used to copy the string in the attribute 'carName' of car1
	strcpy_s(car1.carModel, "Mustang"); //builtin function is used to copy the string in the attribute 'carModel' of car1
car1.yearModel = 2000; //year model of car 1 is initialised
car1.cost = 25000; //cost of car 1 is initialised

Car car2; //object 'car1' is declared, of data type 'Car',which is a structure.
	strcpy_s(car2.carName, "City"); //builtin function is used to copy the string in the attribute 'carName' of car1
	strcpy_s(car2.carModel, "Honda"); //builtin function is used to copy the string in the attribute 'carModel' of car1
car2.yearModel = 2015; //year model of car 1 is initialised
car2.cost = 18000; //cost of car 1 is initialised

	//this block of code prints the individual elements of the object car 1
cout << "DETAILS OF CAR 1: " << endl; 
cout << "Name: " << car1.carName << endl;
cout << "Model: " << car1.carModel << endl;
cout << "Year Model: " << car1.yearModel << endl;
cout << "Cost: " << car1.cost << endl;

	//this block of code prints the individual elements of the object car 2
cout <<endl<<endl<< "DETAILS OF CAR 2: " << endl;
cout << "Name: " << car2.carName << endl;
cout << "Model: " << car2.carModel << endl;
cout << "Year Model: " << car2.yearModel << endl;
cout << "Cost: " << car2.cost << endl;
cout << endl << endl;
		
	//checks if the cost of car 2 is more than the car 1
if (car2.cost >= car1.cost)
	cout << "Car with the highest cost is: " << car2.carName;  //prints the cost of car 2

else
	cout << "Car with the highest cost is: " << car1.carName; //prints the cost of car 2
	
cout<< endl;
	
return 0;

}
