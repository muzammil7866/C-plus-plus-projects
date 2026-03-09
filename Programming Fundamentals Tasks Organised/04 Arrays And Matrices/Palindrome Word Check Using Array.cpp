#include <iostream>
using namespace std;
int main()
{
	int size=0, input, checktill, count=0;
	bool even= false, odd= false, palindrome = false;
	cout<<"Enter the size of your word: ";
	cin>>size;
	char array[size];
	
	cout<<"Enter the word to check if it is a palindrome or not: ";
	
	for(int i=0; i<size; i++)
	{
		cin>>array[i];
	}
	
	
	if(size%2==0)
	{
		even = true;
		checktill = size/2;
	}
	
	else if(size%2 == 1)
	{
		odd = true;
		checktill = size/2;
	}
	
	for(int i=0; i<size; i++)
	{
		if(even = true)
		{	
			count=i;
			while(count<checktill)
			{
				if(array[i] == array[i+checktill])
				{
					palindrome = true;		
				}
				
				else
				{
					palindrome = false;
				}
				count++;
			}
		}
		
		else if(odd = true)
		{	
			count=i;
			while(count<checktill)
			{
				if(array[i] == array[i+checktill+1])
				{
					palindrome = true;		
				}
				
				else
				{
					palindrome = false;
				}
				count++;
			}
		}
		
		
	}
	
	if(palindrome = false)
	{
		cout<<"It is not a palindrome";
	}
	else
	{
		cout<<"It is a palindrome";
	}
	
	return 0;	
}
