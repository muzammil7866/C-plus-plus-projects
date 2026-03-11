#include<iostream>
using namespace std;
void bubbleSort(int array[],int size)
{

	for (int i = 0; i < size; i++)
	{

		for (int j = i+1; j < size; j++)
		{
			if (array[i] >= array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;

			}
		}
	}
}

int* removeRepetitions(int array[], int size)
{
	int* result = new int[size];

	int count = 0;
	int start = 0;
	int countForResult = 0;

	while (count < size)
	{

		bool match = true;
		int count2 = count + 1;

		while (match != false)
		{
			if (count2 > size - 1)
			{
				break;
			}

			else
			{
				if (array[count] == array[count2])
				{
					match = true;
					count2++;
				}

				else
				{
					match = false;
				}


			}
		}

		result[countForResult] = array[count];
		countForResult++;

		count = count2;
	}

	return result;
}

int* unions(int array[], int array2[], int size1, int size2)
{
	int* result = new int[size1 + size2];

	int count = 0;

	for (int i = 0; i < size1; i++)
	{
		result[i] = array[i];
	}

	for (int i = 0; i < size2; i++)
	{
		result[i + size1] = array2[i];
	}

	return result;
}

void output(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << endl;
}

int newSize(int array[], int size)
{
	int count = 0;
	while (array[count] > 0)
	{
		count++;
	}

	return count;
}

int* intersection(int array[], int array2[], int size1, int size2)
{
	int* result = new int[size1 + size2];
	int countForResult = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (array[i] == array2[j])
			{
				result[countForResult] = array[i];
				countForResult++;
				break;
			}

		}
	}

	

	return result;
}


int main()
{

	int array1[5] = {22,1,2,2,3};
	int size1 = sizeof(array1)/sizeof(array1[0]);
	//cout << size1;

	int array2[10] = { 11,3,5,5,10,2,5,4,2,4 };
	int size2 = sizeof(array2) / sizeof(array2[0]);
	//cout << size2;

	cout << endl << endl;

	bubbleSort(array1, size1);
	bubbleSort(array2, size2);


	int* ptr = removeRepetitions(array1, size1);
	int * ptr2 = removeRepetitions(array2, size2);

	int size3 = newSize(ptr, size1);
	int size4 = newSize(ptr2, size2);

	output(ptr, size3);
	output(ptr2, size4);


	int* ptr3 = unions(ptr, ptr2, size3, size4);
	
	cout << "Union: " << endl;
	bubbleSort(ptr3, size3+size4);
	int* ptr4 = removeRepetitions(ptr3, size3+size4);
	int size5 = newSize(ptr4, size3 + size4);
	output(ptr4, size5);


	int array3[5] = { 1,6,4,2, 4 };
	int array4[9] = { 1,3,7,1,1,1,3,56,6};
	int size6=5, size7 =9;

	int* ptr5 = intersection(array3, array4, size6, size7);
	
	bubbleSort(ptr5, newSize(ptr5, size6 + size7));
	
	int* ptr6 = removeRepetitions(ptr5, newSize(ptr5, size6 + size7));
	
	output(array3, 5);
	output(array4, 9);
	cout << "Intersection: "<<endl;
	output(ptr6, newSize(ptr6, size6 + size7));

	system("pause");

	return 0;
}