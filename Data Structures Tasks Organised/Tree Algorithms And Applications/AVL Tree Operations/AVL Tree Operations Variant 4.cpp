
#include <iostream>
using namespace std;
//some global variables for height calculation
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
public:
	Node* root;

	int calculateHeight(Node* root) {
		if (root == nullptr) {
			return -1;
		}
		else {
			int leftHeight = calculateHeight(root->left);
			int rightHeight = calculateHeight(root->right);
			return 1 + max(leftHeight, rightHeight);
		}
	}

	int height(Node* node) //CALLS THE HEIGHT CALCULATION FUNCTION
	{
		node->height = calculateHeight(node);
		return node->height;
	}


	int balanceFactor(Node* node) //CALCULATES THE BALANCE FACTOR FOR THE NODE
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			cout << 0;
			return 0;
		}

		else if (node->left == nullptr && node->right != nullptr)
		{
			cout << -1 - calculateHeight(node->right);
			return -1 - calculateHeight(node->right);
		}

		else if (node->left != nullptr && node->right == nullptr)
		{
			cout << calculateHeight(node->left) - (-1);
			return calculateHeight(node->left) - (-1);
		}

		else
		{
			cout << calculateHeight(node->left) - calculateHeight(node->right);
			return calculateHeight(node->left) - calculateHeight(node->right);
		}
	}

	int Max(int a, int b) //COMPARES TWO INTEGER VALUES TO FIND THE LARGEST
	{
		if (a >= b)
		{
			return a;
		}

		else
		{
			return b;
		}
	}
	void  rotateLeft(Node*& node) //ROTATES THE TREE TO THE LEFT
	{
		Node* K2;
		K2 = node->right;
		node->right = K2->left;
		K2->left = node;
		//node->height = Max(height(node->left), height(node->right)) + 1;
		//K2->height = Max(height(K2->right), node->height) + 1;
		node = K2;
	}
	void rotateRight(Node*& node) //ROTATES THE TREE TO THE RIGHT
	{
		Node* temp;
		temp = node->left;
		node->left = temp->right;
		temp->right = node;
		//node->height = Max(height(node->left), height(node->right)) + 1;
		//temp->height = Max(height(temp->left), node->height) + 1;
		node = temp;
	}

	void balance(Node*& node) //BALANCES THE TREE IN ACCORDANCE TO THE NEED
	{

		if (balanceFactor(node) < -1 || balanceFactor(node) > 1)
		{
			//rotate left
			if (balanceFactor(node) < 0 && balanceFactor(node->right) < 0)
			{
				rotateLeft(node);

			}

			//rotate right
			else if (balanceFactor(node) > 0 && balanceFactor(node->left) > 0)
			{
				rotateRight(node);

			}

			//double rotate left
			if (balanceFactor(node) < 0 && balanceFactor(node->right) > 0)
			{
				DoubleRotateLeft(node);
			}
			//double rotate right
			if (balanceFactor(node) > 0 && balanceFactor(node->left) < 0)
			{
				DoubleRotateRight(node);
			}
		}



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

		balance(node);
		return node;
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

	Node* DoubleRotateRight(Node*& K3) //FIRST ROTATES THE TREE LEFT THEN ROTATES RIGHT
	{


		rotateLeft(K3->left);
		rotateRight(K3);
		return K3;

	}

	Node* DoubleRotateLeft(Node*& K1) //FIRST ROTATES THE TREE RIGHT THEN ROTATES LEFT
	{


		rotateRight(K1->right);
		rotateLeft(K1);

		return K1;
	}

	Node* deleteNodeRecursive(Node*& root, int value) //DELETES THE NODE FROM THE TREE
	{

		//if (root == nullptr)
		//{
		//	return root;
		//}

		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr; //important to do this
			return root;
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

		balance(root);
		return root;
	}
	Node* remove(Node*& node, int key) //CALLS THE DELETING NODE FUNCTION
	{
		node = deleteNodeRecursive(node, key);

		return node;
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

		if (root != nullptr)
		{
			checkAVL(root->left);
			cout << getBalanceFactor(root) << " ";
			if (balanceFactor(root) < -1 || balanceFactor(root) > 1)
			{
				check = false;

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

	void checkAVL2()
	{
		int val1, val2;
		cout << "ENTER VALUE 1: ";
		cin >> val1;
		cout << "ENTER VALUE 2: ";
		cin >> val2;

		bool a = searchRecursive(root, val1);
		bool b = searchRecursive(root, val2);

		if (a == 0 || b == 0)
			cout << "BOTH VALUES DOES NOT EXIST IN TREE!";


		else
		{
			bool check = checkAVL(lca(root, val1, val2));

			if (check == false)
			{
				cout << "SUBTREE IS NOT AVL!";
			}

			else
			{
				cout << "TREE IS AVL";
			}
		}
	}

	Node* lca(Node* root, int n1, int n2)
	{
		if (root == NULL)
			return NULL;

		if (root->data > n1 && root->data > n2)
			return lca(root->left, n1, n2);

		if (root->data < n1 && root->data < n2)
			return lca(root->right, n1, n2);

		return root;
	}

	bool checkSubTreeAVL(Node* root, int val1, int val2)
	{
		if (root != nullptr)
		{
			checkSubTreeAVL(root->left, val1, val2);

			if (root->right != nullptr && root->left != nullptr)
			{
				if (root->right->data == val1 && root->left->data == val2)
				{
					return checkAVL(root);
				}

				else if (root->right->data == val2 && root->left->data == val1)
				{
					return checkAVL(root);
				}
			}
			checkSubTreeAVL(root->right, val1, val2);

		}

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
		cout << "(1) INSERT \n(2) DELETE KTH LARGEST VALUE \n(3) TRAVERSE \n(4) DELETE \n(5) EXIT MENU" << endl;

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
			int num;
			cout << "HOW MUCH VALUES DO YOU WANT TO ENTER: ";
			cin >> num;
			
			int* arr = new int[num];

			for (int i = 0; i < num; i++)
			{
				cout << "ENTER VALUE: ";
				cin >> arr[i];
			}

			int k;
			cout << "ENTER THE KTH NUMBER WHICH YOU WANT TO DELETE: ";
			cin >> k;

			if (k > num)
			{
				cout << "INVALID INPUT!";
			}

			else
			{
				for (int i = 0; i < num; i++)
				{
					avl.insert(arr[i]);
				}

				for (int i = 0; i < num; i++)
				{
					for (int j = i + 1; j < num; j++)
					{
						if (arr[i] >= arr[j])
						{
							int temp = arr[i];
							arr[i] = arr[j];
							arr[j] = temp;
						}
					}
				}

				int ksize = num - k;

				avl.deleteNodeRecursive(avl.root, arr[ksize]);

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