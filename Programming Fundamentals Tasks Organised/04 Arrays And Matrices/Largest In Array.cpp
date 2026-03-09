#include <iostream>
using namespace std;
int main()
{	
	int a[5], largest;
	
	for(int i=0;i<5;i++)
	{
		cout<<"Enter number in index "<<i<<": "<<endl;
		cin>>a[i];
	}
	
	cout<<"Your array is: "<<endl;
	for(int k=0;k<5;k++)
	{	
		cout<<a[k]<<" ";
	}
	
	cout<<endl;
	
	largest = a[0];
	
	for(int j=0;j<5;j++)
	{
		if(largest<=a[j])
		{
			largest = a[j];
		}
	}
	
	cout<<"The largest of the numbers is: "<<largest;
	
	
	
	return 0;	
}
