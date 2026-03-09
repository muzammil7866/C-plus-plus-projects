#include <iostream>
#include<math.h>
using namespace std;
int reverse(int);
int main()
{
int num;
cout << "Enter a four-digit number: ";
cin >> num;
//	
cout << reverse(num);
//
return 0;
}
//
int reverse(int num) //reverses the digit one by one
{
//	int dig, rem = num;
int count= 3;
int num2 = 0;
//
while (rem > 0)
{	
	dig = (rem % 10)*pow(10, count); //obtains the last digit in the number and adds weightage through power function
	rem = rem / 10; //remaining number is obtained
//
	num2 = num2 + dig;
//		count--;
}
//
return num2;
}
