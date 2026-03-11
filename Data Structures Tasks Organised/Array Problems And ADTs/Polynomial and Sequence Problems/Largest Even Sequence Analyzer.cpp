#include<iostream>
using namespace std;
int main()
{
	int num = 0;
	cout << "ENTER A NUMBER: ";
	cin >> num;

	int arr[100] = { 0 };
	int arr2[100] = { 0 };
	int count = 0;
	int count2 = 0;
	int count3 = 0;
	int max = 0;

	while (num > 10)
	{
		int dig = num % 10;
		cout << dig << endl;
		num = num / 10;
		cout << num<<endl;
		count2++;

		if (dig %2 == 0) //even
		{
			arr[count] = dig;
			count++;
			max++;
		}

		else
		{
			if (dig % 2 != 0) //odd
			{
				arr2[count3] = max;
				if(max > )
				count3++;
				max = 0;
				while (dig%2 != 0)
				{
					dig = num % 10;
					num = num / 10;
					arr[count] = dig;
					count++;
					cout << dig<<endl;
					cout << num<<endl;

				}
			}

		}

	}

	arr[count] = num;
	count++;
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}