//THIS QUESTION REVERSES THE LIST USING RECURSION METHOD AND THEN PRINTS IT
#include <iostream>
using namespace std;
class Node
{
public:
	int num;
	Node* next;

	Node(int a) //parameterized constructor for initialising data members
	{
		num = a;
		next = nullptr;
	}

	Node() //default constructor for initialising data members
	{
		num = 0;
		next = nullptr;
	}
};

class LinkedList {

public:
	Node* head;

	LinkedList() //default constructor for initialising data members
	{
		head = nullptr;
	}

	void insert(int a) //inserts node
	{

		if (head == nullptr) 
		{
			Node* thisNode = new Node(a);
			head = thisNode;
		}

		else 
		{
			Node* temp = head;

			while (temp->next != nullptr) 
			{
				temp = temp->next;
			}
			Node* thisNode = new Node(a);
			temp->next = thisNode;

		}
	}

	Node* reverseListRecursive(Node*& head) //reverses list recursively
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}


			Node* newHead = reverseListRecursive(head->next);
			head->next->next = head;
			head->next = nullptr;

			return newHead;	
	}



	void display() //displays list
	{
		Node* temp = head;

		while (temp != nullptr)
		{
			cout << temp->num << "->";
			temp = temp->next;
		}

		cout << "nullptr";
	}


};
int main()
{
	LinkedList obj;
	obj.insert(1);
	obj.insert(2);
	obj.insert(3);
	obj.insert(4);

	obj.display();

	obj.head = obj.reverseListRecursive(obj.head);
	
	cout << endl;
	
	obj.display();


	return 0;	
}
