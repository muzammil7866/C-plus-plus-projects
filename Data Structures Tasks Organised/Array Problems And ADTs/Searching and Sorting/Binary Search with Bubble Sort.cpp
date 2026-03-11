//THIS QUESTION HAS THE FUNCTIONALITY OF BUBBLE SORT TO FIRST SORT THE ARRAY AND THEN RECURSIVELY APPLIES BINARY SEARCH TO FIND THE KEY FROM THE ARRAY
#include <iostream>
using namespace std;
int binarySearchRecursive(int arr[], int left, int right, int key) //FINDS THE KEY USING BINARY SEARCH FROM THE ARRAY OR RETURNS -1 IF THE KEY IS NOT FOUND
{
	int mid = left + (right - left) / 2;
	if (left > right)
	{
		return -1;
	}

	else if (arr[mid] == mid)
	{
		return mid;
	}

	else if (arr[mid] > key)
	{
		binarySearchRecursive(arr, left, mid - 1, key);
	}
	
	else if (arr[mid] < key)
	{
		binarySearchRecursive(arr, mid+1, right, key);
	}
}

void bubbleSort(int arr[], int size) //COMPARES ADJACENT ELEMENTS AND SORTS THE ARRAY IN ASCENDING ORDER 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] >= arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

void display(int arr[], int size) //DISPLAYS THE CONTENTS OF THE ARRAY
{
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}
int main()
{
	int size = 8;
	int arr[8] = { 11,2,72,6,1,23,44,41};
	cout << "UNSORTED ARRAY: \n";
	display(arr, size);
	
	cout << "\n\nSORTED ARRAY: \n";
	bubbleSort(arr, size);
	display(arr, size);

	cout << "\n\nFINDING 23 IN THE ARRAY USING BINARY SEARCH: FOUND AT INDEX ";
	cout<<binarySearchRecursive(arr, 0, size-1, 23)<<endl<<endl;

	return 0;	
}
