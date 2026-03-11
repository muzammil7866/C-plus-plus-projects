#include<iostream>
using namespace std;
template<typename T> 
int search(T array[], int size, T key) //searches linearly by  iterating through array to find the passed value in the array
{
	
	for (int i = 0; i < size; i++)
	{
		if (key == array[i])
			return i;
		
	}

	return -1; //returns -1 if value not found


}

template<typename A>
float mean(A array[], int size) //mean would always be in mean
{

	float sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}

	return sum/size;
}

template<typename B>
B median(B array[], int size) //
{
	int temp = 0;

	int array2[size] = 0;

	//this piece of code is used to sort the array using the bubble sort
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] >= array[j]) //each element compared with the rest of the array
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
			}
		}
	}


	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}


	if (size % 2 == 0) //median of the even size
	{
		temp = size / 2;

		return (array[temp] + array[temp + 1]) / 2; //average of the middle two
	}

	else //median of the odd size
	{
		temp = size / 2;
		return array[temp];
	}

}

template<typename C>
float standardD(C array[], int size, float mean) //standard deviation
{
	float ans = 0;

	for (int  i = 0; i < size; i++)
	{
		ans += ((array[i] - mean)*(array[i] - mean)) / size;
	}

	return sqrt(ans); //square root
}
int main()
{
	int array[5] = { 1,2,3,4,5 }; //declared a random array
	double array2[4] = { 1.4,47.2, 41.9, 17.3 };

	int key;
	cout << "ARRAY 1: ";

	for (int i = 0; i < 5; i++)
	{
		cout << array[i]<<" ";
	}

	cout << "Enter the value to search for that in the array 1: ";
	cin >> key;


	if (search(array, 5, key) != -1)
	{
		cout << "Your value is found on the index: " << search(array, 5, key);
	}

	else
		cout << "Your value is not found!";

	cout << endl;
	cout << "The mean of the array 1 is: " << mean(array, 5) << endl;
	cout << "The mode of the array 1 is: " << median(array, 5)<<endl;
	cout << "The standard deviation of the array 1 is: " << standardD(array, 5, mean(array,5))<<endl;

	cout << endl << endl;
	cout << "ARRAY 2: ";

	for (int i = 0; i < 5; i++)
	{
		cout << array2[i] << " ";
	}

	cout << endl;
	cout << "Enter the value to search for that in the array 2: ";
	cin >> key;


	if (search(array2, 5, key) != -1)
	{
		cout << "Your value is found on the index: " << search(array2, 5, key);
	}

	else
		cout << "Your value is not found!";

	cout << endl;
	cout << "The mean of the array 2 is: " << mean(array2, 5) << endl;
	cout << "The mode of the array 2 is: " << median(array2, 5) << endl;
	cout << "The standard deviation of the array 2 is: " << standardD(array2, 5, mean(array2, 5)) << endl;



	system("pause");
	return 0;
}