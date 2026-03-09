#include<iostream>
#include<string>
using namespace std;
int main()
{
int size;
string text;
cout << "Enter a string: ";
getline(cin, text);
size = text.length();
for(int i=0; i<size; i++)
{
	if (text[i] == 'z')
	{
		text[i] = 'a';
		cout << text[i];
	}
	else if (text[i] == 'Z')
	{
		text[i] = 'A';
		cout << text[i];
	}
	else
	{
		cout << ++text[i];
	}
}
//
return 0;
}
