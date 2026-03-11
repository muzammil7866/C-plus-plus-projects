#include <iostream>
using namespace std;
//FIXED FRONT AND MOVABLE REAR
//O(N)
class Queue
{
public:
	int array[4];
	int maxSize;
	int front;
	int end;

	Queue()
	{
		maxSize = 4;
		for(int i = 0; i < maxSize; i++)
		{
			array[i] = 0;
		}

		front = -1;
		end = -1;
	}

	void enqueue(int a)
	{
		if (front == -1)
		{
			front = 0;
			end = 0;
			array[end] = a;
		}

		else
		{
			if (this->isFull())
			{
				cout << "YOU CANNOT ADD MORE ITEMS INTO THE QUEUE AS IT IS FULL!";
			}

			else
			{
				end++;
				array[end] = a;
			}
		}
	}

	bool isFull()const //ADDING CONST AS THE FUNCTION DOES NOT ALTERS ANY VALUE(S)
	{
		if (end == maxSize - 1)
		{
			return true;
		}

		else
			return false;
	}

	void display()const //SAME CONST
	{
		cout << endl;

		for ( int i = 0; i < maxSize; i++)
		{

			cout << array[i] <<" ";
		}
		cout << endl;
	}

	bool isEmpty() const
	{
		if (front == -1)
			return true;

		else
			return false;
	}

	int dequeue()
	{
		if (this->isEmpty())
		{
			cout << "CANNOT DEQUEUE AS THE QUEUE IS EMPTY!";
			return -1; 
		}

		else
		{
			if (end == 0)
			{
				int temp = array[end];
				front = -1;
				end = -1;

				array[end + 1] = 0;

				return temp;
			}

			else
			{
				int temp = array[front];

				for (int i = front; i < end; i++)
				{
					array[i] = array[i + 1];
				}

				end--;

				array[end + 1] = 0;


				return temp;
			}
		}
	}
};
int main()
{
	Queue obj;

	int option;
	bool end = false;

	while(end!= true)
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
