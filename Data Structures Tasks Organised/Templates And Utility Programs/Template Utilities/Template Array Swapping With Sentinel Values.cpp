#include<iostream>
using namespace std;
const int MAX_SIZE = 100;
template<typename T>
void swap(T array, T array2, int size, int size2)
{
	int temp[MAX_SIZE];
	
	for (int i = 0; i < MAX_SIZE; i++)
	{
		temp[i] = array[i];
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		array[i] = array2[i];
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		array2[i] = temp[i];
	}


}
int main()
{
	int *array = new int[MAX_SIZE];
	float endArray = -100;
	cout << "Set the sentinal value to end the array 1: ";
	cin >> endArray;

	int value = 0;
	int count = 0;
	int size1 = 0;

	while (value != endArray)
	{

		cout << "Enter the value to store into the array: ";
		cin >> value;

		if (value == endArray)
			break;

		else
		{
			array[count] = value;
			count++;
			size1++ ;
		}

	}

	cout << "Set the sentinal value to end the array 2: ";
	cin >> endArray;

	int *array2 = new int[MAX_SIZE];
	value = 0;
	count = 0;
	int size2 = 0;

	while (value != endArray)
	{

		cout << "Enter the value to store into the array: ";
		cin >> value;

		if (value == endArray)
			break;

		else
		{
			array2[count] = value;
			count++;
			size2++;
		}

	}

	cout << "\t\tBEFORE SWAPPING: " << endl << endl;
	cout << "ARRAY 1: "<<endl;

	for (int i = 0; i < size1; i++)
	{
		cout << array[i] << " ";

	}
	
	cout << endl;

	cout << "ARRAY 2: " << endl;

	for (int i = 0; i < size2; i++)
	{
		cout << array2[i] << " ";

	}

	swap(array, array2, size1, size2);

	cout << endl;
	cout << "\t\tAFTER SWAPPING: " << endl << endl;
	cout << "ARRAY 1: " << endl;

	for (int i = 0; i < size2; i++)
	{
		cout << array[i] << " ";

	}

	cout << endl;

	cout << "ARRAY 2: " << endl;

	for (int i = 0; i < size1; i++)
	{
		cout << array2[i] << " ";
	}





	system("pause");
	return 0;
}