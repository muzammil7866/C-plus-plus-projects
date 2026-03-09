#include <iostream>
using namespace std;
int main()
{
//	float num1, num2;
//
cout << "ENTER NUMBER 1 AS NUMERATOR: ";
cin >> num1;
cout << "ENTER NUMBER 2 AS DENOMINATOR: ";
cin >> num2;
//
//	try 
{
	if (num2 == 0)
	{
//			throw(num2);
	}
//
	else
	{
		cout << num1 << "/" << num2 << "= " << num1 / num2<<endl;
//
	}
}
//
//	catch (float num2)
{
	cout << "DENOMINATOR COULD NOT BE ZERO! "<<endl;
}
//
//
return 0;	
}
