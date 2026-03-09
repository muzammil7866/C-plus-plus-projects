#include<iostream>
using namespace std;
double* momentum(double* velocity, double mass); //function prototype
int main()
{
double* array = new double[3]; //dynamically allocates memory for array
cout << "Enter the velocity of the function as follwing: "<<endl;
cout << "x= ";
cin >> *(array); //takes input for the x component of velocity
cout << "y= ";
cin >> *(array+1); //takes input for the y component of velocity
cout << "z= ";
cin >> *(array + 2); //takes input for the z component of velocity
cout << "Enter the value for your scalar mass: ";
double mass;
cin >> mass; //takes input for the mass
//	momentum(array, mass); //mass and the array is passed onto the function
//
//
return 0;
}
//
double* momentum(double* velocity, double mass)
{
//	double m1, m2, m3;
//	//calculates the momentum of each component of velocity, stored in each variable 
m1 = *(velocity)*mass; 
m2 = *(velocity+1)*mass;
m3 = *(velocity+2)*mass;
//
//	//displays the momentums
cout << "Momentum due to x = " << m1<<endl;
cout << "Momentum due to y = " << m2 << endl;
cout << "Momentum due to z = " << m3 << endl;
//
double* momentumm = new double[3]; //dynamically allocates memory for the array
//	*(momentumm) = m1;
//	*(momentumm+1) = m2;
//	*(momentumm+2) = m3;
//
return momentumm; //returns the pointer to the momentum array
//
}
