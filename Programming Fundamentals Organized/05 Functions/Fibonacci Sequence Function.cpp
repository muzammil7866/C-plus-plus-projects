#include <iostream>
using namespace std;

void fibonacci(int a);
int main()
{
	int count=0;
	cout << "Enter the number of terms of fibonacci sequence: ";
	cin >> count;
	fibonacci(count);

	return 0;
}

void fibonacci(int a)
{	

	int num1 = 0, num2 = 1, temp = 0;
	cout << num1 << " " << num2<< " ";
	int count = 2;
	while (count < a)
	{
		num1 = num2 + num1;
		cout << num1<< " ";
		count++;
	}

}