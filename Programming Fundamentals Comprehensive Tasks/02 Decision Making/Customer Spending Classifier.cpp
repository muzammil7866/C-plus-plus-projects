#include <iostream>
using namespace std;
int main()
{
	int morecustomer = 1;
	float spendings;
	int count1=0, count2=0, count3=0, sum1=0, sum2=0, sum3=0;
	
	cout<<"Please enter the customer's spending: ";
	cin>>spendings;
	
	if(spendings>= 0 && spendings < 200.01)
	{
		count1++;
		sum1 = spendings;
	}

	else if(spendings>= 200.01 && spendings <800.01)
	{
		count2++;
		sum2 = spendings;
	}

	else if(spendings >= 800.01)
	{
		count3++;
		sum3 = spendings;
	}
	
	else
	{
		cout<<"Wrong input!"<<endl;
	}

		cout<<"Do you want to continue with adding another customer's spending: "<<endl;
		cout<<"(Enter 0 if you want to end or 1 if you want to continue): ";
		cin>>morecustomer;
		cout<<endl;
		
	while(morecustomer != 0 && morecustomer > 0)
	{
		cout<<"Please enter the customer's spending: ";
		cin>>spendings;
			
			if(spendings>= 0 && spendings < 200.01)
			{
				count1++;
				sum1 = sum1 + spendings;
			}
		
			else if(spendings>= 200.01 && spendings <800.01)
			{
				count2++;
				sum2 = sum2 + spendings;
			}
		
			else if(spendings >= 800.01)
			{
				count3++;
				sum3 = sum3 + spendings;
			}	
			
			else
			{
				cout<<"Wrong input!"<<endl;
			}	
			
		cout<<"Do you want to continue with adding another customer's spending: "<<endl;
		cout<<"(Enter 0 if you want to end or 1 if you want to continue): ";
		cin>>morecustomer;	
		cout<<endl;
		
		}	 

	cout<<"The total number of customer's with their spending between $0 to $200.01 are: "<<count1<<endl<<endl;
	cout<<"Total spendings between $0 to $200.01 are: "<<sum1<<endl<<endl;
	cout<<"The total number of customer's with their spending between inclusive $200.01 to $800.01 are: "<<count2<<endl<<endl;
	cout<<"Total spendings between $200.01 to $800 are: "<<sum2<<endl<<endl;
	cout<<"The total number of customer's with their spending $800.01 or more are: "<<count3<<endl<<endl;
	cout<<"Total spendings of $800.01 or more are: "<<sum3<<endl<<endl;
	
	
	return 0;	
}
