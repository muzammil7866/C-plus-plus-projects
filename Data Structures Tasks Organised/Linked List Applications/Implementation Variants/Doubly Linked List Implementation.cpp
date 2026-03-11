#include<iostream>
using namespace std;
class Node
{
public:
	int key;
	int data;
	Node* next;
	Node* prev;

	Node()
	{
		next = nullptr;
		prev = nullptr;
		data = 0;
		key = 0;
	}

	Node(int key, int data)
	{
		next = nullptr;
		prev = nullptr;
		this->data = data;
		this->key = key;

	}

	Node(int data)
	{
		key = 0;
		next = nullptr;
		prev = nullptr;
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

			while (temp != nullptr)
			{
				temp = temp->next;
				count++;
			}

			temp = head;

			for (int i = 0; i < count - 1; i++)
			{
				temp = temp->next;
			}

			n->key = ++(this->count);
			temp->next = n;
			n->prev = temp;


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

	void prependNode(Node* n)
	{
		if (head == nullptr)
		{
			head = n;
			n->key = 1;
		}

		else
		{
			Node* temp = new Node;
			temp = head;

			head = n;
			n->next = temp;
			n->key = 1;

			temp = head;
			int track = 1;
			while (temp != nullptr)
			{
				temp->key = track;
				track++;
				temp = temp->next;

			}
		}
	}

	void insertNode(int key, Node* n)
	{
		Node* temp = new Node;
		temp = head;

		if (key <= 0)
			cout << "Invalid Key! " << endl;


		else
		{
			while (temp->key != key - 1)
			{
				temp = temp->next;
			}

			Node* temp2 = new Node;
			temp2 = temp->next;
			temp->next = n;
			n->next = temp2;
			n->prev = temp;
			temp2->prev = n;

			temp = head;
			int track = 1;

			while (temp != nullptr)
			{
				temp->key = track;
				track++;
				temp = temp->next;

			}

		}

	}

	LinkedList(LinkedList& l1)
	{
		Node* temp = l1.head;

		while (temp != nullptr)
		{
			Node* newNode = new Node;
			newNode->data = temp->data;
			appendNode(newNode);

			temp = temp->next;
		}
	}

};

int main()
{
	LinkedList l1;
	Node n1(1);
	l1.appendNode(&n1);
	Node n2(2);
	l1.appendNode(&n2);
	Node n3(3);
	l1.appendNode(&n3);
	l1.outputList();

	LinkedList l2(l1);
	l2.outputList();



	system("pause");

	return 0;
}