#include <iostream>
using namespace std;
int main()
{
	int size, spacer;
	
	cout<<"Enter the size of your diamond: "<<endl;
	cin>>size;
	
	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<"@";
		}
		cout<<endl;
	}
	
	for(int k=size-1;k>=1;k--)
	{
		for(int n=1;n<=k;n++)
		{
			cout<<"@";
		}
		cout<<endl;
	}
	
	
	
	
	return 0;	
}
