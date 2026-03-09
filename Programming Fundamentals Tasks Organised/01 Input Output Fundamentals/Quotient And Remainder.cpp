#include <iostream>
using namespace std;
int main()
{
	int divisor,dividend, quo, rem;
	cout<< "Enter the Divisor: "<<endl;
	cin>> divisor;
	cout<< "Enter the Dividend: ";
	cin>> dividend;
	
	quo= dividend/divisor;
	rem= dividend%divisor;
	
	cout<< "Quotient is: " << quo << endl;
	cout<< "Remainder is: " << rem;
	
	return 0;
}
