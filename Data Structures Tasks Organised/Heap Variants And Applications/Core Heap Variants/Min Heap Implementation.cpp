#include<iostream>
#include<math.h>
using namespace std;
class HeapNode
{
public:
	HeapNode* left;
	HeapNode* right;
	int data;

	HeapNode()
	{
		left = nullptr;
		right = nullptr;
		data = 0;

	}

	HeapNode(int value)
	{
		left = nullptr;
		right = nullptr;
		data = value;

	}

};

class MinHeap
{
public:
	int* arr;
	int maxSize;
	int currSize;

	MinHeap(int size)
	{
		maxSize = size;
		arr = new int[maxSize];
		currSize = 0;

	}

	int linearSearch(int value)
	{
		for (int i = 0; i < currSize; i++)
		{
			if (value == arr[i])
			{
				return i;
			}
		}

		return -1;

	}

	void display()
	{
		for (int i = 0; i < currSize; i++)
		{
			cout << arr[i] << " ";
		}
	}

	int height() //research about this
	{
		return ceil(log2(currSize + 1)) - 1;
	}

	int getParentIndex(int i) //returns index
	{
		return (i - 1) / 2;
	}
	void minInsert(int& value) //min heap
	{
		if (currSize == maxSize)
		{
			cout << "HEAP IS FULL SO CANNOT INSERT ANY MORE OF THE VALUE!";
		}

		else
		{
			currSize++;
			int i = currSize - 1;
			arr[i] = value;

			while (i != 0 && arr[getParentIndex(i)] > arr[i]) //careful
			{

				swaps(arr[getParentIndex(i)], arr[i]);
				i = getParentIndex(i);

			}

		}
	}
	int getLeftIndex(int i)
	{
		return 2 * i + 1;
	}

	int getRightIndex(int i)
	{
		return 2 * i + 2;
	}

	void swaps(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	void minHeapify(int i)
	{
		int left = getLeftIndex(i);
		int right = getRightIndex(i);
		int minimum = i;

		if (left < currSize && arr[left] < arr[i])
		{
			minimum = left;
			if (right < currSize && arr[right] < arr[minimum])
			{
				minimum = right;
			}
		}

		if (minimum != i)
		{
			swaps(arr[i], arr[minimum]);
			cout << arr[minimum];
			minHeapify(minimum);
		}


	}
	int getMin()
	{
		return arr[0];
	}

	int extractMin()
	{
		if (currSize <= 0)
		{
			return INT_MAX;
		}

		else if (currSize == 1)
		{
			currSize--;
			return arr[0];
		}
		else {

			int temp = arr[0];

			arr[0] = arr[currSize - 1];
			currSize--;

			minHeapify(0);
			return temp;
		}


	}

	void perculateUp(int& a, int b)
	{
		arr[a] = b;

		while (a != 0 && arr[getParentIndex(a)] > arr[a])
		{
			swaps(arr[getParentIndex(a)], arr[a]);
			a = getParentIndex(a);
		}

	}

	void deleteValue(int i)
	{
		perculateUp(i, INT_MIN);
		extractMin();
	}

};
int main()
{

	MinHeap obj(10);
	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) INSERT  \n(2) SEARCH \n(3) DELETE \n(4) GET MIN  \n(5) EXTRACT MIN \n(6) HEIGHT \n(7) DISPLAY \n(8) EXIT MENU \n" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int value;
			cout << "ENTER THE VAUE THAT YOU WANT TO INSERT: ";
			cin >> value;
			obj.minInsert(value);
		}

		else if (option == 2)
		{
			int value;
			cout << "ENTER THE VAUE THAT YOU WANT TO SEARCH: ";
			cin >> value;
			if (obj.linearSearch(value))
				cout << "FOUND!";
			else
			{
				cout << "NOT FOUND!";
			}
		}
		else if (option == 3)
		{
			int value;
			cout << "ENTER THE VAUE THAT YOU WANT TO DELETE: ";
			cin >> value;
			if (obj.linearSearch(value) == -1)
			{
				cout << "VALUE DOES NOT EXIST IN THE HEAP!";
			}

			else
			{
				obj.deleteValue(value);
			}


		}
		else if (option == 4)
		{
			cout << obj.getMin();
		}
		else if (option == 5)
		{
			cout << obj.extractMin();
		}

		else if (option == 6)
		{
			cout << obj.height();
		}
		else if (option == 7)
		{
			obj.display();
		}
		else if (option == 8)
		{
			end = true;
		}

		else
		{
			cout << "INVALID OPTION!" << endl;
		}


		system("pause");
		system("cls");


	}


}