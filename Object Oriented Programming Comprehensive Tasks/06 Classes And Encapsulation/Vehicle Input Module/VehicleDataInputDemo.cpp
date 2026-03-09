#include<iostream>
#include "Vehicle.h"
#include <string>
using namespace std;
int main()
{
vehicle obj1;
cout << "ENTER THE MODEL OF VEHICLE: ";
getline(cin >> ws, obj1.name);
cout << "ENTER THE PRICE OF THE VEHICLE: ";
cin >> obj1.price;

cout << "MODEL: " << obj1.name << endl;
cout << "PRICE: " << obj1.price << endl;

return 0;
}
