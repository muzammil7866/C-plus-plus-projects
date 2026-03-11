#include <iostream>
using namespace std;
int GCD(int num1, int num2, int n) //calculates higest common divider
{
	
	if (num1 % n == 0 && num2 % n == 0) //both are factors
		return n;

	else
	{
		return GCD(num1, num2, n - 1); //one less than the number
	}
}
int main()
{
	int num1, num2;
	cout << "ENTER TWO NUMBERS: (SEPERATED BY SPACE): ";
	cin >> num1 >> num2;

	if (num1 >= num2)
	{
		cout<<GCD(num1, num2, num2); //first one is high in both cases
	}
	
	else
	{
		cout<<GCD(num2, num1, num1); 
	}



	return 0;	
}
