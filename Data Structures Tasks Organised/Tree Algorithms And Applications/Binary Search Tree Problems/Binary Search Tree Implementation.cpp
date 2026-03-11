#include <iostream>
using namespace std;
//SOME GLOBAL FUNCTIONS FOR COUNTING NODES AND DEPTH OF BST
int depth = 0;
int depth2 = 0;
int totalNodes = 0;
class Node 
{
public:
	char data;
	Node* left;
	Node* right;

	Node(int value) //PARAMETERISED CONSTRUCTOR TO INITIALSE VALUES
	{
		data = value;
		left = nullptr;
		right = nullptr;
	}
};
class BinarySearchTree
{
private:
	Node* root;

public:
	BinarySearchTree() //DEFAULT CONSTRUCTOR TO INITIALISE BST 
	{
		root = nullptr;
	}
	// Insert a value into the BST
	void insert(int value) {
		root = insertRecursive(root, value);
	}

	// Search for a value in the BST
	bool search(int value) {
		return searchRecursive(root, value);
	}


	void deleteNode(int value) //SIR MENTIONED THAT THIS IS NOT INCLUDED AS ITS IMPLEMENTATION IS NOT DONE IN DS COURSE YET
	{
		if (search(value))
			root = deleteNodeRecursive(root, value);

		else
		{
			cout << "VALUE NOT IN THE TREE!";
		}

	}


	// In-order traversal of the BST
	void inorderTraversal() {
		inorderRecursive(root);
	}


	// Pre-order traversal of the BST
	void preorderTraversal() {
		preorderRecursive(root);
	}

	// Post-order traversal of the BST
	void postorderTraversal() {
		postorderRecursive(root);
	}

	// Calculate the height of the BST
	int getHeight() {
		return calculateHeight(root);
	}


	// Count the total number of nodes in the BST
	int countNodes() {
		return countNodesRecursive(root);
	}


	// Find of Lowest Common Ancestor of given nodes in the BST
	Node* findLCA(int n1, int n2) {
		return findRLCA(root, n1, n2);
	}
	// Destructor
	~BinarySearchTree() {
		destroyTree(root);
	}

	void display() //DISPAYS THE BST IN THE DESIRED ORDER
	{
		int option;
		cout << "HOW DO YOU WANT TO DISPLAY THE TREE, ENTER (1) FOR PREORDER, (2) FOR INORDER, (3) FOR POSTORDER: " << endl;
		cin >> option;

		if (option == 1)
		{
			preorderTraversal();
		}

		else if (option == 2)
		{
			inorderTraversal();
		}

		else if (option == 3)
		{
			postorderTraversal();
		}

		else
		{
			cout << "INVALID INPUT!";
		}

	}

private:

	// Function for inserting node in BST
	Node* insertRecursive(Node*& root, int value) {

		if (root == nullptr)
		{
			Node* newNode = new Node(value);
			root = newNode;
		}

		else
		{
			if (value > root->data)
			{
				insertRecursive(root->right, value);
			}

			else if (value < root->data)
			{
				insertRecursive(root->left, value);
			}

		}


		return root;
	}
	// Function for searching value in BST
	bool searchRecursive(Node* root, int value) {

		if (root == nullptr)
		{
			return false;
		}
		else if (root->data == value)
		{
			return true;
		}

		else
		{
			if (value > root->data)
			{
				searchRecursive(root->right, value);
			}

			else
			{
				searchRecursive(root->left, value);
			}
		}

	}

	Node* findInOrderPred(Node* ptr) //FINDS THE INORDER PREDECESSOR FOR THE NODE TO BE DELETED 
	{
		if (ptr->right != nullptr)
			findInOrderPred(ptr->right);

		return ptr;
	}
	// Function to delete node according to value in BST
	Node* deleteNodeRecursive(Node*& root, int value) {

		if (root == nullptr)
		{
			return root;
		}

		else if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr; //important to do this
		}

		else if (value > root->data)
		{
			deleteNodeRecursive(root->right, value);
		}

		else if (value < root->data)
		{
			deleteNodeRecursive(root->left, value);
		}


