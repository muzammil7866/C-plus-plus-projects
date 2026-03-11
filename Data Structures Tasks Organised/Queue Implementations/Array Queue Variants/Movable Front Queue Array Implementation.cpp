#include<iostream>
using namespace std;
//MOVALBE FRONT AND REAR QUEUE
//O(1) BUT ARRAY SPACE NOT UTILISED PROPERLY
class MovableFrontQueue
{
public:

	int* array;
	int front;
	int rear;
	int maxSize;

	MovableFrontQueue()
	{
		maxSize = 5;
		array = new int[maxSize];
		front = rear = -1;

		for (int i = 0; i < maxSize; i++)
		{
			array[i] = 0;
		}
	}

	bool isFull()const
	{
		if (rear == maxSize - 1)
		{
			return true;
		}

		else
			return false;
	}

	bool isEmpty()const
	{
		if (front == - 1 && rear == -1)
		{
			return true;
		}

		else if (front - 1 == rear)
		{
			return true;
		}

		else
			return false;
	}

	void enqueue(int a)
	{
		if (isEmpty())
		{
			front = rear = 0;
			array[rear] = a;
		}

		else if (rear == maxSize - 1)
		{
			cout << "CANNOT ENQUEUE ANYMORE AS THE QUEUE IS FULL NOW!";
		}

		else {
			rear++;
			array[rear] = a;
		}

	}

	void display()const
	{
		for (int i = 0; i < maxSize; i++)
		{
			cout << array[i] << " ";
		}
	}

	int dequeue()
	{
		if (isEmpty())
		{
			cout << "CANNOT DEQUEUE ANYMORE AS THE QUEUE IS EMPTY!";
			return -1;
		}

		else
		{
			int a = array[front];
			array[front] = 0;
			front++;

			return a;
		}
	}
};

int main()
{
	MovableFrontQueue obj;

	int option;
	bool end = false;

	while (end != true)
	{
		cout << "CHOOSE OPTION:" << endl;
		cout << "1) ENQUEUE" << endl;
		cout << "2) DEQUEUE" << endl;
		cout << "3) ISFULL?" << endl;
		cout << "4) ISEMPTY?" << endl;
		cout << "5) DISPLAY" << endl;
		cout << "6) EXIT" << endl;
		cout << "ENTER: ";
		cin >> option;

		if (option == 1)
		{
			int num;
			cout << "ENTER THE VALUE TO ENQUEUE: ";
			cin >> num;

			obj.enqueue(num);
			system("pause");
			system("cls");
		}

		if (option == 2)
		{
			obj.dequeue();
			system("pause");
			system("cls");
		}

		if (option == 3)
		{
			if (obj.isFull())
			{
				cout << "YOUR QUEUE IS FULL!";
			}

			else
			{
				cout << "YOUR QUEUE IS NOT FULL!";
			}
			system("pause");
			system("cls");
		}

		if (option == 4)
		{
			if (obj.isEmpty())
			{
				cout << "YOUR QUEUE IS EMPTY!";
			}

			else
			{
				cout << "YOUR QUEUE IS NOT EMPTY!";
			}
			system("pause");
			system("cls");
		}

		if (option == 5)
		{
			obj.display();
			system("pause");
			system("cls");
		}

		if (option == 6)
		{
			end = true;
			system("pause");
			system("cls");
		}
	}

	return 0;
}