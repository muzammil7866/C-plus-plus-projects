#include <iostream>
using namespace std;
int main()
{
	int triangle, rows, count = 0, count2 = 0, count3 =0, count4=0;
	char space = 32;
	
	cout<<"Choose the triangle option \nEnter 1 for Bottom up triangle\nEnter 2 for Bottom down triangle\nEnter 3 for Right triangle\nEnter 4 for Upside down right triangle: ";
	cin>>triangle;
	cout<<endl<<"Enter the number of rows of triangle: "<<endl;
	cin>>rows;
	
	
		
	switch(triangle)
	{
		case 3 :
			
			while(count<rows)
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
			break;
			
		case 4 :
			count2 = rows;
			count = 0;
			
			while(count<rows)
		{		
	
			while(count2>count)
			
			{
			cout<<"*";
			count2--;	
			}
			
			cout<<endl;
			count++;
			count2=rows;
		}
			break;
			
		case 2 :
			
			count2 = rows+1;
			count = 0;
			count3 = 0;
			
			while(count<=rows)
			
		{	
			while(count2>count3)
			{
				cout<<"*";
				count2--;
			}
			while(count4)
			count++;
			count2 = rows+1;
			count3 = count3 +2 ;
			
		}	
			
	}
	
	return 0;	
}
