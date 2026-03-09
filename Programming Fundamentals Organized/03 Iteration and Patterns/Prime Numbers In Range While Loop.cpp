#include <iostream>
using namespace std;
int main()
{	
	long int primecount=0, startnum, endnum, currentnum, count;
	bool prime;
	
	cout<<"Enter the starting number: ";
	cin>>startnum;
	cout<<"Enter the ending number: ";
	cin>>endnum;
	
	cout<<"Prime numbers are: "<<endl;
	
	while(startnum<=endnum)
	{
		currentnum=startnum;
		count=2;
		prime=true;
		
		if(currentnum==1)
		{
			prime=false;
		}
		
		if(currentnum==2)
		{
			prime=true;
			primecount++;
			cout<<currentnum<<endl;
		}
		
		if(currentnum>2)
		{
			while(count<currentnum)
			{
				if(currentnum%count==0)
				{
					prime=false;
				}
				count++;
			}
			
			if(prime==true)
			{
				primecount++;
				cout<<currentnum<<endl;
			}
		}
		
		startnum++;
	}
	
	cout<<"Total prime numbers are: "<<primecount;

	return 0;	
}
