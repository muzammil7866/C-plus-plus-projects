#include <iostream>
using namespace std;
const int SECRET = 5; // semi colon was not placed here before
int main()
{
		int x, y, w, z;	
		z=9;
		
		if(z>10)	// brackets of if condition were not here before
			{		// parenthesis of if body were absent before
			x=12;
			y=5;	// comma was placed instead of semicolon before
			w = x+y+SECRET;
			}
		else
		
		{						// parenthesis of else body were absent before
			x=12;
			y=4;				// comma was placed instead of semicolon before
			w= x+y+SECRET;
		cout<<"w= "<<w<<endl;
		}
		
		return 0;
}
