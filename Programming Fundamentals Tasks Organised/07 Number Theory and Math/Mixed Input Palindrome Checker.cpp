#include <iostream>
#include <string>
using namespace std;
bool palindrome(string text);
bool palindrome(int a);
int main()
{
	bool final = false;
	int choice = 0;
	cout << "Do you want to enter(1)string or (2)number: ";
	cin >> choice;
	if (choice == 1)
	{
		string text;
		cout << "Enter your text: ";
		cin >> text;
		final = palindrome(text);

		if (final == true)
		{
			cout << "It is a palindrome";
		}

		else
		{
			cout << "It is not a palindrome";
		}
	}

	else
	{
		int num = 0;
		cout << "enter your number";
		cin >> num;
		palindrome(num);
	}
	return 0;


}

bool palindrome(string text)
{
	int size = 0;
	bool palindrome = false;
	size = text.length();

	int checktill = size/ 2;

	for (int i = 0, j = 0; i<checktill, j>checktill; i++, j--)
	{
		if (text[i] == text[j])
		{
			palindrome = true;
		}
	}

	if (palindrome == false)
	{
		return false;
	}

	else
	{
		return true;
	}
}
bool palindrome(int a)
{
	int size = 0;
	bool palindrome = false;


	return false;
	
}