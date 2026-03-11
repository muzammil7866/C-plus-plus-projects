#include<iostream>
using namespace std;
class Queue
{
public:
	int front;
	int rear;
	int num;
	int deqCount;
	static int size;
	static int count1;
	int array[100];


	Queue()
	{
		front=-1;
		rear=-1;
		deqCount = 0;
		size = 5;
		num = 0;
		for (int i = 0; i <= deqCount + size - 1; i++)
		{
			array[i] = 0;
		}
	}


	void enqueue()
	{
		if (front == -1 && rear == -1)
		{
			front++;
			rear++;
			count1++;
			cout << "ENTER THE ITEM WHICH YOU WANT TO ENTER INTO THE QUEUE AT THE INDEX " << num << ": ";
			cin >> array[rear];
			num++;
			cout << endl;
		}
		else if (rear < deqCount + size-1)
		{
			rear++;
			count1++;
			cout << "ENTER THE ITEM WHICH YOU WANT TO ENTER INTO THE QUEUE AT THE INDEX " << num << ": ";
			cin >> array[rear];
			num++;
			cout << endl;
		}

		else
		{
			cout << "YOUR QUEUE IS FULL! IT CANNOT ADD MORE ITEMS." << endl;
		}
	}

	void dequeue()
	{
		if (rear >= front)
		{
			front++;
			num--;
			deqCount++;
			count1--;
		}

		else
		{
			cout << "YOUR QUEUE IS EMPTY! IT CANNOT REMOVE MORE ITEMS OFF THE STACK." << endl;
		}


	}

	int peek(int pos)
	{
		if (pos-1 > -1 && pos-1<=count1-1 && pos-1<size)
		{
			cout << "THE ITEM IS: " <<array[deqCount+ pos - 1];
			return array[deqCount + pos - 1];
		}

		else if (pos-1<size && pos-1>-1)
		{
			cout << "THE POSITION IS EMPTY YET";
		}

		else
		{
			cout << "INVALID OPTION!";
		}
	
		
	}

	void display()
	{
		cout << endl;
		for (int i = front; i <= rear; i++)
		{
			cout << array[i]<<" ";
		}
	}

	int count()
	{
		return count1;
	}



};
int Queue::size = 5;
int Queue::count1 = 0;

int main()
{
	Queue obj;
	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) ENQUEUE ITEM \n(2) DEQUEUE ITEM \n(3) PEEK INTO \n(4) GET ITEMS COUNT \n(5) EXIT MENU \n" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			obj.enqueue();
		}

		else if (option == 2)
		{
			obj.dequeue();
		}
		else if (option == 3)
		{
			int num;
			cout << "ENTER THE POSITION TO PEEK ITS ITEM: ";
			cin >> num;
			obj.peek(num);
			cout << endl;
		}
		else if (option == 4)
		{
			cout << "THE ITEMS CURRENTLY IN THE STACK ARE: " << obj.count() << endl;
		}
		else if (option == 5)
		{
			end = true;
		}

		else
		{
			cout << "INVALID OPTION!" << endl;
		}


		obj.display();
		system("pause");
		system("cls");


	}


}
