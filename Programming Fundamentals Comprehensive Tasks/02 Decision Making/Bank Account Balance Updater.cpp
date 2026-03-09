#include <iostream>
using namespace std;
int main()
{
		int AccountNo, MinimumBalance, CurrentBalance;
		char AccountType;
		
		cout<<"Enter your Account Number: ";
		cin>>AccountNo;
		cout<<"Enter your Account Type: ('s' for Savings and 'c' for Checking): ";
		cin>>AccountType;
		cout<<"Enter your Current Balance: ";
		cin>>CurrentBalance;
		cout<<"Enter the Minimum Balance that needs to be maintained: ";
		cin>>MinimumBalance;
		
		switch(AccountType)
		{
			case 's' : 
				if(CurrentBalance<MinimumBalance)
				{
					CurrentBalance = CurrentBalance - 10;
					cout<<endl<<"Account Number: "<<AccountNo<<endl;
					cout<<"Account Type: Savings"<<endl;
					cout<<"Your Current Balance is: $"<<CurrentBalance;
				}
				
				else if(CurrentBalance>=MinimumBalance)
				{
					CurrentBalance = CurrentBalance*1.1;
					cout<<endl<<"Account Number: "<<AccountNo<<endl;
					cout<<"Account Type: Savings"<<endl;
					cout<<"Your Current Balance is: $"<<CurrentBalance;
				}
				
				break;
		
			case 'c' : 
				if(CurrentBalance<MinimumBalance)
				{
				
					CurrentBalance = CurrentBalance - 25;
					cout<<endl<<"Account Number: "<<AccountNo<<endl;
					cout<<"Account Type: Checking"<<endl;
					cout<<"Your Current Balance is: $"<<CurrentBalance;
				}
				
				else if(CurrentBalance>=MinimumBalance)
				{
					CurrentBalance = CurrentBalance*1.07;
					cout<<endl<<"Account Number: "<<AccountNo<<endl;
					cout<<"Account Type: Checking"<<endl;
					cout<<"Your Current Balance is: $"<<CurrentBalance;
				}
				break;
				
				
			default :
			
				cout<<"Your Input for Account Type is invalid.";	
				break;		
		}
		
			return 0;
		}
