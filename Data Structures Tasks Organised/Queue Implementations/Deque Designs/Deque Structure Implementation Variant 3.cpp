#include <iostream>
using namespace std;
struct Node
{
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = nullptr;
	}
};

class Queue {

public:
	Node* front; //FOR DEQUEUEING
	Node* rear; //FOR ENQUEUEING

	Queue(); //FOR ALLOCATING MEMORY DYNAMICALLY AND INITIALISING DATA MEMBERS
	void enqueue(int item); //ADDS ELEMENT IN QUEUE
	int dequeue(); //REMOVES ELEMENT IN QUEUE
	bool isEmpty(); //CHECKS IF QUEUE IS EMPTY
	~Queue(); //RELEASES MEMORY TO HEAP
	void display(); //DISPLAYS QUEUE CONTENTS
};

Queue::Queue() {

	front = nullptr;
	rear = nullptr;
}
void Queue::enqueue(int item) {
	
	if (rear == nullptr) //IS EMPTY
	{
		Node* temp = new Node;
		temp->data = item;

		front = temp;
		rear = temp;

		cout << item << " ENQUEUED SUCCESSFULLY!";
	}

	else if(front == rear) //ONLY ONE ELEMENT IS IN QUEUE
	{
		Node* temp = new Node;
		temp->data = item;

		rear = temp;
		front->next = rear;

		cout << item << " ENQUEUED SUCCESSFULLY!";

	}

	else //FOR ALL REST INSERTIONS
	{
		Node* temp = rear;
		Node* temp2 = new Node;
		temp2->data = item;
		temp->next = temp2;

		rear = temp2;

		cout << item << " ENQUEUED SUCCESSFULLY!";
	}
}
int Queue::dequeue() 
{ 

	if (front == nullptr) //IS EMPTY
	{
		cout << "COULD NOT BE DEQUEUED AS THE QUEUE IS EMPTY";
	}

	else if(&rear == &front) //ONE ELEMENT IS IN QUEUE
	{
		int temp = front->data;
		Node* temp2 = front;
		rear = nullptr;
		front = nullptr;
		delete temp2;
		

		cout << temp << " DEQUEUED SUCCESSFULLY!";
		return temp;
	}
	
	else //FOR ALL REST ELEMENTS
	{
		int temp1 = front->data;
		Node* temp2 = front;
		front = front->next;
		delete temp2;

		cout << temp1 << " DEQUEUED SUCCESSFULLY!";
		return temp1;

	}

	return -1; //RETURNS IF DEQUEUEING IS NOT POSSIBLE
}
bool Queue::isEmpty() {
	if (rear == nullptr)
		return true;

	else
		return false;
}
Queue::~Queue() {
	while (!isEmpty())
	{
		dequeue(); 
	}
}

void Queue::display()
{
	Node* temp = front;
	while (temp != nullptr)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}

}

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
			
			cout << "LINKED QUEUE STRUCTURE CANNOT BE FULL AS IT HAS NO SIZE CONSTRAINTS, HOWEVER, YOUR SYSTEM HEAP MEMORY STILL MATTERS!";

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