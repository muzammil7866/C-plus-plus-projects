#include <iostream>
using namespace std;
class Vehicle {
//
protected:
//
int maxSpeed;
//
public:
	void setMax(int a)
	{
		maxSpeed = a;
	}
//	
	int getMax()
	{
		return maxSpeed;
	}
//
};
//
class car : public Vehicle
{
int noOfSeats;
string model;
//
public:
void input()
		{
			int temp;
			cout << "Enter the maximum speed of the car: ";
			cin >> temp;
//				setMax(temp);
//		
//				
			cout << "Enter the no of seats of the car: ";
			cin >> noOfSeats;
			cout << "Enter the model of the car: ";
			cin >> model;
//					
		}
//		
		void display()
		{
			cout << endl;
			cout << "THIS CAR DETAILS: " << endl;
			cout << "\tMAXIMUM SPEED: " << getMax() << endl;
			cout << "\tNO OF SEATS: " << noOfSeats << endl;
			cout << "\tMODEL: " << model<< endl;
//		
		}
//
};
//
class bike: public Vehicle
{
string type;
//
public:
void input()
{
	cout << endl;
	int temp;
	cout << "Enter the maximum speed of the bike: ";
	cin >> temp;
//		setMax(temp);
//
	cout << "Enter the type of the bike: ";
	cin >> type;
//
}
//
void display()
{
	cout << endl;
	cout << "THIS BIKE DETAILS: " << endl;
	cout << "\tMAXIMUM SPEED: " << getMax() << endl;
	cout << "\tTYPE: " << type << endl;
//
}
//
public:
//	
};
int main()
{
car obj1;
//	obj1.input();
//	obj1.display();
//
bike obj2;
//	obj2.input();
//	obj2.display();
//		
//
return 0;
}
