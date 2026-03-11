#include <iostream>
#include<windows.h>
using namespace std;
//SOME GLOBAL MEMBERS FOR COUNTING NODES AND DEPTH OF BST
int sum = 0;
int depth = 0;
int depth2 = 0;
int totalNodes = 0;
int count = 0;
class Node {
public:
	int data;
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
public:
	Node* root;
	int count;


	BinarySearchTree() //DEFAULT CONSTRUCTOR TO INITIALISE BST 
	{
		root = nullptr;
		count = 0;
	}
	// Insert a value into the BST
	void insert(int value) {
		root = insertRecursive(root, value);
	}

	// Search for a value in the BST
	bool search(int value) {
		return searchRecursive(root, value);
	}


	void deleteNode(int value) //DELETS VALUE FROM THE TREE
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
		int temp = 0;
		temp = countNodesRecursive(root);
		totalNodes = 0;
		return temp;
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

	//FINDS THE INORDER PREDECESSOR FOR THE NODE TO BE DELETED
	Node* findInOrderPred(Node* ptr)
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

	//RELEASES MEMORY FOR THE TREE
	void destroyTree(Node* root) {
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
	
	void beforeGreaterTree(Node* root, int arr[]) {
		if (root == nullptr)
		{
			return;
		}

		else
		{
			beforeGreaterTree(root->left, arr);
			arr[count] =  root->data;
			count++;
			beforeGreaterTree(root->right, arr);
		}
	}

	void greaterTree()
	{
		int size = countNodes();
		int* arr = new int[size];

		beforeGreaterTree(root, arr);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";

		}
		count = 0;
	
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j  < size; j++)
			{
				arr[i] += arr[j];

			}

		}
	
	}

	Node* convertBSTToGreaterTree(Node*& root)
	{
		if (root != nullptr)
		{
			convertBSTToGreaterTree(root->right);
			sum += root->data;
			root->data = sum;
			convertBSTToGreaterTree(root->left);

		}

		return root;
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
		cout << "(1) INSERT \n(2) SEARCH \n(3) TRAVERSE \n(4) RELEASE MEMORY USING DESTRUCTOR \n(5) COUNT NODES \n(6) GET HEIGHT \n(7) EXIT MENU \n(8) DELETE \n(9) TO GREATER TREE" << endl;

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
			int num;
			cout << "ENTER THE VALUE THAT YOU WANT TO DELETE: ";
			cin >> num;
			bst.deleteNode(num);

		}

		else if (option == 9)
		{
			bst.insert(4);
			bst.insert(1);
			bst.insert(6);
			bst.insert(0);
			bst.insert(2);
			bst.insert(5);
			bst.insert(7);
			bst.insert(3);
			bst.insert(8);

			cout << "CURRENT NODES IN TREE USING INORDER TRAVERSAL: \n";
			bst.inorderTraversal();

			system("pause");
			cout << "\nNOW CONVERTING TO BST";
			for (int i = 0; i < 3; i++)
			{
				cout << ".";
				Sleep(700);
			}


			bst.convertBSTToGreaterTree(bst.root);

			cout << "\nAFTER CONVERSION USING INORDER TRAVERSAL: \n";
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