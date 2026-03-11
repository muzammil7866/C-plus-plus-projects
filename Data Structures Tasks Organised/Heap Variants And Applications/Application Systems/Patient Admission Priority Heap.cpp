#include<iostream>
#include<math.h>
using namespace std;
struct Patient {
	string name;
	int condition; 
	Patient(string name, int condition) {
		this->name = name;
		this->condition = condition;
	}

	Patient()
	{
		name = '\0';
		condition = 0;
	}

};
class HeapNode
{
public:
	HeapNode* left;
	HeapNode* right;
	Patient patient;

	HeapNode()
	{
		left = nullptr;
		right = nullptr;
	}

	HeapNode(Patient obj)
	{
		left = nullptr;
		right = nullptr;
		patient.name = obj.name;
		patient.condition = obj.condition;

	}

};

class MaxHeap
{
public:
	Patient* arr;
	int maxSize;
	int currSize;

	MaxHeap(int size)
	{
		maxSize = size;
		arr = new Patient[maxSize];
		currSize = 0;

	}

	int linearSearch(int value)
	{
		for (int i = 0; i < currSize; i++)
		{
			if (value == arr[i].condition)
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
			cout << arr[i].name << " "<<arr[i].condition<<"-";
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
	void maxInsert(int& value) //max heap
	{
		if (currSize == maxSize)
		{
			cout << "HEAP IS FULL SO CANNOT INSERT ANY MORE OF THE VALUE!";
		}

		else
		{
			currSize++;
			int i = currSize - 1;
			arr[i].condition = value;

			while (i != 0 && arr[getParentIndex(i)].condition < arr[i].condition) //careful
			{

				swaps(arr[getParentIndex(i)].condition, arr[i].condition);
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
	void maxHeapify(int i)
	{
		int left = getLeftIndex(i);
		int right = getRightIndex(i);
		int max = i;

		if (left < currSize && arr[left].condition > arr[i].condition)
		{
			max = left;
			if (right < currSize && arr[right].condition > arr[max].condition)
			{
				max = right;
			}
		}

		if (max != i)
		{
			swaps(arr[i].condition, arr[max].condition);
			cout << arr[max].condition;
			maxHeapify(max);
		}


	}
	void getMax()
	{
		cout<< arr[0].condition;
	}

	int extractMax()
	{
		if (currSize <= 0)
		{
			return INT_MAX;
		}

		else if (currSize == 1)
		{
			currSize--;
			int temp = arr[0].condition;
			arr[0].condition = 0;
			return temp;
		}
		else {

			int temp = arr[0].condition;

			arr[0] = arr[currSize - 1];
			currSize--;

			maxHeapify(0);
			return temp;
		}


	}

	void perculateUp(int& a, int b)
	{
		arr[a].condition = b;

		while (a != 0 && arr[getParentIndex(a)].condition < arr[a].condition)
		{
			swaps(arr[getParentIndex(a)].condition, arr[a].condition);
			a = getParentIndex(a);
		}

	}

	void deleteValue(int i)
	{
		perculateUp(i, INT_MIN);
		extractMax();
	}

};
int main()
{

	MaxHeap obj(10);
	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) ADD PATIENT \n(2) SEARCH \n(3) REMOVE PATIENT \n(4) GET MOST URGENT PATIENT  \n(5) EXTRACT MOST URGENT PATIENT \n(6) HEIGHT \n(7) DISPLAY \n(8) EXIT MENU \n" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int value;
			string name;
			cout << "ENTER THE NAME OF PATIENT: ";
			cin >> name;
			cout << "ENTER THE PATIENT URGENCY NUMBER FOR THE PATIENT YOU WANT TO ADD: ";
			cin >> value;
			obj.maxInsert(value);
		}

		else if (option == 2)
		{
			int value;
			cout << "ENTER THE PATIENT URGENCY NUMBER THAT YOU WANT TO LOOK FOR: ";
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
			cout << "ENTER THE PATIENT URGENCY NUMBER FOR THE PATIENT THAT YOU WANT TO REMOVE: ";
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
			obj.getMax();
		}
		else if (option == 5)
		{
			cout << obj.extractMax();
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