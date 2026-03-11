#include<iostream>
using namespace std;
int main()
{
	char a;
	cout << "ENTER ANY CHARACTER: ";
	cin >> a; 

	if (a >= 65 && a <= 90)
	{
		int b = a - 65;
		a = 97 + b;
	}

	cout << a;





	return 0;
}