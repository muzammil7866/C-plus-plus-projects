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

	Node(int a)
	{
		num = a;
		next = nullptr;
	}
};
class CircularLinkedList
{
public:
	Node* head;

	CircularLinkedList()
	{
		head = nullptr;
	}

	void prepend(Node* obj)
	{
		if (head == nullptr)
		{
			head = obj;
			obj->next = head;
		}

		else
		{
			Node* temp = head;

			while (temp->next != head)
			{
				temp = temp->next;
			}

			obj->next = head;
			temp->next = obj;
			head = obj;
		}
	}

	void append(Node* obj)
	{
		if (head == nullptr)
		{
			head = obj;
			obj->next = head;
		}

		else
		{
			Node* temp = head;

			while (temp->next != head)
			{
				temp = temp->next;
			}

			temp->next = obj;
			obj->next = head;

		}
	}

	void output()
	{
		if (head == nullptr)
		{
			cout << "HEAD -> NULLPTR";
		}

		else
		{
			Node* temp = head;

			cout << "HEAD -> ";

			do
			{
				cout << temp->num << " -> ";
				temp = temp->next;
			} while (temp != head);

			cout << " NULLPTR";
			cout << endl;

		}
	}

	void skip(int m)
	{
		


	}

};
int main()
{
	CircularLinkedList* c1 = new CircularLinkedList;
	int num;
	cout << "ENTER THE NUMBER OF PEOPLE: ";
	cin >> num;
	int m;
	cout << "ENTER THE NUMBER M TO CYCLE THROUGH THE CIRCLE WHICH MEANS M-1 NODE(S) ARE SKIPPED: ";
	cin >> m;


	for (int i = 0; i < num; i++)
	{
		Node* obj = new Node(i + 1);
		c1->append(obj);
	}

	c1->output();

	int count = num;
	Node* temp = c1->head;
	
	while (count > 1)
	{
		Node* temp3 = temp;

		for (int i = 0; i < m - 1; i++)
		{
			temp = temp->next;
		}

		if (temp->next == c1->head)
		{
			c1->head = c1->head->next;
		}

		temp->next = (temp->next)->next;
		temp = temp->next;

		count--;
		c1->output();
	}


	return 0;
}
