#include <iostream>
using namespace std;
int main()
{
	int a[5], count, countofindex, maxcount=1, mostoccuring, arrayindexcount=0;
	
	for(int i=0;i<5;i++)
	{
		cout<<"Enter number in index "<<i<<": "<<endl;
		cin>>a[i];
	}
	
	
	countofindex = 0;
	count = 1; 
	
	while(arrayindexcount<5)
	{
		if(a[countofindex]==a[arrayindexcount])
		{
			arrayindexcount++;
			
		}
		
		if(maxcount<count)
		{
			maxcount = count;
		}
		
	}
	
	cout<<maxcount;
	
	
	
	return 0;	
}
