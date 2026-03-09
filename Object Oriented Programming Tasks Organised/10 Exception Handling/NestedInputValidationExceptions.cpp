#include <iostream>
using namespace std;

int main()
{
	try
	{
		float num;
		cout << "ENTER LENGTH IN FEET AND INCHES: ";
		cin >> num;
		if (num < 0)
		{
			throw (num);
		}

		char temp;
		temp = num;

		try
		{
			
			if (temp >='a' && temp <='z' || temp >= 'A' && temp <= 'Z')
			{
				throw(temp);
			}

			else
			{
				num = num * 30.48;
				cout << "THE LENGTH IN CENTIMETERS IS: " << num;
			}
		}

			catch (char temp)
			{
				cout << "INVALID! YOU ENTERED A NON DIGIT INPUT";
			}

			


	
	}
	
	catch (float num)
	{
		cout << "INVALID! YOU ENTERED A NON NEGATIVE NUMBER";
	}

	

	return 0;	
}
