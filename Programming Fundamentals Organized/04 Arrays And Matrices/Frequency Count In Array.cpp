#include <iostream>
using namespace std;
int main()
{
	
	int a[5], count, currentcheck, maxcount=1, maxcountindex;
	
	for(int i=0;i<5;i++)
	{
		cout<<"Enter number in index "<<i<<": "<<endl;
		cin>>a[i];
	}	
	
	for(int j=0; j<5; j++)
	{
		for(int k=0; k<5; k++)
		{
			currentcheck=a[j];
			
			if(currentcheck == a[k])
			{
				count++;
				cout<<currentcheck;
				
			}
			
		}
		
		if(maxcount<count)
			{
				maxcount = count;
				cout<<"Maximum occuring value is: "<< currentcheck;
			}
	}
	
	if(maxcount == 2)
	{
		cout<<"There is no more repeating number";
	}
	
	
	return 0;	
}
