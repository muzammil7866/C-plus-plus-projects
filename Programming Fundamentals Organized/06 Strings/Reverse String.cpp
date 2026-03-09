#include <iostream>
#include <string>
using namespace std;
int main()
{
int size;
string text;
cout << "Enter the word to invert it: ";
cin >> text;
//
size = text.length();
//
for (int i = size; i >= 0; i--)
{
	cout << text[i];
}
//
//
//
return 0;
}
