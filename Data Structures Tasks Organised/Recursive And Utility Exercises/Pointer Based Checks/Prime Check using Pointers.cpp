#include <iostream>
using namespace std;
bool primaryCheck(int* pnum);
int main()
{
	int num;
	cout << "\t\tENTER A NUMBER TO CHECK IF IT IS A PRIME ONE USING POINTER AND ADDRESS METHOD: "<<endl<<endl;

	cout << "Choose a number: ";
	cin >> num;
	int *pnum = &num; //address of number is passed to function for prime check
	bool prime = primaryCheck(pnum); 
	if (prime == true) //displays if the number is a prime number
		cout<<"Your number is a prime number"<<endl;

	else if(prime == false) //displays if the number is a prime number
		cout<<"Your number is not a prime number" << endl;
	
	return 0;
}
bool primaryCheck(int* pnum)
{
	bool prime = true;
	for (int i = 2; i < *pnum; i++) //loop would run till (i) reaches the number inputted
	{
		if (*pnum % i == 0) //checks if some number other than 1 and the number itself is divisible on the num
		{
			prime = false;
			return false; //returns false if nukber is a prime number
		}

	}

	return true; //returns true if number is prime
} 