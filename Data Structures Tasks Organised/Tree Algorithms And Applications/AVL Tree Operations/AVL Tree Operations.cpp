
// MUZAMMIL BIN SOHAIL 
// 22F - 3110 
// BS - AI
// SECTION: 3A1

#include <iostream>
using namespace std;
//some global variables for height calculation
int depth = 0;
int depth2 = 0;
int totalNodes = 0;
class Node {
public:
	int data;
	Node* left;
	Node* right;
	int height;

	//PARAMETERIZED CONSTRUCTOR TO INITIALISE NODE
	Node(int value) //done
	{
		data = value;
		left = nullptr;
		right = nullptr;
		height = 0;
	}
};
class AVLTree {
private:
	Node* root;


	int calculateHeight(Node*& root) //TO CALCULATE HEIGHT OF THE NODE
	{
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

	int height(Node* node) //CALLS THE HEIGHT CALCULATION FUNCTION
	{	node->height = calculateHeight(node);
		return node->height;
	}


	int balanceFactor(Node* node) //CALCULATES THE BALANCE FACTOR FOR THE NODE
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			return 0;
		}

		else if (node->left == nullptr && node->right != nullptr)
		{
			return -1 - calculateHeight(node->right);
		}

		else if (node->left != nullptr && node->right == nullptr)
		{
			return calculateHeight(node->left) - 1;
		}

