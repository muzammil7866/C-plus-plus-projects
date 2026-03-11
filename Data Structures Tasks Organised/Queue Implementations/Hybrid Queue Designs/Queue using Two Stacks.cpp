#include <iostream>
using namespace std;
class Stack
{
public:
	int top;
	int size;
	int* array;


	Stack()
	{
		top = -1;
		size = 5;
		array = new int[size];
		for (int i = 0; i <= size - 1; i++)
		{
			array[i] = 0;
		}
	}


	void push()
	{
		if (top + 1 < size)
		{
			top++;
			cout << "ENTER THE ITEM WHICH YOU WANT TO ENTER INTO THE STACK AT THE INDEX " << top << ": ";
			cin >> array[top];
			cout << endl;
		}

		else
		{
			cout << "YOUR STACK IS FULL! IT CANNOT PUSH MORE ITEMS INTO THE STACK." << endl;
		}
	}

	void push(int value)
	{
		if (top + 1 < size)
		{
			top++;
			array[top] = value;
			cout << endl;
		}

		else
		{
			cout << "YOUR STACK IS FULL! IT CANNOT PUSH MORE ITEMS INTO THE STACK." << endl;
		}
	}

	int pop()
	{
		if (top > -1)
		{
			int temp = array[top];
			array[top] = 0;
			top--;
			cout << endl;

			return temp;
		}

		else
		{
			cout << "YOUR STACK IS EMPTY! IT CANNOT POP MORE ITEMS OFF THE STACK." << endl;
			return -1;
		}


	}

	int peek(int pos)
	{
		return array[pos - 1];
	}

	void display()
	{
		for (int i = size - 1; i >= 0; i--)
		{
			cout << array[i];
			cout << endl;
		}
	}

	int count()
	{
		return top + 1;
	}

	bool isFull()
	{
		if (top == size - 1)
		{
			return true;
		}

		else
			return false;
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}

		else
			return false;
	}
};

class queueStack {

	Stack S1, S2;

public:
	queueStack();
	bool isEmpty();
	bool isFull();
	void enqueue(int value);
	int dequeue();
	~queueStack();
	Stack getS1();
	Stack getS2();
};

Stack queueStack::getS1()
{
	return S1;
}

Stack queueStack::getS2()
{
	return S2;
}

queueStack::queueStack()
{
	//automatically memory allocated w.r.t. constructor of Stack
}

bool queueStack::isEmpty() {

	if (S1.top == -1)
		return true;

	else
		return false;
}
bool queueStack::isFull() {

	if (S1.top == S1.size - 1)
	{
		return true;
	}

	else
		return false;
}
void queueStack::enqueue(int value) {


	if (!S1.isFull())
	{
		while (!S2.isEmpty())
		{
			S1.push(S2.pop());
		}


		S1.push(value);

		while (S1.top != -1)
		{
			S2.push(S1.pop());
		}
	}

	else
	{
		cout << "CANNOT ENQUEUE ANY MORE ITEMS AS THE QUEUE SIZE IS FULL!";
	}

}
int queueStack::dequeue() {

	return S2.pop();
}
queueStack::~queueStack() {

	//automatically memory released w.r.t. destructor of Stack

}

int main() {

	queueStack Q1;
	Q1.enqueue(178);
	Q1.enqueue(-43);
	Q1.enqueue(953);

	cout << Q1.dequeue(); // 178 will be printed


}
