//THIS QUESTION RECURSIVELY CONVERTS A NUMBER FROM BASE 10 INTO BASE 8 AND BASE 16
#include <iostream>
using namespace std;
int convertingTo8(int num) //CONVERTS BASE DECIMAL TO BASE OCTAL
{
	if (num < 8)
	{
		return (num);
	}

	return num % 8 + 10 * convertingTo8(num / 8); 
	
}

int convertingTo16(int num) //CONVERTS BASE DECIMAL TO BASE HEXADECIMAL
{
	if (num < 16)
	{
		return num;
	}

	return num % 16 + 10 * convertingTo16(num / 16);
}
int main()
{
	int num;
	cout << "ENTER A NUMBER IN BASE 10 TO CONVERT IT INTO ANOTHER BASE (DO NOT FORGET TO WRITE 10 WITHOUT A SPACE AT THE END OF THE NUMBER TO DENOTE THE BASE) : ";
	cin >> num;

	cout<<"YOUR NUMBER IS: "<<num / 100<<endl;

	cout << "ANSWER AFTER CONVERSION TO BASE 8: ";
	cout << convertingTo8(num / 100)<<8<<endl;
	//cout<<convertingTo16(num / 100)<<16;



	return 0;	
}
