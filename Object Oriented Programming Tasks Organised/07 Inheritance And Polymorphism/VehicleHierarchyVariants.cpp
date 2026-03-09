#include <iostream>
#include<string>
using namespace std;
class Address
{
	//members
	string streetAddress;
	string city;
	string state;

public:
	//displays member values
	void retrieveValues()
	{
		cout << endl;
		cout << "\tSTREET ADDRESS: " <<streetAddress<< endl;
		cout << "\tCITY: " << city<<endl;
		cout << "\tSTATE: " << state<<endl;
	}
	
	//sets values of members
	void setVal()
	{
		cout << "ENTER THE STREET ADDRESS OF THE PERSON: ";
		cin >> streetAddress;
		
		cout << "ENTER THE CITY OF THE PERSON: ";
		cin >> city;

		cout << "ENTER THE STATE OF THE PERSON: ";
		cin >> state;
	}
};

class Person
{
	//implements aggregation as pointer of Address is a member of person class (weak has a relationship)
	Address* obj1;
	string name;
	
public:
	//setter
	void setValues(Address obj)
	{
		cout << "ENTER THE NAME OF THE PERSON: ";
		cin >> name;

		
		obj1 = &obj; // address of the Address object pointed to the class member of Address type
	}
	
	//prints the member values
	void retrieveValue(Address obj)
	{
		cout << endl << endl;
		cout << "\tPERSON NAME: "<<name;

		obj.retrieveValues(); //calls the getter of Address class
	}

};


int main()
{
	//object declaration
	Person obj;
	Address obj1;
	
	//setters
	obj1.setVal();
	obj.setValues(obj1);
	
	//getters
	obj.retrieveValue(obj1);
	

	return 0;
}
