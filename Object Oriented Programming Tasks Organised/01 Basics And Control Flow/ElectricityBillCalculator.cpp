#include <iostream>
using namespace std;
int main()
{
//	int prevRead, currRead, units;
float cost;
cout << "Enter your previous reading: ";
cin >> prevRead;
cout << "Enter your current reading: ";
cin >> currRead;
//
units = currRead - prevRead; //calculates the units used
if (units < 0) //checks if units are not in negative which is not possible
	cout << "Invalid entry found";
else
{
//		//following if condition checks the number of units and accordingly performs calculation as is done 
	if (units < 100)
		cost = units * 6;
	else if (units > 101 && units < 300)
		cost = units * 7.5 * 1.1;
	else if (units > 300)
		cost = units * 9 * 1.2;
//		
	cout << "Your total cost is: " << cost; //outpus the final cost
}
//
return 0;
}
