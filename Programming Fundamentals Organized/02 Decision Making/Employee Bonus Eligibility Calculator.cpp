#include <iostream>
using namespace std;
int main()
{
	int age, gender, basicpay, bonus, moreemployee = 1;
	
	while(moreemployee != 0)
	{
		cout<<"Enter the gender of employee"<<endl;
		cout<<"(1 for MALE and 2 for FEMALE): ";
		cin>>gender;
		if(gender == -999)
			{
				break;
			}
		
		else
		{	
			cout<<"Enter the age of employee: ";
			cin>>age;
				if(age == -999)
				{
				break;
				}

				else
				{
					cout<<"Enter the 'Basic Pay' of an employee: ";
					cin>>basicpay;
						if(basicpay == -999)
						{
							break;
						}
			
						else
						{
								if(gender == 1 && age>30 && basicpay > 25000)
									{
										bonus = 0.25*basicpay;
										cout<<"This employee gets bonus amount: "<<bonus<<endl;
									}
									
								else if(gender == 1 && age<30 && basicpay > 21000)
									{
										bonus = 0.17*basicpay;
										cout<<"This employee gets bonus amount: "<<bonus<<endl;
									}
									
								else if(gender == 2 && age<25 && basicpay>18000)
									{
										bonus = 0.13*basicpay;
										cout<<"This employee gets bonus amount: "<<bonus<<endl;
									}
									
								else
									{
										cout<<"This employee gets no bonus!"<<endl;
									}
								
								cout<<"Do you want to enter another Employee details: ";
								cout<<"(Enter 0 to STOP and 1 to CONTINUE): ";
								cin>>moreemployee;
									if(moreemployee == -999)
									{
										break;	
									}	
						}
			
			}
		
		
			
		
		
	
	}

	}
	return 0;	
}
