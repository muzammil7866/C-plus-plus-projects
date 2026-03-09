#include <iostream>
using namespace std;
bool palindrome(int num);
int main()
{
	int num=0;
	bool palindrome2 = false;
	cout << "Enter the number to check if it is a palindrome or not: ";
	cin >> num;
	palindrome2 = palindrome(num);
	
	if (palindrome2 == true)
	{
		cout << endl<<"Your number is a palindrome number";
	}

	else {
		cout << endl << "Your number is not a palindrome number";
	}
	return 0;
}

bool palindrome(int num)
{
	int rem;
	int sum = 0;
	int dig = 0;
	rem = num;
	do
	{
		dig = rem % 10;
		rem = rem / 10;
		sum = sum + dig;
		cout << dig;
	} while (rem > 0);

	cout <<endl<< sum;
	if (sum == num)
	{
		return true;
	}

	else
	{
		return false;
	}
}

	