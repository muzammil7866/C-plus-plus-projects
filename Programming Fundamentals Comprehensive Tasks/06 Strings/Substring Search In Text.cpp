#include <iostream>
#include <string>
using namespace std;
int main()
{

	string text;
	int size = 0;
	cout << "Enter your text: ";
	getline(cin, text);
	size = text.size();

	cout << "Enter the substring that you want to find from the text: ";
	string substring;
	getline(cin, substring);

	string::size_type pos = text.find(substring);

	if (pos == string::npos)
	{
		cout << "Your substring is not found" <<endl;;
	}
	else
	{
		cout << "Your substring is found at index: " << pos;
	}

}