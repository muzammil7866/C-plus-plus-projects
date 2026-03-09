#include <iostream>
using namespace std;
int main()
{
	int size, count, count2;
	count = 0;
	count2 = 0;
	cout<<"Enter the size of your triangle: ";
	cin>> size;
	while(count<size)
	{		
		
		while(count2<=count)
		{
		cout<<"*";
		count2++;	
		}
		cout<<endl;
		count++;
		count2=0;
	}
	
	return 0;
}
