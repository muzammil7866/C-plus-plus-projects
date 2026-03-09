#include <iostream>
using namespace std;
int main()
{
	int a=1, num2, num3, b, col=1, row;
	
	for(int i=1;i<=5;i++)
	{	
		row=i;
			for(int j=4;j>=i;j--)
			{
				cout<<" ";
			}
	
	
			for(int num2=1;num2<=row; num2++ )
			{
				cout<<a;
				a++;
			}
			

			
			for(int num3=1;num3<=row-1; num3++)
			{
				cout<<--a;
			}
	
	col= col+2;
	cout<<endl;
	
	}
		
	
	
	return 0;	
}
