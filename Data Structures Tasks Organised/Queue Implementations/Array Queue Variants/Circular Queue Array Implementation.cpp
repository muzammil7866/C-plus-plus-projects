#include <iostream>
#include<string>
#include<cstring> //reassess queue structure
using namespace std;
class CircularQueue
{
public:
	int front;
	int rear;
	int maxSize;
	int* array;

	CircularQueue()	{
		maxSize = 8;
		array = new int[maxSize];
		for (int i = 0; i < 8; i++)
		{
			array[i] = 0;
		}
		rear = -1;
		front = -1;

	}

	bool isEmpty()
	{
		if (rear == -1 && front == -1)
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}


	bool isFull()
	{
		if (rear + 1 == front)
			return true;

		else if(rear == maxSize-1 && front == 0)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
	

	void enqueue(int a)
	{
		if (isEmpty())
		{
			front = 0;

			rear = 0;
			array[rear] = a;
		}

		else if (isFull())
		{
			cout << "CANNOT ENQUEUE AS THE QUEUE IS FULL!";
		}

		else
		{
			if (rear == maxSize - 1)
			{
				rear = 0;
				array[rear] = a;
			}

			else {
				rear++;
				array[rear] = a;
			}
		
		}
	}

	int dequeue()
	{
		if (isEmpty())
		{
			cout << "CANNOT DEQUEUE ANY MORE!";
			return -1;
		}

		else if (front == rear)
		{
			int temp = array[front];
			array[front] = 0;
			rear = -1;
			front = -1;

			return temp;
		}

		else
		{
			if (front == maxSize-1)
			{
				int temp = array[front];
				array[front] = 0;
				front = 0;;

				return temp;

			}

			else {
				int temp = array[front];
				array[front] = 0;
				front++;


				return temp;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < 8; i++)
		{
			cout << array[i]<<" ";
		}
	}

};
int main()
{
	CircularQueue obj;
	cout<<obj.isEmpty();
	cout << endl;
	obj.enqueue(1);
	obj.enqueue(2);
	obj.dequeue();
	obj.dequeue();
	obj.enqueue(1);
	obj.enqueue(2);
	obj.dequeue();
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(2);
	obj.enqueue(2);
	obj.enqueue(2);
	obj.enqueue(7);
	obj.enqueue(11);
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.enqueue(2);
	obj.enqueue(2);
	obj.enqueue(2);
	obj.enqueue(2);
	obj.print();
	

	
	return 0;	
}
