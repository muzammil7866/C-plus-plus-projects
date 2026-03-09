#include <iostream>
using namespace std;
int main()
{
int start = 1, end = 600, thisnum = 0;
thisnum = start;
int rem = 0, dig = 0;
int sum = 0;
cout << "Armstrong numbers b/w 1 and 600 are: ";
while (thisnum <= 600)
{
	rem = thisnum;
	sum = 0;
	while (rem > 0)
	{
		dig = rem % 10;
		sum = sum + (dig*dig*dig);
		rem = rem / 10;
	}
//		 
	if (sum == thisnum)
	{
		cout << thisnum << " ";
	}
//
//
	thisnum++;
}
//
return 0;
}
