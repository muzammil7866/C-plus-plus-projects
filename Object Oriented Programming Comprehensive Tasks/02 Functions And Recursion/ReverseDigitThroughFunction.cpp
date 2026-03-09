#include<iostream>
using namespace std;
int reverse(int num);
int main()
{
int num;
cout << "Enter number: ";
cin>> num;

cout<<reverse(num);


return 0;
}

int reverse(int num)
{
int rem, dig;
rem = num;
int num2 = 0;
while (rem > 0)
{
	dig = rem % 10;
	rem = rem / 10;
	num2 = num2 * 10 + dig;
}
return num2;
}
