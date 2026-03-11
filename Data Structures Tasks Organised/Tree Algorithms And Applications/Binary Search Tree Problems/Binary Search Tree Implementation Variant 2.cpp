#include<iostream>
using namespace std;
class Node
{
public:

	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

class BST
{
public:
	Node* root;

	BST()
	{
		root = nullptr;
	}


	void inOrder(Node* root)
	{
		if (root != nullptr)
		{
			inOrder(root->left);
			cout << root->data;
			inOrder(root->right);
		}
	}

	void preOrder(Node* root)
	{
		if (root != nullptr)
		{
			cout<< root->data;
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void postOrder(Node* root)
	{
		if (root != nullptr)
		{
			postOrder(root->left);
			postOrder(root->right);
			cout << root->data;
		}
	}


	bool checkBST(Node* root)
	{
		static Node* prev = nullptr; //according to the backward traversal order

		if (root != nullptr)
		{
			checkBST(root->left);

			if (prev != nullptr && root->data <= prev->data)
				return 0;

			prev = root;
			checkBST(root->right);
		}

		return true;
	}
};
int main()
{
	BST obj;
	Node node1(1);
	Node node2(2);
	Node node3(3);

	node1.left = &node2;
	node1.right = &node3;
	
	obj.root = &node1;

	cout<<obj.checkBST(obj.root);
	return 0;
}