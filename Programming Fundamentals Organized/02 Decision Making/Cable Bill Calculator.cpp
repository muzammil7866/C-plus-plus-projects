#include <iostream>
using namespace std;
int main()
{	
	int AccountNo, PremiumChannels, Connections;
	float TotalBill;
	char CustomerCode;
	
	cout<<"Enter your Account Number: ";
	cin>>AccountNo;
	cout<<"Enter your Customer Code: ('R' or 'r' for Residential and 'B' or 'b' for Business): ";
	cin>>CustomerCode;
	cout<<"Enter the required number of Premium Channels:  ";
	cin>>PremiumChannels;
	
	if(CustomerCode=='R' || CustomerCode == 'r')
	{
		TotalBill = 4.5 + 20.5 + 7.5*PremiumChannels;
		cout<<endl<<"Account Number: "<<AccountNo<<endl;
		cout<<"Your total bill is: $"<<TotalBill;
	}
	
	else if(CustomerCode=='B' || CustomerCode == 'b')
	{
		cout<<"Enter the required number of connections: ";
		cin>>Connections;
		
		if(Connections<=10)
		{
			TotalBill = 15.5 + 75.5	+ 50.5*PremiumChannels;
			cout<<endl<<"Account Number: "<<AccountNo<<endl;
			cout<<"Your total bill is: $"<<TotalBill;
		}
		
		else if(Connections>10)
		{
			TotalBill = 15.5 + 75.5 + 5*(Connections - 10) + 50.5*PremiumChannels;
			cout<<endl<<"Account Number: "<<AccountNo<<endl;
			cout<<"Your total bill is: $"<<TotalBill;
		}
	}
	
	else
	{
		cout<<"Customer Code is invalid";
	}	
	
	return 0;
}
