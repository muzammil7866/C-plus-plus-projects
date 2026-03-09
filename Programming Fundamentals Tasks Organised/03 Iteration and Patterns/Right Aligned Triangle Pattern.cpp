#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int size, spacer;
	
	cout<<"Enter the size of your triangle: "<<endl;
	cin>>size;
	spacer=size;
	
	for(int i=1;i<=size;i++)
	{
		cout<<setw(spacer);
		
		for(int j=1; j<=i;j++)
		{	
			cout<<"*";
		}
		cout<<endl;
		spacer--;
	}
	
	
	
	
	
	return 0;	
}
