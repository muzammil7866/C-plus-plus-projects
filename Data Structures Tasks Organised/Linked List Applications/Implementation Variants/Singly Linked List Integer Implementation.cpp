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
		key=0;
	}

	Node(int key, int data)
	{
		next = nullptr;
		this->data= data;
		this->key= key;

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


};

int main()
{
	Node* n1 = new Node(5);
	n1->output();
	LinkedList l1;
	l1.outputList();
	l1.appendNode(n1);
	l1.outputList();
	Node* n2 = new Node(76);
	l1.appendNode(n2);
	l1.outputList();
	Node* n3 = new Node(33);
	l1.appendNode(n3);
	l1.outputList();

	Node* n4 = new Node(15);
	l1.prependNode(n4);
	l1.outputList();
	
	LinkedList l2;
	Node* n5 = new Node(99);
	l2.prependNode(n5);
	l2.outputList();

	Node* n6 = new Node(66);
	l1.insertNode(3, n6);
	l1.outputList();
	l1.deleteNode(3);
	l1.outputList();

	LinkedList l3;
	Node* n7 = new Node(22);
	l3.appendNode(n7);
	l3.outputList();
	l3.deleteNode(1);
	l3.outputList();
	l3.updateNode(1, 6);
	l3.outputList();
	



system("pause");

	return 0;
}