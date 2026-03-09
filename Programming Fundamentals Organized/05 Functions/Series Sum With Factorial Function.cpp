#include <iostream>
using namespace std;

int fact(int num);
double division(double num, double f);
int main()
{
	int factorial = 1, count = 1;
	double result2 = 0;
	int result1=0;
	double sum=0;
	while (count <= 7)
	{
		result1	= fact(factorial);
		result2 = division(count, result1);
		sum = sum + result2;
		cout << result2<< " ";
		count++;
		factorial++;		
	}
	
	cout <<endl<< "Sum is: "<<sum;
	return 0;	
}

int fact(int num)
{
	int fact=1;

	for (int i = 1; i <= num; i++)
	{
		fact = fact * i;
	}
	return fact;
}

double division(double num, double f)
{
	double result=0;
	result = num / f;
	return result;
}