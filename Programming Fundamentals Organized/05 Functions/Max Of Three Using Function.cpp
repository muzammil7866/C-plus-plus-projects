#include <iostream>
using namespace std;
int findmax(int a, int b, int c);
int main()
{
	int num1, num2, num3, largest;
	cout << "Enter number 1: ";
	cin >> num1;
	cout << "Enter number 2: ";
	cin >> num2;
	cout << "Enter number 3: ";
	cin >> num3;
	largest = findmax(num1, num2, num3);
	cout << "Maximum among the three integers is: "<<largest;
	return 0;
}

int findmax(int a, int b, int c)
{
	if (a >= b && a >= c)
	{
		return a;
	}

	else if (b >= a && b >= c)
	{

		return b;
	}

	else
	{
		return c;
	}
}