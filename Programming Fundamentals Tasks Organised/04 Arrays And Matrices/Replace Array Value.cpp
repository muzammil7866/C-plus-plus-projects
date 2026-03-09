#include <iostream>
using namespace std;
int main()
{
	int a[10], atoldvalue, newvalue, replacecount;
	
	
	for(int i=0;i<10;i++)
	{
		cout<<"Enter number in index "<<i<<": "<<endl;
		cin>>a[i];
	}

	cout<<"Enter the number which you want to update: ";
	cin>>atoldvalue;
	cout<<"Enter the updated number: ";
	cin>>newvalue;

	for(int j=0;j<10;j++)
	{
		if(a[j] == atoldvalue)
			{
				a[j] = newvalue;
				replacecount++;
			}		
			
	}
	
	if(replacecount==0)
	{
		cout<<"The value does not exist or the array is empty";
	}
	
	cout<<"Your array is: "<<endl;
	
	for(int n=0;n<10;n++)
	{
		cout<<a[n]<<" ";
	}
	return 0;	
}
