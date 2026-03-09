#include <iostream>
using namespace std;
int main()
{	
	bool end= false;
	int num, num2, larger;
	cout<<"Enter an integer: ";
	cin>>num;
	larger = num;
	while(end != true)
	{	
		cout<<"Do you want to enter more numbers: (Enter 1 for Yes and 0 for No): ";
		cin>>end;
		
		if(end==0)
		{
			end = true;
			cout<< "The largest integer is: "<<larger;
		}
		
		else if(end == 1)
		{
			cout<<"Enter the next integer: ";
			cin>>num2;
			if(num2>=num)
			{
				larger = num2;
				num = num2;
				end = false;
			}
			
			else
			{
				larger = num;
				num= num2;
				end = false;
			}
		}
	}
	return 0;	
}
