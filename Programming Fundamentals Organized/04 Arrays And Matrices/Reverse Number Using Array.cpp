#include <iostream>
using namespace std;
int main()
{
	long int num, count =0, dig, a[10]={0}, i=0, count2=0, sum=0, count3=0;	
	cout<<"Enter your number: ";
	cin>>num;
	
	cout<<"Number in reverse is: ";
	while(num>10)
	{
		dig = num%10;
		num = num/10;
		count++;
		
		a[i] = dig;
		i++;
		cout<<dig;
		
	}
	
	a[i] = num;
	cout<<num%10<<endl;
	count++;
	cout<<"Total number of digits are: "<<count<<endl;
	
	count3 = count;
	
	for(int j=0;j<count;j++)
	{
		while(count2<count3-1)
		{
			a[j] = a[j]*10;
			count2++;	
		}
		
		count2=0;
		count3--;
	}
	
	for(int i=0; i<count; i++)
	{
		sum = sum + a[i];
	}
	
	num = sum;
	
	cout<<endl<<"The reverse number stored in the same variable using array is: "<<num;
	return 0;	
	
}
