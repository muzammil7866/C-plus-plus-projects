#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cout<< "Enter first number: ";
	cin>>a;
	cout<<"Enter second number: ";
	cin>>b;
	a= a-b;
	b= a+b;
	a=b-a;
	cout<<a<<endl;
	cout<<b;
	
	return 0;
	
}
