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

	void deleteNode(int key)
	{
		if (key < 1)
		{
			cout << "Invalid key entered! " << endl;
		}

		else if (key == 1)
		{
			delete head;
			head = nullptr;
		}

		else
		{
			Node* temp = new Node;

			temp = head;

			while (temp->key != key - 1)
			{
				temp = temp->next;
			}

			Node* temp2 = (temp->next)->next;
			delete temp->next;
			temp->next = nullptr;
			temp->next = temp2;

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




	void updateNode(int key, int value)
	{
		if (key < 1)
			cout << "Invalid key!";

		else if (head == nullptr)
		{
			cout << "This list is empty!";
		}


		else if (key == 1)
		{
			head->data = value;
		}


		else
		{
			Node* temp = new Node;
			temp = head;

			int track = 0;

			while (temp != nullptr)
			{
				temp = temp->next;
				track++;

			}



			if (key > track)
			{
				cout << "Your key is not found! ";
			}

			else
			{
				temp = head;

				while (temp->key != key)
				{
					temp = temp->next;
				}

				temp->data = value;
			}
		}

	}

	LinkedList* merge(LinkedList* l1, LinkedList* l2, LinkedList*l3, LinkedList* l4)
	{
		Node* temp = new Node;
		temp = l1->head;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = l2->head;

		temp = l1->head;
		int track2 = 1;

		while (temp != nullptr)
		{
			temp->key = track2;
			track2++;
			temp = temp->next;

		}


		temp = l1->head;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = l3->head;

		temp = l1->head;
		int track3 = 1;

		while (temp != nullptr)
		{
			temp->key = track3;
			track3++;
			temp = temp->next;

		}

		l4->head = l1->head;
		return l4;
	}

	void bubbleSort(LinkedList l1)
	{
		Node* temp = l1.head;
		temp = l1.head;

		while (temp->next != nullptr)
		{
			Node* temp2 = temp->next;

			while (temp2 != nullptr)
			{
				if (temp->data >= temp2->data)
				{
					int num = temp->data;
					temp->data = temp2->data;
					temp2->data = num;
				}

				temp2 = temp2->next;

			}

			temp = temp->next;
		}

	}
};

int main()
{
	LinkedList l1;
	srand(time(0));
	for (int i = 0; i < 3; i++)
	{
		Node* n1 = new Node(rand() % 10 + 1);
		l1.appendNode(n1);
	}
	l1.outputList();
	LinkedList l2;

	for (int i = 0; i < 3; i++)
	{
		Node* n1 = new Node(rand() % 50 + 1);
		l2.appendNode(n1);
	}
	l2.outputList();

	LinkedList l3;

	for (int i = 0; i < 3; i++)
	{
		Node* n1 = new Node(rand() % 100 + 1);
		l3.appendNode(n1);
	}
	l3.outputList();
	LinkedList l4;

	LinkedList* l5 = l1.merge(&l1, &l2, &l3, &l4);
	l5->outputList();
	l5->bubbleSort(*l5);
	l5->outputList();
	system("pause");

	return 0;
}