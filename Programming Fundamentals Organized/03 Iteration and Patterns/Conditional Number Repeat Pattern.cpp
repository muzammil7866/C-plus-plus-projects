#include <iostream>
using namespace std;
int main()
{
	int n, temp;
	
	cout<<"Enter your number: ";
	cin>>n;
	
	if(n>5)
	{
		
		if(n%5 == 0)
		{
			temp = n/2;
			
			for(int i=0; i<temp; i++)
			{
				cout<<n;
			}
			
		}
		
		else
		{
			temp = n/3;
			
			for(int i=0; i<temp; i++)
			{
				cout<<n;
			}
		}
	}
	
	else
	{
		cout<<"Incorrect Input!";
	}
	
	
	return 0;	
}
