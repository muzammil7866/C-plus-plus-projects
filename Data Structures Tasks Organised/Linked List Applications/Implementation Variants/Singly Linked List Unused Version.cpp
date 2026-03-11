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

	LinkedList* removeRepetitions(LinkedList l1)
	{
		int count = 0;

		LinkedList* l2 = new LinkedList;

		Node* temp = l1.head;

		while (temp != nullptr)
		{
			bool match = true;
			Node* temp2 = temp->next;

			while (match != false)
			{
				if (temp2 == nullptr)
				{
					break;
				}

				else
				{
					if (temp->data == temp2->data)
					{
						match = true;
						temp2 = temp2->next;
					}

					else
					{
						match = false;
					}


				}
			}

			Node* temps = new Node(temp->data);
			l2->appendNode(temps);

			temp = temp2;
		}

		return l2;
	}

	void SortedInsert(LinkedList l1, Node* n)
	{
		l1.appendNode(n);
		Node* temp = l1.head;
		temp = l1.head;

		while (temp->next != nullptr)
		{
			Node* temp2 = temp->next;

			while (temp2 != nullptr)
			{
				if (temp->data <= temp2->data)
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
	Node* n = new Node(7);
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		Node* n1 = new Node(rand() % 25 + 1);
		l1.appendNode(n1);
	}

	l1.outputList();
	l1.SortedInsert(l1, n);
	l1.outputList();

	Node* n2 = new Node(17);
	l1.insertNode(3, n2);
	l1.outputList();





	system("pause");
	return 0;

}