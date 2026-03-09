#include <iostream>
using namespace std;
int main()
{
	int num;
	cout<< "Enter number: \n" ;
	cin>>num;
	if(num == 3)
		{
			num++;
			cout<< endl <<num;
		}
	else if (num == 4)
	{
		num--;
		cout<<endl<< num;
	}
	
	return 0;
}
