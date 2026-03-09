#include <iostream>
using namespace std;
int main()
{
	long int num, count =0, dig, a[10]={0}, i=0, count2=0, sum=0, count3=0;	
	cout<<"Enter your number: ";
	cin>>num;
	
	while(num>10)
	{
		dig = num%10;
		num = num/10;
		count++;
		
		a[i] = dig;
		i++;
		
	}
	
	a[i] = num;
	count++;
	
	count3 = count;
	
	for(int j=0;j<count;j++)
	{
		while(count2<count3-1)
		{
			a[j] = a[j]*10;
			count2++;	
		}
		
		count2=0;
		count3--;
	}
	
	for(int i=0; i<count; i++)
	{
		sum = sum + a[i];
	}
	
	num = sum;
	
	
	while(num>10)
	{
		dig = num%10;
		num = num/10;
		

		switch(dig)
		
		{

			case 0:		
				cout<<"Zero ";
				break;
			case 1:
				cout<<"One ";
				break;
			case 2:
				cout<<"Two ";
				break;
			case 3:
				cout<<"Three ";
				break;
			case 4:
				cout<<"Four ";
				break;
			case 5:
				cout<<"Five ";
				break;
			case 6:	
				cout<<"Six ";
				break;
			case 7:
				cout<<"Seven ";
				break;
			case 8:
				cout<<"Eight ";
				break;
			case 9:
				cout<<"Nine ";
				break;
		
		}
		
	}
	
		switch(num%10)
		
		{	
			case 0:		
				cout<<"Zero ";
				break;
			case 1:
				cout<<"One ";
				break;
			case 2:
				cout<<"Two ";
				break;
			case 3:
				cout<<"Three ";
				break;
			case 4:
				cout<<"Four ";
				break;
			case 5:
				cout<<"Five ";
				break;
			case 6:	
				cout<<"Six ";
				break;
			case 7:
				cout<<"Seven ";
				break;
			case 8:
				cout<<"Eight ";
				break;
			case 9:
				cout<<"Nine ";
				break;
	
	
	
	return 0;	
	
}
}
