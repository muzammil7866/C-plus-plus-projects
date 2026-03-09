#include <iostream>
using namespace std;
bool karatosDestruction(double num1, double num2, double num3);
/*bool karatosDestruction(int num1, int num2, int num3);
bool karatosDestruction(int num1, double num2, double num3);
bool karatosDestruction(double num1, int num2, double num3);
bool karatosDestruction(double num1, double num2, int num3);
bool karatosDestruction(int num1, int num2, double num3);
bool karatosDestruction(double num1, int num2, int num3);
bool karatosDestruction(int num1, double num2, int num3);*/
//
int main()
{
bool same = false;
while (same != true)
{
	int num1 = 0, num2 = 0, num3 = 0;
	cout << "Enter three numbers one by one: ";
	cin >> num1 >> num2 >> num3;
	same = karatosDestruction(num1, num2, num3);
//
	if (same == false)
	{
		cout << "Mismatch found! repeat your process.\n";
	}
//	
}
return 0;
}
//
bool karatosDestruction(double num1, double num2, double num3)
{
double result = 1;
for (int i = 0; i < num2;i++)
	result = result * num1;
//	
//	
if (num3 == result)
	return true;
//
else
	return false;
}
