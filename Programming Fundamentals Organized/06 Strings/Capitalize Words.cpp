#include <iostream>
#include <string>
using namespace std;
int main()
{
int size, count=1;
string text;
cout << "Enter your text: ";
getline(cin, text);
//	
size = text.length();
//
text[0] = toupper(text[0]);
while (count < size)
{
	if (text[count] == ' ')
	{
		text[count+1] = toupper(text[count + 1]);
	}
	count++;
}
//
cout << text;
//
return 0;
}
