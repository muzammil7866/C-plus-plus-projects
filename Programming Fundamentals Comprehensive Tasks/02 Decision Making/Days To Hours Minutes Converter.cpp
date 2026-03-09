#include <iostream>
using namespace std;
int main()
{
	int days, minutes, hours;
	char a;
	cout<< "Enter number of days you want to convert: ";
	cin>> days;
	cout<<"Do you want to convert into HOURS or MINUTES\nEnter H for HOURS and M for MINUTES: ";
	cin>>a;
	if(a != 'H' && a!= 'M')
	{
		cout<< "Your input is invalid";
	}
	else if(a == 'M')
	{
		minutes= days*24*60;
		cout<< "Your minutes are: "<<minutes;
	}
	
	else if(a== 'H')
	{
		hours= days*24;
		cout<< "Your hours are:"<<hours;
	}
	return 0;
}
