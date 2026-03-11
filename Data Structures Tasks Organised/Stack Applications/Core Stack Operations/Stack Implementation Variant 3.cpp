#include <iostream>
using namespace std;
class Node
{
public:
	int num;
	Node* next;

	Node()
	{
		num = 0;
		next = nullptr;
	}

	Node(int num)
	{
		this->num = num;
		next = nullptr;
	}

};


class LinkedList
{

public:
	Node* head;
	
	LinkedList()
	{
		head = nullptr;
	}

	void appendNode(Node* obj)
	{
		if (head == nullptr)
		{
			head = obj;
		}

		else
		{
			Node* temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			temp->next = obj;
		}
	}

};
class Stack
{
public:
	int top;
	int size;
	int* arr;

	Stack()
	{
		top = -1;
		size = 10;
		int* arr = new int[10];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	void push(Node* obj)
	{
		if (top + 1 < size)
		{
			arr[++top] = obj->num;
			cout << endl;
		}

		else
		{
			cout << "YOUR STACK IS FULL! IT CANNOT PUSH MORE ITEMS INTO THE STACK." << endl;
		}
	}

	void pop()
	{
		if (top > -1)
		{

			arr[top] = 0;
			top--;
			cout << endl;
		}

		else
		{
			cout << "YOUR STACK IS EMPTY! IT CANNOT POP MORE ITEMS OFF THE STACK." << endl;
		}
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	void print()
	{
		for (int i = size-1;i >= 0; i--)
		{
			cout << arr[i] << endl;
		}
	}
};
int main()
{
	
	Stack obj;
	Node n1(81);
	cout << n1.num;
	obj.push(&n1);
	obj.print();




	return 0;	
}
