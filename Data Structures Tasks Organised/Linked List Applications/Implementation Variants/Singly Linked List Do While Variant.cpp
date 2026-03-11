#include<iostream>
using namespace std;
class Node
{
public:
	int key;
	int data;
	Node* next;

	Node()
	{
		next = nullptr;
		data = 0;
		key = 0;
	}

	Node(int key, int data)
	{
		next = nullptr;
		this->data = data;
		this->key = key;

	}

	Node(int data)
	{
		key = 0;
		next = nullptr;
		this->data = data;

	}

	void output()
	{
		cout << "Key: " << key << endl;
		cout << "Data: " << data << endl;

	}
};


class LinkedList {

public:
	Node* head;
	int count;

	LinkedList()
	{
		head = nullptr;
		count = 0;
	}

	void appendNode(Node* n)
	{
		if (head == nullptr)
		{
			head = n;
			n->key = ++count;
		}
		else
		{

			Node* temp = new Node;
			temp = head;
			int count = 0;

			do
			{
				temp = temp->next;
				count++;
			} while (temp != nullptr);

			temp = head;

			for (int i = 0; i < count - 1; i++)
			{
				temp = temp->next;
			}

			n->key = ++(this->count);
			temp->next = n;


		}
	}

	void outputList()
	{
		cout << "Head -> ";

		if (head == nullptr)
		{

		}

		else
		{
			Node* temp = new Node;
			temp = head; //as we cannot lose the track of the first element via head

			while (temp != nullptr)
			{
				cout << "(" << temp->key << ") " << temp->data << "-> ";
				temp = temp->next; //next element's address
			}
		}

		cout << "NULL" << endl;
	}

};

int main()
{
	




	system("pause");

	return 0;
}