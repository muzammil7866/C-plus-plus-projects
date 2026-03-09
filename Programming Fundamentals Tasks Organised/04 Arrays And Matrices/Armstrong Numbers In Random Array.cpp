#include <iostream>
using namespace std;
int main()
{
const int size = 100;
int array[size];
int thisnum = 0, rem = 0, sum = 0, dig=0;
srand(time(0));
//
for (int i = 1; i < size; i++)
{
//		array[0] = 153; //for check that the logic is working
	array[i] = (rand() % (10000 + 1)) + 100;
}
//
for (int i = 0; i < size; i++)
{
	cout <<"Array element at index ["<<i<<"]: "<< array[i] << " " << endl;
}
//
cout <<endl<< "Armstrong numbers among the random generater numbers of array are: ";
for (int i = 0; i < size; i++)
{
	thisnum = array[i];
	rem = thisnum;			
//		
//
	while(rem >0)
	{
		dig = rem % 10;
		sum = sum + (dig * dig * dig);
		rem = rem / 10;
	}
//
	if (sum == thisnum)
	{
		cout << thisnum<< " ";
	}
//
}
//
return 0;
}
