#include <iostream>
using namespace std;
class deque {
	int* dequeArr;
	int maxSize, rear, front;
public:
	deque();
	bool isEmpty();
	bool isFull();
	void insertFront(int value);
	void insertBack(int value);
	int removeFront();
	int removeBack();
	~deque();
	void display();
};

deque::deque() {

	maxSize = 10;
	dequeArr = new int[maxSize];

	for (int i = 0; i < maxSize; i++)
	{
		dequeArr[i] = 0;
	}
	rear = -1;
	front = -1;

}
bool deque::isEmpty() {
	if (front == -1 && rear == -1)
		return true;

	else
		return false;
}
bool deque::isFull() {
	

	if (rear + 1 == front)
		return true;

	else if (rear == maxSize-1 && front == 0)
		return true;

	else
		return false;
}

void deque::insertBack(int value) {
	if (isFull())
	{
		cout << "STRUCTURE IS FULL!";
	}
	
	else if (isEmpty())
	{
		front = 0;
		rear = 0;
		dequeArr[rear] = value;
	}

	else
		{
			if (rear == maxSize - 1)
			{
				rear = 0;
				dequeArr[rear] = value;

			}

			else
			{
				rear++;
				dequeArr[rear] = value;
			}
			
	}

}
void deque::insertFront(int value) {

	if (isFull())
	{
		cout << "CANNOT ENQUEUE ANYMORE AS THE STRUCTURE IS FULL!";
	}

	else if (isEmpty())
	{
		front = maxSize-1;
		dequeArr[front] = value;
		rear = maxSize - 1;
	}

	else
	{
		if (front == 0)
		{
			front = maxSize - 1;
			dequeArr[front] = value;

		}

		else
		{
			front--;
			dequeArr[front] = value;
		}
	}

}
int deque::removeBack() {
	
	if (isEmpty())
	{
		cout<<"CANNOT REMOVE ANYTHING AS THE STRUCTURE IS EMPTY!";
		return -1;
	}

	else if (rear == 0 && front != 0)
	{
		int temp = dequeArr[rear];
		dequeArr[rear] = 0;
		rear = maxSize - 1;
		return temp;
	}

	else if(rear == 0 && front== 0)
	{
		front = -1;
		int temp = dequeArr[rear];
		dequeArr[rear] = 0;
		rear = -1;
		return temp;

	}

	else if (rear == front)
	{
		int temp = dequeArr[rear];
		dequeArr[rear] = 0;
		rear = -1;
		front = -1;
		return temp;
	}
	else
	{
		int temp = dequeArr[rear];
		dequeArr[rear] = 0;
		rear--;
		return temp;

	}

}
int deque::removeFront() {
	if (isEmpty()) {
		cout << "CANNOT REMOVE ANYMORE AS THE STRUCTURE IS EMPTY!";
		return -1;
	}

	else if (front == rear)
	{
		int temp = dequeArr[front];
		dequeArr[front] = 0;
		front = -1;
		rear = -1;
		return temp;
	}

	else if (front == maxSize-1)
	{
		int temp = dequeArr[front];
		dequeArr[front] = 0;
		front = 0;
		return temp;
		
	}
	else
	{
		int temp = dequeArr[front];
		dequeArr[front] = 0;
		front++;
		return temp;
	}
}
deque::~deque() {

	delete [] dequeArr;

}
 
void deque::display()
{
	cout << endl << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cout << dequeArr[i]<<" ";
	}

	cout << endl;
}
int main()
{
	deque obj;

	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) INSERT FRONT  \n(2) INSERT BACK \n(3) REMOVE FRONT  \n(4) REMOVE BACK  \n(5) DISPLAY \n(6) IS EMPTY? \n(7) IS FULL? \n(8) EXIT" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int num;
			cout << "ENTER THE VALUE THAT YOU WANT TO INSERT: ";		
			cin >> num;
			obj.insertFront(num);
			obj.display();
		}

		else if (option == 2)
		{
			int num;
			cout << "ENTER THE VALUE THAT YOU WANT TO INSERT: ";
			cin >> num;
			obj.insertBack(num);
			obj.display();
		}
		else if (option == 3)
		{
			obj.removeFront();
			obj.display();
		}
		else if (option == 4)
		{
			obj.removeBack();
			obj.display();
		}
		else if (option == 5)
		{
			obj.display();
		}
		else if (option == 6)
		{
			cout<<obj.isEmpty();
			obj.display();
		}
		else if (option == 7)
		{
			cout<<obj.isFull();
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