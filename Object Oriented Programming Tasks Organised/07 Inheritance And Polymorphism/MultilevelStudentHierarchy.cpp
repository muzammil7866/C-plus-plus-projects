#include <iostream>
#include<string>
using namespace std;
class eventCard 
{ 
//	//class members
string eventName;
string dateOfEvent;
string timeOfEvent;
string addressOfEvent;
//
//	//friend function prototype
friend void print(eventCard obj);
//
public:
//	//setter for all the members
void setMembers()
{
	cout << "ENTER THE NAME OF EVENT: ";
//		getline(cin,eventName);
//
	cout << "ENTER THE DATE OF EVENT: ";
//		getline(cin, dateOfEvent);
//
	cout << "ENTER THE TIME OF EVENT: ";
//		getline(cin, timeOfEvent);
//
	cout << "ENTER THE ADDRESS OF EVENT: ";
//		getline(cin, addressOfEvent);
}
//
};
//
////displays all the members
void print(eventCard obj)
{
cout << "\tEVENT NAME: " << obj.eventName<<endl;
cout << "\tDATE OF EVENT: " << obj.dateOfEvent<< endl;
cout << "\tTIME OF EVENT: " << obj.timeOfEvent<< endl;
cout << "\tADDRESS OF EVENT: " << obj.addressOfEvent<< endl;
//
}
//
int main()
{
//	
eventCard obj1; //object declaration
//	obj1.setMembers(); //sets all members
//	print(obj1); //displays object members
//
//
return 0;
}
