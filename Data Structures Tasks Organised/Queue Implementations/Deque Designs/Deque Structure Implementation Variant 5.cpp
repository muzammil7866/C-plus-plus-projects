#include <iostream>
using namespace std;
class Queue
{
public:
	int *array;
	int maxSize;
	int front;
	int end;

	Queue() //CONSTRUCTOR TO INITIALISE DATA MEMBERS
	{
		
		cout << "ENTER THE SIZE OF YOUR QUEUE: ";
		cin >> maxSize;
		system("pause");
		system("cls");
		array = new int[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			array[i] = 0;
		}

		front = -1;
		end = -1;
	}

	void enqueue(int a) //ADDS ELEMENT TO QUEUE
	{
		if (front == -1) //QUEUE IS EMPTY
		{
			front = 0;
			end = 0;
			array[end] = a;

			cout << a << " ENQUEUED SUCCESSFULLY!";
		}

		else
		{
			if (this->isFull())
			{
				cout << "YOU CANNOT ADD MORE ITEMS INTO THE QUEUE AS IT IS FULL!";
			}

			else //FOR ALL REST CONDITIONS
			{
				end++;
				array[end] = a;
				cout << a << " ENQUEUED SUCCESSFULLY!";
			}
		}
	}

	bool isFull()const //CHECKS IF QUEUE IS FULL
	{
		if (end == maxSize - 1) //IS FULL
		{
			return true;
		}

		else //NOT
			return false;
	}

	void display()const //DISPLAYS CONTENTS OF QUEUES
	{
		cout << endl;

		for (int i = end; i >= 0; i--)
		{

			cout << array[i] << endl;
		}
		cout << endl;
	}

	bool isEmpty() const //CHECKS IF QUEUE IS EMPTY
	{
		if (end == -1)
			return true;

		else
			return false;
	}

	int dequeue() //REMOVES ELEMENT FROM QUEUE
	{
		if (this->isEmpty()) //QUEUE IS EMPTY
		{
			cout << "CANNOT DEQUEUE AS THE QUEUE IS EMPTY!";
		}

		else
		{
			if (end == 0) //REMOVING IF ONLY ONE ELEMENT IN QUEUE
			{
				int temp = array[end];
				front = -1;
				end = -1;

				cout << temp << " DEQUEUED SUCCESSFULLY!";

				return temp;
			}

			else //REMOVES FOR ALL REST CONDITIONS
			{
				int temp = array[front];

				for (int i = front; i < end; i++) //COPIES ALL CONTENTS AT THE START OF ARRAY
				{
					array[i] = array[i + 1];
				}
				end--;

				if (array[end + 1] != maxSize - 1) 
					array[end + 1] = 0;

				cout << temp << " DEQUEUED SUCCESSFULLY!";
				return temp;
			}
		}
	}

	~Queue() //RELEASING MEMORY TO HEAP USING DESTRUCTOR
	{
		delete array;
	}
};
int main()
{
	Queue obj;

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
