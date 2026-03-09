#include <iostream>
using namespace std;


void prime(int a, int b);
int main()
{
	int num1, num2;
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	prime(num1, num2);

	return 0;
}

void prime(int a, int b)
{
	cout << "Prime Numbers are: ";
	while (a <= b)
	{
		if (a == 2)
		{
			cout << a <<" ";
		}

		if (a % 2 != 0 && a!=2 && a!= 1)
		{
			cout << a<< " ";
		}
		
		a++;
	}
}