#include <iostream>
#include<string>
using namespace std;
bool palindrome(char a[], int size, int i) //checks if is palindrome
{

	if (i == size/2) //half size
	{
		return true;
	}

	else
	{
		if (a[i] == a[size - 1 - i]) //comparing from start and last correspondingly
		{
			
			palindrome(a, size, i+1); //next recursive iteration
		}

		else
		{
			return false;
		}
	}
}
int main()
{
	char text[6] = "madam";
	char text2[6] = "madam";

	int count = 0;

	//while (text[count] != '\0')
	{
		count++;
	}

	cout << palindrome(text,count, 0)<<endl;
	cout << palindrome(text2, count, 0);

	return 0;	
}
