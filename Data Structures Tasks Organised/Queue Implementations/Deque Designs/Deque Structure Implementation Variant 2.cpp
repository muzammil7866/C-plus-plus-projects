#include <iostream>
using namespace std;
struct Process
{
public:
	int processID;
	int time;
	Process* next;

	Process()
	{
		processID = 0;
		time = 0;
		next = nullptr;
	}
};

class Queue {

public:
	Process* front; //FOR DEQUEUEING
	Process* rear; //FOR ENQUEUEING

	Queue(); //FOR ALLOCATING MEMORY DYNAMICALLY AND INITIALISING DATA MEMBERS
	void enqueue(int id, int t); //ADDS ELEMENT IN QUEUE
	int dequeue(); //REMOVES ELEMENT IN QUEUE
	bool isEmpty(); //CHECKS IF QUEUE IS EMPTY
	~Queue(); //RELEASES MEMORY TO HEAP
	void display(); //DISPLAYS QUEUE CONTENTS
};

Queue::Queue() {

	front = nullptr;
	rear = nullptr;
}
void Queue::enqueue(int id, int t) {
	
	if (rear == nullptr) //IS EMPTY
	{
		Process* temp = new Process;
		temp->processID = id;
		temp->time = t;

		front = temp;
		rear = temp;

		cout << id << " ENQUEUED SUCCESSFULLY!";
		cout << t << " ENQUEUED SUCCESSFULLY!";
	}

	else if(front == rear) //ONLY ONE ELEMENT IS IN QUEUE
	{
		Process* temp = new Process;
		temp->processID = id;
		temp->time = t;

		rear = temp;
		front->next = rear;

		cout << id << " ENQUEUED SUCCESSFULLY!";
		cout << t << " ENQUEUED SUCCESSFULLY!";

	}

	else //FOR ALL REST INSERTIONS
	{
		Process* temp = rear;
		Process* temp2 = new Process;
		temp2->processID = id;
		temp2->time = t;
		temp->next = temp2;

		rear = temp2;

		cout << id << " ENQUEUED SUCCESSFULLY!";
		cout << t << " ENQUEUED SUCCESSFULLY!";
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
		int temp = front->time;
		Process* temp2 = front;
		rear = nullptr;
		front = nullptr;
		delete temp2;
		

		cout << temp << " DEQUEUED SUCCESSFULLY!";
		return temp;
	}
	
	else //FOR ALL REST ELEMENTS
	{
		int temp1 = front->time;
		Process* temp2 = front;
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
	cout << endl;
	Process* temp = front;
	while (temp != nullptr)
	{
		cout << temp->processID<<" "<<temp->time<< endl;
		temp = temp->next;
	}

	cout << endl;

}

int main()
{
	Queue obj;

	int option;
	bool end = false;

	int centiV;
	cout << "ENTER YOUR CENTINAL VALUE OF PROCESS ID: ";
	cin >> centiV;

	while (end != true)
	{
		int pID, t;
		cout << "ENTER THE PROCESS ID P:";
		cin >> pID;

		if (pID == centiV)
			end = true;

		else
		{
			end = false;
			cout << "ENTER THE TIME: ";
			cin >> t;

			obj.enqueue(pID, t);
			obj.display();
			system("pause");
			system("cls");
		}
	}

	

	return 0;

}