		else
		{
			return calculateHeight(node->left) - calculateHeight(node->right);
		}
	}

	int Max(int a, int b) //COMPARES TWO INTEGER VALUES TO FIND THE LARGEST
	{
		if(a >= b)
		{
			return a;
		}

		else
		{
			return b;
		}
	}
	Node* rotateLeft(Node* node	) //ROTATES THE TREE TO THE LEFT
	{
		Node* K2;
		K2 = node->right;
		node->right = K2->left;
		K2->left = node;
		node->height = Max(height(node->left), height(node->right)) + 1;
		K2->height = Max(height(K2->right), node->height) + 1;
		Node * newRoot =  K2;
		return newRoot;
	}
	Node* rotateRight(Node* node) //ROTATES THE TREE TO THE RIGHT
	{
		Node* temp;
		temp = node->left;
		node->left = temp->right;
		temp->right = node;
		node->height = Max(height(node->left), height(node->right)) + 1;
		temp->height = Max(height(temp->left), node->height) + 1;
		Node* newRoot = temp;
		return newRoot;
	}
	Node* balance(Node* node) //BALANCES THE TREE IN ACCORDANCE TO THE NEED
	{

		//if (balanceFactor(node) < -1 || balanceFactor(node) > 1)
		//{
		//	//rotate left
		//	if (balanceFactor(node) < 0 && balanceFactor(node->right) < 0)
		//	{
		//		rotateLeft(node);
		//	}

		//	//rotate right
		//	if (balanceFactor(node) > 0 && balanceFactor(node->right) > 0)
		//	{
		//		rotateRight(node);
		//	}

		//	//rotate left
		//	if (balanceFactor(node) < 0 && balanceFactor(node->right) > 0)
		//	{
		//		//rotateLeft(node);
		//	}
		//	//rotate left
		//	if (balanceFactor(node) < 1 && balanceFactor(node->left) < 0)
		//	{
		//		//rotateLeft(node);
		//	}
		//}


		//else
		//{
		//	return node;
		//}

		return node;

	}
	Node* insertInto(Node*& node, int key) //INSERTS A NODE INTO THE TREE AND BALANCES IT ALONG
	{
		if (node == nullptr)
		{
			Node* newNode = new Node(key);
			node = newNode;
		}

		else
		{
			if (key > node->data)
			{
				insertInto(node->right, key);
			}

			else if (key < node->data)
			{
				insertInto(node->left, key);
			}

		}

		return balance(node);
	}

	Node* insert(Node* node, int key) //CALLS THE INSERT FUNCTION
	{

		node = insertInto(node, key);
		return node;
	}
	Node* findMin(Node* node) //DUMMY FUNCITON GIVEN BY SIR, IT WAS OPTIONAL TO USE!
	{
		return node;
	}

	Node* findInOrderPred(Node* root) //FINDS THE INORDER PREDECESSOR TO BE REPLACED BY NODE INTENDED TO BE DELETED
	{
		Node* ptr = root->left;

		while (ptr->right != nullptr)
		{
			ptr = ptr->right;
		}

		return ptr;
	}

	Node* DoubleRotateRight(Node* K3) //FIRST ROTATES THE TREE LEFT THEN ROTATES RIGHT
	{

		
		K3->left = rotateLeft(K3->left);
		return rotateRight(K3);

	}

	Node* DoubleRotateLeft(Node* K1) //FIRST ROTATES THE TREE RIGHT THEN ROTATES LEFT
	{

		
		K1->right = rotateRight(K1->right);
		
		return rotateLeft(K1);

	}

	Node* deleteNodeRecursive(Node*& root, int value) //DELETES THE NODE FROM THE TREE
	{

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
				iPre = findInOrderPred(root);
				root->data = iPre->data;
				deleteNodeRecursive(root->left, iPre->data);

			}

		}

		return root;
	}
	Node* remove(Node* node, int key) //CALLS THE DELETING NODE FUNCTION
	{
		node = deleteNodeRecursive(node, key);

		return balance(node);
	}
	void inorderRecursive(Node* root) //TRAVSERSES THE TREE USING INORDER
	{
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
	void preorderRecursive(Node* root) //TRAVSERSES THE TREE USING PREORDER
	{
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
	void postorderRecursive(Node* root) //TRAVSERSES THE TREE USING POSTORDER
	{

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
public:
	AVLTree() //DEFAULT CONSTRUCTOR TO INITIALISE THE TREE
	{
		root = nullptr;
	}
	void insert(int key) //CALLS THE INSERT FUNCTION TO INSERT VALUE INTO THE TREE
	{
		root = insert(root, key);
	}


	void remove(int key) //CALLS THE DELETE FUNCTION TO REMOVE A VALUE FROM THE TREE
	{
		if (searchRecursive(root, key))
			root = deleteNodeRecursive(root, key);
		else
		{
			cout << "VALUE NOT IN THE TREE!";
		}
	}
	void display() //DISPAYS THE BST IN THE DESIRED ORDER
	{
		int option;
		cout << "HOW DO YOU WANT TO DISPLAY THE TREE, ENTER (1) FOR PREORDER, (2) FOR INORDER, (3) FOR POSTORDER: " << endl;
		cin >> option;

		if (option == 1)
		{
			preorderRecursive(root);
		}

		else if (option == 2)
		{
			inorderRecursive(root);
		}

		else if (option == 3)
		{
			postorderRecursive(root);
		}

		else
		{
			cout << "INVALID INPUT!";
		}

	}

	void Traversal() //PRINTS IN ALL THREE TRAVERSAL ORDERS
	{
		inorderRecursive(root);
		preorderRecursive(root);
		postorderRecursive(root);
	}

	bool searchRecursive(Node* root, int value) //SEARCHES THE VALUE INTO THE TREE
	{

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

	bool checkAVL(Node* root) //CHECKS IF TREE IS AN AVL OR NOT
	{
		bool check = true;

		if (root!= nullptr)
		{
			checkAVL(root->left);
			cout << getBalanceFactor(root)<<" ";
			if (balanceFactor(root) < -1 || balanceFactor(root) > 1)
			{
				 check =  false;
				 
			}

			checkAVL(root->right);
		}

		return check;
	}

	Node* getRoot() //RETURNS THE ROOT OF TREE
	{
		return root;
	}

	int getBalanceFactor(Node* node) //RETURNS THE BALANCE FACTOR OF THE PROVIDED NODE
	{
		return balanceFactor(node);
	}
};
int main()
{
	AVLTree avl;	
	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) INSERT \n(2) CHECK FOR AVL \n(3) TRAVERSE \n(4) DELETE \n(5) EXIT MENU" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int data;
			cout << "ENTER DATA: ";
			cin >> data;
			avl.insert(data);
		}

		else if (option == 2)
		{
			if (avl.getRoot() == nullptr)
			{
				cout << "TREE IS EMPTY!";
			}

			else
			{
				bool check = avl.checkAVL(avl.getRoot());
				cout << endl;
				if (check == false)
				{
					cout << "TREE IS NOT AVL!";
				}

				else
				{
					cout << "TREE IS AVL";
				}
			}
		}
		else if (option == 3)
		{
			avl.display();
		}
		else if (option == 4)
		{
			int num;
			cout << "ENTER THE VALUE THAT YOU WANT TO DELETE: ";
			cin >> num;
			avl.remove(num);
		}
		else if (option == 5)
		{
			end = true;

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