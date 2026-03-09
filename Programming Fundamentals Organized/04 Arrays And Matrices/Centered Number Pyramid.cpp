#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i, j, num = 0; 
		for (i = 1; i <= 5; ++i) //no of rows
		{
			for (j = 1; j <= (5 - i); ++j)  //noof spaces
			cout << " ";
			
			for (j = 1; j <= i; ++j) // no of elements in col
			cout << setw(1) << j+num;
			
			for (j = (i - 1); j >= 1; --j) //no of elements one less than previus and decrementing
			cout << setw(1) << j+num;
			
			
			cout << endl;
			num++;
			
	}

	return 0;	
}
