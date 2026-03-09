#include <iostream>
using namespace std;
int main()
{
	
	char alpha;
	cout<<  "Enter your alphabet: ";
	cin>> alpha;
	if(alpha =='a' || alpha =='e' || alpha=='i' || alpha=='o'|| alpha=='u'|| alpha == 'A' || alpha =='E' || alpha=='I' || alpha=='O'|| alpha=='U')
	{
		cout<< "Your entered alphabet is a vowel";
	}
	
	else
	{
		cout<< "Your entered alphabet is a consonant";
	}
return 0;	
}
