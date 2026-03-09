#include <iostream>
using namespace std;
int main()
{
	long int numofterms, valueofx, thispowervalue;
	float 	sum = 1, thisfactorial = 1;
	
	cout<<"Till how many terms do you want the sum to be: ";
	cin>>numofterms;
	cout<<"Enter the value of x: ";
	cin>>valueofx;
	
	thispowervalue=valueofx;
	
	for(int i=0; i<numofterms-1; i++)
	{
		for(int j=0; j<i;j++)	//for value of x
		{
			thispowervalue = thispowervalue*valueofx;
		}
		
		
		for(int k=1; k<=i;k++)
		{
			thisfactorial = thisfactorial*(i+1);
		}
		
		
		sum = sum + (thispowervalue/thisfactorial);
	}

	cout<<"The value of sum is: "<<sum;

	return 0;	
}
