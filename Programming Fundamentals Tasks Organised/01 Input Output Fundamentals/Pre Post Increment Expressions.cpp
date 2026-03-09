#include <iostream>
using namespace std;
int main()
{
	int a, b, c,result1, result2, result3;
	cout<<"Enter a: \n";
	cin>>a;
	cout<<"Enter b: \n";
	cin>>b;
	cout<<"Enter c: \n";
	cin>>c;
	
	result1=(++a)+(++b)+(++c);
	result2=(a++)+(b++)+(c++);
	result3=(a++)+(++b)+(c++);
	
	cout<<result1<<endl;
	cout<<result2<<endl;
	cout<<result3<<endl;
	
	return 0;
}

