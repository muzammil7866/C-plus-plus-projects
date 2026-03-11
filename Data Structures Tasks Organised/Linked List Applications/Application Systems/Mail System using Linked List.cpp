#include <iostream>
using namespace std;
class Node
{
public:
	int key;
	Node* next;

	Node()
	{
		key = 0;
		next = nullptr;
	}

	Node(int key)
	{
		this->key = key;
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

	void appendNode(Node* n)
	{
		if (head == nullptr)
		{
			head = n;

		}
		else
		{

			Node* temp = head;
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

			temp->next = n;


		}
	}

	void outputList()
	{
		cout << "HEAD -> ";

		if (head == nullptr)
		{

		}

		else
		{
			Node* temp = head; //as we cannot lose the track of the first element via head

			while (temp != nullptr)
			{
				cout << temp->key << "-> ";
				temp = temp->next; //next element's address
			}
		}

		cout << "NULL" << endl;
	}

	Node* deleteNode(int key)
	{
	 
		bool found = false;

			if (head == nullptr)
			{
				found = false;
				cout << "\n\t\tMESSAGE WITH THIS KEY NOT FOUND AS THE LIST IS EMPTY!\n";
				return nullptr;
				
			}

			else if (head->key == key)
			{
				Node* temp2 = head;
				head = head->next;
				temp2->next = nullptr;
				found = true;
				return temp2;
			}

			Node* temp = head;

			while (temp->next != nullptr)
			{
			if (temp->next->key == key)
			{
				Node* temp2 = temp->next;
				temp->next = temp->next->next;
				temp2->next = nullptr;
				found = true;

				return temp2;
			}

			temp = temp->next;
			if (temp->next == nullptr)
			{
				cout << "\n\t\tMESSAGE WITH THIS KEY NOT FOUND IN THE DESIRED MAIL SECTION!\n";
				found = false;
			}
		}

			return nullptr;
	}
	
};
int main()
{
	LinkedList* unread = new LinkedList;
	LinkedList* read = new LinkedList;
	LinkedList* trash = new LinkedList;

	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	Node* n8 = new Node(8);
	Node* n9 = new Node(9);
	Node* n10 = new Node(10);

	unread->appendNode(n1);
	unread->appendNode(n2);
	unread->appendNode(n3);
	unread->appendNode(n4);
	unread->appendNode(n5);
	unread->appendNode(n6);
	unread->appendNode(n7);
	unread->appendNode(n8);
	unread->appendNode(n9);
	unread->appendNode(n10);

	cout << "\t\tUNREAD SECTION: \n";
	unread->outputList();

	bool end = false;
	int option;
	int key;

	while (end != true)
	{
		cout << "ENTER YOUR QUERY (1) FROM UNREAD TO READ (2) FROM READ TO TRASH (3) FROM UNREAD TO TRASH (4) TRASH TO READ (5) TO EXIT THE PROGRAM: ";
		cin >> option >> key;

		if (option == 1)
		{
			read->appendNode(unread->deleteNode(key));
			cout << "UNREAD: ";
			unread->outputList();
			cout << "READ: ";
			read->outputList();
			cout << "TRASH: ";
			trash->outputList();
			system("pause");
			system("cls");
		}

		else if (option == 2)
		{
			trash->appendNode(read->deleteNode(key));
			cout << "UNREAD: ";
			unread->outputList();
			cout << "READ: ";
			read->outputList();
			cout << "TRASH: ";
			trash->outputList();
			system("pause");
			system("cls");
		}

		else if (option == 3)
		{
			trash->appendNode(unread->deleteNode(key));
			cout << "UNREAD: ";
			unread->outputList();
			cout << "READ: ";
			read->outputList();
			cout << "TRASH: ";
			trash->outputList();
			system("pause");
			system("cls");

		}

		else if (option == 4)
		{
			read->appendNode(trash->deleteNode(key));
			cout << "UNREAD: ";
			unread->outputList();
			cout << "READ: ";
			read->outputList();
			cout << "TRASH: ";
			trash->outputList();
			system("pause");
			system("cls");
		}

		else if (option == 5)
		{
			end = true;
		}

		else
		{
			cout << "\n\t\tINVALID INPUT, ENTER AGAIN!\n";
			system("pause");
			system("cls");
		}
	}


	return 0;	
}
