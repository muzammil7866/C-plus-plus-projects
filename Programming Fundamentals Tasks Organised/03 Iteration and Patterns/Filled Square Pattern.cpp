#include<iostream>
using namespace std;
void square(int size);
int main()
{
int size = 0;
cout << "Enter the size of your square: ";
cin >> size;
square(size);
//
//
}
//
void square(int size)
{
cout << endl << endl;
for (int i = 0; i < size;i++)
{
	for (int j = 0;j < size;j++)
	{
		cout << "*  ";
	}
	cout << endl;
}
}
