#include<iostream>
using namespace std;
template <typename T>
class ListADT
{
public: 

	
 	T array[10];
	int currentSize = 0;

	
	ListADT()
	{
		for (int i = 0; i < 10; i++)
		{
			array[i] = T();
		}
	}


	ListADT rearrange(ListADT& obj)
	{

		T array2[10];
		int count = 0;

		for (int i = 0; i < 10; i++)
		{
			if (array[i] % 2 == 0)
			{
				array2[count] = array[i];
				count++;
			}
		}
		

		for (int i = 0; i < 10; i++)
		{
			if (array[i] % 2 == 1)
			{
				array2[count] = array[i];
				count++;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			array[i] = array2[i];
		}

		for (int i = 0; i < 10; i++)
		{
			cout << array[i] << " ";
		}

		return obj;
	}

	void output()
	{
		for (int i = 0; i < currentSize; i++)
		{
			cout << array[i] << " ";
		}
	}

	void input()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "Enter the element at the index " << i << ": ";
			cin >> array[i];
			currentSize++;
		}

	}

	int get(int index)
	{
		return array[index];
	}

	void insert(T value)
	{
		array[currentSize] = value;
		currentSize++;
	}

	void remove()
	{
		for (int i = 0; i < 10; i++)
		{
			array[i] = 0;
		}
	}

	void removeAt(int index)
	{
		array[index] =2 0;
	}

	void replace(T value, int index)
	{
		array[index] = value;
	}

	int size()
	{
		return currentSize;
	}

	bool isEmpty()
	{ 
		if (currentSize == 0)
			return true;

		else
			return false;

	}

	bool isFull()
	{
		if (currentSize = 10)
			return true;

		else
			return false;

	}


};
int main()
{
	ListADT<int> obj;
	obj.input();
	obj.rearrange(obj);
	cout << endl;
	obj.output();
	cout << endl;
	cout << obj.isFull();

	ListADT<short> obj2;
	obj2.input();
	obj2.rearrange(obj2);
	cout << endl;
	obj2.output();
	cout << endl;

system("pause");

	return 0;
}