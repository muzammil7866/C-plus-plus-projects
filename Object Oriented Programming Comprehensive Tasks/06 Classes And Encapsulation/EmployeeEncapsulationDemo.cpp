#include <iostream>
using namespace std;
struct distancee //structure named 'distance' is defined
{
//	//block of code shows the attributes of the structure 'distance'
int feet; 
float inches;
//
};
int main()
{
distancee d1; //object 'd1' of data type 'distancee' is declared
cout << "Enter the feets of Room 1: ";
cin >> d1.feet; //inputs the number of feets of Room1
cout << "Enter the inches of Room 1: ";
cin >> d1.inches; //inputs the number of feets of Room1
//
//	
distancee d2; //object 'd1' of data type 'distancee' is declared
//	
//	//Attributes of room 2 are defined
d2.feet = 10;
d2.inches = 5.25;
//
//
distancee d3;
d3.feet = d1.feet + d2.feet; //feets of Room 1 and Room 2 are added and stored in the attribute 'feet' of d3
d3.inches = d1.inches + d2.inches; //Inches of Room 1 and Room 2 are added and stored in the attribute 'inches' of d3
//
if (d1.inches > 12.0) //checks if the inches of Room 1 exceeds 12 (a foot)
{
	d1.feet = (d1.inches / 12) + d1.feet; //adds the respective feets into the feets of Room 1 by making calculation using the inches
	d1.inches = d1.inches - 12*int((d1.inches/12)); //subtracts the respective number of inches of Room 1 according to the feets from the inches of Room 1 as the corresponding feets have already been added  
}
//
if (d2.inches > 12.0)
{
	d2.feet = (d2.inches / 12) + d2.feet; //adds the respective feets into the feets of Room 2 by making calculation using the inches
	d2.inches = d2.inches - 12 * int((d2.inches / 12)); //subtracts the respective number of inches of Room 2 according to the feets from the inches of Room 2 as the corresponding feets have already been added
}
//
if (d3.inches > 12.0)
{
	d3.feet = (d3.inches / 12) + d3.feet; //adds the respective feets into the feets of Room 3 by making calculation using the inches
	d3.inches = d3.inches - 12 * int((d3.inches / 12)); //subtracts the respective number of inches of Room 3 according to the feets from the inches of Room 3 as the corresponding feets have already been added
}
//
//
cout << "Room 1 has size "<<d1.feet << " Feet(s) and " << d1.inches << " Inche(s)."<<endl; //prints the feets and inches of Room 1
cout << "Room 2 has size "<<d2.feet << " Feet(s) and " << d2.inches << " Inche(s)." << endl; //prints the feets and inches of Room 2
cout << "Room 3 has size "<<d3.feet << " Feet(s) and " << d3.inches << " Inche(s)." << endl; //prints the feets and inches of Room 3
//	
//	
return 0;
}
#include <iostream>
using namespace std;
struct distancee //structure named 'distance' is defined
{
//	//block of code shows the attributes of the structure 'distance'
int feet; 
float inches;
//
};
int main()
{
distancee d1; //object 'd1' of data type 'distancee' is declared
cout << "Enter the feets of Room 1: ";
cin >> d1.feet; //inputs the number of feets of Room1
cout << "Enter the inches of Room 1: ";
cin >> d1.inches; //inputs the number of feets of Room1
//
//	
distancee d2; //object 'd1' of data type 'distancee' is declared
//	
//	//Attributes of room 2 are defined
d2.feet = 10;
d2.inches = 5.25;
//
//
distancee d3;
d3.feet = d1.feet + d2.feet; //feets of Room 1 and Room 2 are added and stored in the attribute 'feet' of d3
d3.inches = d1.inches + d2.inches; //Inches of Room 1 and Room 2 are added and stored in the attribute 'inches' of d3
//
if (d1.inches > 12.0) //checks if the inches of Room 1 exceeds 12 (a foot)
{
	d1.feet = (d1.inches / 12) + d1.feet; //adds the respective feets into the feets of Room 1 by making calculation using the inches
	d1.inches = d1.inches - 12*int((d1.inches/12)); //subtracts the respective number of inches of Room 1 according to the feets from the inches of Room 1 as the corresponding feets have already been added  
}
//
if (d2.inches > 12.0)
{
	d2.feet = (d2.inches / 12) + d2.feet; //adds the respective feets into the feets of Room 2 by making calculation using the inches
	d2.inches = d2.inches - 12 * int((d2.inches / 12)); //subtracts the respective number of inches of Room 2 according to the feets from the inches of Room 2 as the corresponding feets have already been added
}
//
if (d3.inches > 12.0)
{
	d3.feet = (d3.inches / 12) + d3.feet; //adds the respective feets into the feets of Room 3 by making calculation using the inches
	d3.inches = d3.inches - 12 * int((d3.inches / 12)); //subtracts the respective number of inches of Room 3 according to the feets from the inches of Room 3 as the corresponding feets have already been added
}
//
//
cout << "Room 1 has size "<<d1.feet << " Feet(s) and " << d1.inches << " Inche(s)."<<endl; //prints the feets and inches of Room 1
cout << "Room 2 has size "<<d2.feet << " Feet(s) and " << d2.inches << " Inche(s)." << endl; //prints the feets and inches of Room 2
cout << "Room 3 has size "<<d3.feet << " Feet(s) and " << d3.inches << " Inche(s)." << endl; //prints the feets and inches of Room 3
//	
//	
return 0;
}
