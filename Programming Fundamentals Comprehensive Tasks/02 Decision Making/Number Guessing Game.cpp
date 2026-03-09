#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int guesscheck, originalguess, count;
	bool guess=false;
	
	
	srand(time(0));
	
	originalguess = (rand()%50+1);
	
	
	while(guess!=true)
	{
		cout<<"Enter your number for guess: "<<endl;
		cin>>guesscheck;
	
	
		if(guesscheck==originalguess)
		{
			guess = true;
			cout<<endl<<"Congratulations! You won. :) "<<endl;
		}
		
		else if(guesscheck>originalguess)
		{
			cout<<"Your number is too high, try again! "<<endl;
			count++;
		}
		
		else if(guesscheck<originalguess)
		{
			cout<<"Your number is too low, try again! "<<endl;
			count++;
		}
		
	}
	
	cout<<"You got it in "<<count<<" tries";
return 0;
}
