#include <iostream>
using namespace std;
int main()
{
	char gender; bool urban; int age; bool anyarea;
	cout<< "Enter your gender: ";
	cin>> gender;
	cout<< "Enter your age: ";
	cin>> age;
	
	if(gender != 'M' && gender != 'F')
	{
		cout<< "Your input is invalid";
	}
	else if(gender == 'F')
	{
		urban=true;
		cout<< "You can work only in urban areas";
	}
	else if(gender == 'M' && age>20 && age<40)
	{
		anyarea=true;
		cout<< "You can work in any area";
	}
	else if(gender == 'M' && age>40 && age<60)
	{
		urban=true;
		cout<< "You can work only in urban areas";
	}
	else
	{
		cout<< "ERROR";
	}
	
	return 0;
}
