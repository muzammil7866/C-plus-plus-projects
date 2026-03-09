#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{

	int array[10] = {2,3,4,6,6,34,3,23,23,4};

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}

	int num;
	cout << "Enter the number you want to search in the array: " << endl;
	cin >> num;

	bool isPresent = false;

	for (int i = 0; i < 10; i++)
	{
		if (num == array[i])
		{
			isPresent = true;
			cout << "YOUR NUMBER IS FOUND AT INDEX " << i;
		}
		else
			isPresent = false;
			
	}




	return 0;
}