#include <iostream>
using namespace std;
int sum(int num);
int main()
{
int num;
cout << "Enter your number: "; 
cin >> num;
cout<<"Sum of digits is: "<<sum(num)<<endl; //function call is made which returns the sum of digits
//
//
return 0;
}
//
int sum(int num)
{
if (num==0) //base case which would end the call when the last digit of the number is 0
{
	return 0; //returns zero which would have no impact on adding the digits
}
else
{
	return num % 10 + sum(num / 10); //the remaining digits of the number are further passed to the function to work on the other digits. However, the previous digit is added to the next function to add that digit
}
//
}
