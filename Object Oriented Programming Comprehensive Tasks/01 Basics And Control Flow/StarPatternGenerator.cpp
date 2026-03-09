#include <iostream>
using namespace std;
int main()
{
for (int i = 1; i <= 10; i++) //for rows increasing
{
	for (int j = 1; j <= i; j++) //for cols being run till the number of rows
	{
		cout <<"*";
	}
	cout << endl;
}
//
cout << endl;
for (int i = 1; i <= 10; i++) //for rows increasing
{
	for (int j = 10; j >= i; j--) //column is one less each time the row is incremented
	{
		cout<<"*";
	}
//
	cout << endl;
}
//
cout << endl;
//
for (int i = 1; i <= 10; i++) //for rows increasing 
{
	for (int space = 10 - i; space > 0; space--) //space decreases one at a time when the row increases
		cout << " ";
	for (int j = 1; j <= i; j++) //column increases with the increase in row
		cout << "*";
//		
	cout << endl;
}
//
cout << endl;
//
for (int i = 1; i <= 10; i++) //for rows increasing
{
	for (int space = 1; space <= i; space++) //space is increased one at a time with the increase in the row
		cout << " ";
	for (int j = 10; j >= i; j--) // column decreases one at a time with the increase in the row
	{
		cout << "*";
	}
	cout << endl;
}
//
//
}
