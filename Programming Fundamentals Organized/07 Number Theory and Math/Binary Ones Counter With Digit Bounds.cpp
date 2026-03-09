#include <iostream>
using namespace std;
int main()
{
	int num, digitsanalyser=0, onecounter=0, thisdigit=0;
	cout<<"Enter your Binary Number: ";
	cin>>num;
	
	while(num>=1)
	{
		thisdigit = num%10;
		num = num/10;
		if(thisdigit == 1)
		{
			onecounter++;
		}
		else if(thisdigit != 1 && thisdigit!= 0)
		{
			cout<<"Incorrect input! It is not a binary number ";
			break;
		}
		digitsanalyser++;
	}
	
	if(digitsanalyser>6 && digitsanalyser<10)
	cout<<"Number of 1s in your binary number are: "<<onecounter<<endl;
	
	if(digitsanalyser<6)
	{
		cout<<"Digits are less than six";
	}
	
	else if(digitsanalyser>10)
	{
		cout<<"Digits are greater than ten";	
	}

	return 0;	
}