		else
		{
			if (root->right == nullptr && root->left != nullptr)
			{
				root->data = root->left->data;
				deleteNodeRecursive(root->left, root->data);
			}

			else if (root->left == nullptr && root->right != nullptr)
			{
				root->data = root->right->data;
				deleteNodeRecursive(root->right, root->data);
			}
			else
			{
				Node* iPre;
				iPre = findInOrderPred(root->left);
				root->data = iPre->data;
				deleteNodeRecursive(root->left, iPre->data);

			}

		}

		return root;
	}

	// Function for Inorder Traversal in BST
	void inorderRecursive(Node* root) {
		if (root == nullptr)
		{
			return;
		}

		else
		{
			inorderRecursive(root->left);
			cout << root->data << " ";
			inorderRecursive(root->right);
		}
	}

	// Function for Pre-Order Traversal in BST 
	void preorderRecursive(Node* root) {
		if (root == nullptr)
		{
			return;
		}

		else
		{
			cout << root->data << " ";
			preorderRecursive(root->left);
			preorderRecursive(root->right);
		}
	}

	// Function for PostOrder Traversal in BST
	void postorderRecursive(Node* root) {

		if (root == nullptr)
		{
			return;
		}

		else
		{

			postorderRecursive(root->left);
			postorderRecursive(root->right);
			cout << root->data << " ";
		}
	}


	// Function to calculate the height of BST
	int calculateHeight(Node* root) {
		if (root == nullptr)
		{
			return -1;
		}

		else
		{
			depth = calculateHeight(root->left) + 1;
			depth2 = calculateHeight(root->right) + 1;

			if (depth >= depth2)
			{
				return depth;
			}

			else
				return depth2;

		}
	}



	// Function to count number of nodes in BST
	int countNodesRecursive(Node* root) {
		if (root == nullptr)
		{
			return 0;
		}

		else
		{
			totalNodes += 1;
			countNodesRecursive(root->left);
			countNodesRecursive(root->right);


			return totalNodes;
		}
	}


	// Function to find LCA of provided nodes in BST
	Node* findRLCA(Node* root, int n1, int n2) {
		return root;
	}
	//RELEASES MEMORY OF THE TREE
	void destroyTree(Node* root) 
	{
		if (root == nullptr)
		{
			return;
		}

		else
		{
			Node* temp = root->left;
			Node* temp2 = root->right;
			delete root;
			root = nullptr;

			destroyTree(temp);
			destroyTree(temp2);
		}
	}
};
// Main function have menu driven interface
int main() {

	BinarySearchTree bst;

	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) INSERT \n(2) SEARCH \n(3) TRAVERSE \n(4) RELEASE MEMORY USING DESTRUCTOR \n(5) COUNT NODES \n(6) GET HEIGHT \n(7) EXIT MENU \n(8) DELETE NODES ACCORDING TO THE QUESTION!" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int data;
			cout << "ENTER DATA: ";
			cin >> data;
			bst.insert(data);
		}

		else if (option == 2)
		{
			int data;
			cout << "ENTER ITEM TO SEARCH: ";
			cin >> data;
			if (!bst.search(data))
			{
				cout << endl << "NOT FOUND!";
			}

			else {
				cout << endl << "FOUND!";
			}
		}
		else if (option == 3)
		{
			bst.display();
		}
		else if (option == 4)
		{
			bst.~BinarySearchTree();
		}
		else if (option == 5)
		{
			cout << bst.countNodes();

		}

		else if (option == 6)
		{
			if (bst.getHeight() == -1)
				cout << "0";

			else
				cout << bst.getHeight();

		}


		else if (option == 7)
		{
			end = true;

		}

		else if (option == 8)
		{
			bst.insert('L');
			bst.insert('D');
			bst.insert('P');
			bst.insert('C');
			bst.insert('H');
			bst.insert('A');
			bst.insert('F');
			bst.insert('J');

			cout << "CURRENT NODES IN THE TREE USING INORDER TRAVERSAL: \n";
			bst.inorderTraversal();


			bst.deleteNode('J');
			bst.deleteNode('C');
			bst.deleteNode('L');
			bst.deleteNode('D');
			bst.deleteNode('A');

			cout << "\nAFTER DELETION THE NODES IN THE TREE USING INORDER TRAVERSAL: \n";
			bst.inorderTraversal();

		}
		else
		{
			cout << "INVALID OPTION!" << endl;
		}

		cout << endl;
		system("pause");
		system("cls");


	}
	return 0;

}