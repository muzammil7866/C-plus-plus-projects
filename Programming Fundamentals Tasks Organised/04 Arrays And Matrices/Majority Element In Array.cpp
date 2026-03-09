#include <iostream>
using namespace std;
void majorityElement(int array[], int a);
int main()
{
int array[8] = {0};
for (int i = 0; i < 8; i++)
{
	cout << "Enter the element of Array at index [" << i << "]: ";
	cin >> array[i];
 }
//
majorityElement(array, 8);
//
//
return 0;
}
//
void majorityElement(int array[], int b)
{
int count = 0;
int size = 8;
int checktill = size/2;
bool noElement = true;
	cout << "Enter the size of your array: ";
//	
	cin>>size;
checktill = size / 2;
for (int i = 0; i < b; i++)
{	
	count = 0;
	for (int j = i+1; j <  b;j++)
	{
		if (array[i] == array[j])
		{
			count++;
		}
	}
//
	if (count > checktill)
	{
		cout << "Majority element is " << array[i] << " that is more than " << checktill;
		noElement = false;
	}
//
//
}
//
if (noElement == true)
{
	cout << "There is no element whose frequency is greater than the half of the size of the array size.";
}
//	
}
