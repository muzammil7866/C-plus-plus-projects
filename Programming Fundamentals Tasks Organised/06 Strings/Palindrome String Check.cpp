#include <iostream>
#include <string>
using namespace std;
int main()
{
	string text;
	bool palindrome = true;
	cout << "Enter Word: ";
	getline(cin, text);
	int size = text.length();

	int checktill = size / 2;

	for (int i = 0, j = size-1; i<=checktill, j >= checktill; i++, j--)
	{
		if (text[i] == text[j])
		{
			palindrome = true;
		}
		else {
			palindrome = false;
			break;
		}
	}
	if (palindrome == false)
	{
		cout << "Word is not a palindrome ";
	}
	else {
		cout << "Word is a palindrome";
	}
		
		return 0;
	}