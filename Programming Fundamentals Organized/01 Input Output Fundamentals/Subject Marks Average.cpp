#include <iostream>
using namespace std;
int main()
{
	int n1,n2,n3,n4,n5, avg;
	cout<< "Enter marks of subject 1: \n";
	cin>>n1;
	cout<< "Enter marks of subject 2: \n";
	cin>>n2;
	cout<< "Enter marks of subject 3: \n";
	cin>>n2;
	cout<< "Enter marks of subject 4: \n";
	cin>>n2;
	cout<< "Enter marks of subject 5: \n";
	cin>>n2;
	
	avg= ((n1+n2+n3+n4+n5)/5);
	cout<< endl<< avg;
	
	return 0;
}
