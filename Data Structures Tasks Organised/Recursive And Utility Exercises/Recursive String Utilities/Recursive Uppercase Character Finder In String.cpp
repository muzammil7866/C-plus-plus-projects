#include <iostream>
#include<string>
using namespace std;
bool isUpperCase(char a) //checks if is uppercase
{
	if (a >= 'A' && a <= 'Z') 
		return true;

	else
		return false;
}
char findUpper(char a[], int size, int i) //returns the first letter that is uppercase
{

	if (i == size-1)
	{
		cout<<"UPPERCASE NOT FOUND!";
	}

	else
	{
		if (isUpperCase(a[i]))
		{
			return a[i]; 
		}

		else
		{
			findUpper(a, size, i + 1); //next recursive iteration
		}
	}
}
int main()
{
	char text[15] = "meTa teTa";

	int count = 0;

	while (text[count] != '\0') //for size of string
	{
		count++;
	}

	cout << findUpper(text,count, 0)<<endl;


	return 0;	
}
